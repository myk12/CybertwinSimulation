#include "cybertwin-packet-header.h"

#include "ns3/log.h"

namespace ns3
{
NS_LOG_COMPONENT_DEFINE("CybertwinPacketHeader");
NS_OBJECT_ENSURE_REGISTERED(CybertwinPacketHeader);

CybertwinPacketHeader::CybertwinPacketHeader(uint64_t src,
                                             uint64_t dst,
                                             uint32_t size,
                                             uint16_t cmd)
    : m_src(src),
      m_dst(dst),
      m_size(size),
      m_cmd(cmd)
{
}

TypeId
CybertwinPacketHeader::GetTypeId()
{
    static TypeId tid = TypeId("ns3::CybertwinPacketHeader")
                            .SetParent<Header>()
                            .SetGroupName("cybertwin")
                            .AddConstructor<CybertwinPacketHeader>();
    return tid;
}

TypeId
CybertwinPacketHeader::GetInstanceTypeId() const
{
    return GetTypeId();
}

uint64_t
CybertwinPacketHeader::GetSrc() const
{
    return m_src;
}

void
CybertwinPacketHeader::SetSrc(uint64_t src)
{
    m_src = src;
}

uint64_t
CybertwinPacketHeader::GetDst() const
{
    return m_dst;
}

void
CybertwinPacketHeader::SetDst(uint64_t dst)
{
    m_dst = dst;
}

uint32_t
CybertwinPacketHeader::GetSize() const
{
    return m_size;
}

void
CybertwinPacketHeader::SetSize(uint32_t size)
{
    m_size = size;
}

uint16_t
CybertwinPacketHeader::GetCmd() const
{
    return m_cmd;
}

void
CybertwinPacketHeader::SetCmd(uint16_t cmd)
{
    m_cmd = cmd;
}

void
CybertwinPacketHeader::Print(std::ostream& os) const
{
    os << "(src=" << m_src << " dst=" << m_dst << " size=" << m_size << " cmd=" << m_cmd << ")";
}

std::string
CybertwinPacketHeader::ToString() const
{
    std::ostringstream oss;
    Print(oss);
    return oss.str();
}

uint32_t
CybertwinPacketHeader::GetSerializedSize() const
{
    return 8 + 8 + 4 + 2;
}

void
CybertwinPacketHeader::Serialize(Buffer::Iterator start) const
{
    Buffer::Iterator i = start;
    i.WriteHtonU64(m_src);
    i.WriteHtonU64(m_dst);
    i.WriteHtonU32(m_size);
    i.WriteHtonU16(m_cmd);
}

uint32_t
CybertwinPacketHeader::Deserialize(Buffer::Iterator start)
{
    Buffer::Iterator i = start;
    m_src = i.ReadNtohU64();
    m_dst = i.ReadNtohU64();
    m_size = i.ReadNtohU32();
    m_cmd = i.ReadNtohU16();
    return GetSerializedSize();
}

//********************************************************************
//*              Cybertwin Controller Header                         *
//********************************************************************

CybertwinControllerHeader::CybertwinControllerHeader():
    method(NOTHING)
{
}

TypeId
CybertwinControllerHeader::GetTypeId()
{
    static TypeId tid = TypeId("ns3::CybertwinControllerHeader")
                            .SetParent<Header>()
                            .SetGroupName("cybertwin")
                            .AddConstructor<CybertwinControllerHeader>();
    return tid;
}

TypeId
CybertwinControllerHeader::GetInstanceTypeId() const
{
    return GetTypeId();
}

void
CybertwinControllerHeader::Print(std::ostream& os) const
{
    os << "(method=" << method << ")";
}

uint32_t
CybertwinControllerHeader::GetSerializedSize() const
{
    return sizeof(method);
}

void
CybertwinControllerHeader::Serialize(Buffer::Iterator start) const
{
    Buffer::Iterator i = start;
    i.WriteHtonU16(method);
}

void CybertwinControllerHeader::SetMethod(uint16_t method)
{
    this->method = method;
}

uint32_t
CybertwinControllerHeader::Deserialize(Buffer::Iterator start)
{
    Buffer::Iterator i = start;
    method = i.ReadNtohU16();
    return GetSerializedSize();
}

std::string
CybertwinControllerHeader::ToString() const
{
    std::ostringstream oss;
    Print(oss);
    return oss.str();
}

uint16_t CybertwinControllerHeader::GetMethod() const
{
    return method;
}

} // namespace ns3