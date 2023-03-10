#ifndef CYBERTWIN_PACKET_HEADER_H
#define CYBERTWIN_PACKET_HEADER_H

#include "ns3/header.h"
#include "cybertwin-common.h"

namespace ns3
{

class CybertwinPacketHeader : public Header
{
  public:
    CybertwinPacketHeader(uint64_t src = 0, uint64_t dst = 0, uint32_t size = 0, uint16_t cmd = 0);

    void SetSrc(uint64_t src);
    uint64_t GetSrc() const;

    void SetDst(uint64_t dst);
    uint64_t GetDst() const;

    void SetSize(uint32_t size);
    uint32_t GetSize() const;

    void SetCmd(uint16_t cmd);
    uint16_t GetCmd() const;

    static TypeId GetTypeId();
    TypeId GetInstanceTypeId() const override;

    void Print(std::ostream& os) const override;
    uint32_t GetSerializedSize() const override;
    void Serialize(Buffer::Iterator start) const override;
    uint32_t Deserialize(Buffer::Iterator start) override;
    std::string ToString() const;

  private:
    uint64_t m_src;
    uint64_t m_dst;
    uint32_t m_size;
    uint16_t m_cmd;
};

class CybertwinControllerHeader: public Header
{
  public:
    CybertwinControllerHeader();
  
    void SetMethod(uint16_t method);
    uint16_t GetMethod() const;

    // request fragment
    void SetDeviceName(DEVNAME_t devName);
    DEVNAME_t GetDeviceName() const;

    void SetNetworkType(NETTYPE_t netType);
    NETTYPE_t GetNetworkType() const;

    void SetCybertwinID(CYBERTWINID_t cybertwinID);
    CYBERTWINID_t GetCybertwinID() const;

    // response fragment
    //void SetCybertwinAddress(Address addr);
    //Ipv4Address GetCybertwinAddress() const;
    
    void SetCybertwinPort(uint16_t port);
    uint16_t GetCybertwinPort() const;

    static TypeId GetTypeId();
    TypeId GetInstanceTypeId() const override;

    void Print(std::ostream& os) const override;
    uint32_t GetSerializedSize() const override;
    void Serialize(Buffer::Iterator start) const override;
    uint32_t Deserialize(Buffer::Iterator start) override;
    std::string ToString() const;
  private:
    uint16_t method;
    DEVNAME_t devName;
    NETTYPE_t netType;
    CYBERTWINID_t cybertwinID;
    //uint32_t cybertwinAddress; //TODO: support IPv6
    uint16_t cybertwinPort;
};

class CybertwinCNRSHeader: public Header
{
  public:
    CybertwinCNRSHeader();

    static TypeId GetTypeId();
    TypeId GetInstanceTypeId() const override;

    void Print(std::ostream& os) const override;
    uint32_t GetSerializedSize() const override;
    void Serialize(Buffer::Iterator start) const override;
    uint32_t Deserialize(Buffer::Iterator start) override;
    std::string ToString() const;

    void SetMethod(uint16_t method);
    uint16_t GetMethod();

    void SetCybertwinID(CYBERTWINID_t id);
    CYBERTWINID_t GetCybertwinID() const;

    void SetCybertwinAddr(uint32_t addr);
    uint32_t GetCybertwinAddr() const;

    void SetCybertwinPort(uint16_t port);
    uint16_t GetCybertwinPort() const;
  
  private:
    uint16_t method;
    CYBERTWINID_t cybertwinID;
    uint32_t cybertwinAddr;
    uint16_t cybertwinPort;
};

} // namespace ns3

#endif