#ifndef STATS_HEADER_H
#define STATS_HEADER_H

#include "ns3/header.h"
#include "ns3/nstime.h"
#include "ns3/address.h"

namespace ns3 {

class StatsHeader : public Header
{
public:
  StatsHeader ();

  /**
   * \param seq the sequence number
   */
  void SetSeq (uint32_t seq);
  /**
   * \return the sequence number
   */
  uint32_t GetSeq (void) const;
  /**
   * \return the time stamp
   */
  Time GetTs (void) const;

  /**
   * \param nodeId the sender's node ID
   */
  void SetNodeId (uint32_t nodeId);
  /**
   * \return the sender's node ID
   */
  uint32_t GetNodeId (void) const;
  
  /**
   * \param appId the sender's application ID
   */
  void SetApplicationId (uint32_t appId);
  /**
   * \return the sender's application ID
   */
  uint32_t GetApplicationId (void) const;

  void SetRxAddress (const Address &addr);

  Address GetRxAddress (void) const
    {
      return m_rxAddress;
    };

  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId (void);

  std::string ToString () const;

  virtual TypeId GetInstanceTypeId (void) const;
  virtual void Print (std::ostream &os) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);

private:
  uint32_t m_seq; //!< Sequence number
  uint64_t m_ts; //!< Time stamp
  uint32_t m_nodeId; //!< Sender Node Id
  uint32_t m_appId; //!< Sender Application Id
  Address m_rxAddress; //!< Receiver IP address (IPv4 or IPv6) and port (InetSocketAddress or Inet6SocketAddress)
};

} // namespace ns3

#endif /* STATS_HEADER_H */
