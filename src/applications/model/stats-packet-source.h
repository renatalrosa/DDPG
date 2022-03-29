#ifndef STATS_PACKET_SOURCE_H
#define STATS_PACKET_SOURCE_H

#include "ns3/address.h"
#include "ns3/application.h"
#include "ns3/event-id.h"
#include "ns3/ptr.h"
#include "ns3/data-rate.h"
#include "ns3/traced-callback.h"
#include <string>

namespace ns3 {

class Address;
class RandomVariableStream;
class Socket;

class StatsPacketSource : public Application 
{
public:
  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId (void);

  StatsPacketSource ();

  virtual ~StatsPacketSource();

  void SetMaxBytes (uint64_t maxBytes);

  Ptr<Socket> GetSocket (void) const;

  int64_t AssignStreams (int64_t stream);

protected:
  virtual void DoDispose (void);
private:
  virtual void StartApplication (void);    // Called at time specified by Start
  virtual void StopApplication (void);     // Called at time specified by Stop

  //helpers
  /**
   * \brief Cancel all pending events.
   */
  void CancelEvents ();

  // Event handlers
  /**
   * \brief Start an On period
   */
  void StartSending ();
  /**
   * \brief Start an Off period
   */
  void StopSending ();
  /**
   * \brief Send a packet
   */
  void SendPacket ();

  Ptr<Socket>     m_socket;       //!< Associated socket
  Address         m_peer;         //!< Peer address
  bool            m_connected;    //!< True if connected
  Ptr<RandomVariableStream>  m_onTime;       //!< rng for On Time
  Ptr<RandomVariableStream>  m_offTime;      //!< rng for Off Time
  DataRate        m_cbrRate;      //!< Rate that data is generated
  DataRate        m_cbrRateFailSafe;      //!< Rate that data is generated (check copy)
  uint32_t        m_pktSize;      //!< Size of packets
  uint32_t        m_residualBits; //!< Number of generated, but not sent, bits
  Time            m_lastStartTime; //!< Time last packet sent
  uint64_t        m_maxBytes;     //!< Limit total number of bytes sent
  uint64_t        m_totBytes;     //!< Total bytes sent so far
  EventId         m_startStopEvent;     //!< Event id for next start or stop event
  EventId         m_sendEvent;    //!< Event id of pending "send packet" event
  TypeId          m_tid;          //!< Type of the socket used
  uint32_t        m_sent;         //!< Counter for sent packets

private:
  /**
   * \brief Schedule the next packet transmission
   */
  void ScheduleNextTx ();
  /**
   * \brief Schedule the next On period start
   */
  void ScheduleStartEvent ();
  /**
   * \brief Schedule the next Off period start
   */
  void ScheduleStopEvent ();
  /**
   * \brief Handle a Connection Succeed event
   * \param socket the connected socket
   */
  void ConnectionSucceeded (Ptr<Socket> socket);
  /**
   * \brief Handle a Connection Failed event
   * \param socket the not connected socket
   */
  void ConnectionFailed (Ptr<Socket> socket);

  TracedCallback<Ptr<const Packet> > m_txTrace;
  uint32_t m_applicationListIndex;

};

} // namespace ns3

#endif /* STATS_PACKET_SOURCE_H */
