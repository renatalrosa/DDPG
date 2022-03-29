#ifndef STATS_PACKET_SINK_H
#define STATS_PACKET_SINK_H

#include "ns3/application.h"
#include "ns3/event-id.h"
#include "ns3/ptr.h"
#include "ns3/traced-callback.h"
#include "ns3/address.h"
#include "ns3/stats-data.h"

namespace ns3 {

class Address;
class Socket;
class Packet;


class StatsPacketSink : public Application 
{
public:
  //*** This sholud be added in any other application to use with StatsData ***
  typedef void (* StatsTracedCallback)
    (Ptr<const Packet> packet, uint32_t sinkNodeId, uint32_t sinkAppId, Address sourceAddr);
  //***************************************************************************

  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId (void);
  StatsPacketSink ();

  virtual ~StatsPacketSink ();

  /**
   * \return the total bytes received in this sink app
   */
  uint64_t GetTotalRx () const;

  /**
   * \return pointer to listening socket
   */
  Ptr<Socket> GetListeningSocket (void) const;

  /**
   * \return list of pointers to accepted sockets
   */
  std::list<Ptr<Socket> > GetAcceptedSockets (void) const;
 
protected:
  virtual void DoDispose (void);
private:
  // inherited from Application base class.
  virtual void StartApplication (void);    // Called at time specified by Start
  virtual void StopApplication (void);     // Called at time specified by Stop

  /**
   * \brief Handle a packet received by the application
   * \param socket the receiving socket
   */
  void HandleRead (Ptr<Socket> socket);
  /**
   * \brief Handle an incoming connection
   * \param socket the incoming connection socket
   * \param from the address the connection is from
   */
  void HandleAccept (Ptr<Socket> socket, const Address& from);
  /**
   * \brief Handle an connection close
   * \param socket the connected socket
   */
  void HandlePeerClose (Ptr<Socket> socket);
  /**
   * \brief Handle an connection error
   * \param socket the connected socket
   */
  void HandlePeerError (Ptr<Socket> socket);

  // In the case of TCP, each socket accept returns a new socket, so the 
  // listening socket is stored separately from the accepted sockets
  Ptr<Socket>     m_socket;       //!< Listening socket
  std::list<Ptr<Socket> > m_socketList; //!< the accepted sockets

  Address         m_local;        //!< Local address to bind to
  uint64_t        m_totalRx;      //!< Total bytes received
  uint64_t        m_totalPacketsRx;      //!< Total packets received
  TypeId          m_tid;          //!< Protocol TypeId

  //*** This sholud be added in any other application to use with StatsData ***
  // Traced Callback: received packet, sink node ID in NodeList, sink app index in ApplicationList, soource address.
  TracedCallback<Ptr<const Packet>, uint32_t, uint32_t, Address> m_rxTrace;
  uint32_t m_applicationListIndex;
  //***************************************************************************
};

} // namespace ns3

#endif /* STATS_PACKET_SINK_H */

