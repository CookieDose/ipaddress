#include <gtest/gtest.h>
#include "Include.h"
TEST(IPAddressV4Test, parse)
{
	ip_address::IPAddressV4 ip1("172.217.21.142");
	/* parse and string representation */
	EXPECT_EQ(ip1.getString(), "172.217.21.142");
	/* IPv4 to IPv6 mapping */
	EXPECT_TRUE(ip1.toIPv6().isIPv4Mapped());
}
TEST(IPAddressV4Test, Loopback)
{
	/* Loopback */
	ip_address::IPAddressV4 ip5("127.0.0.1");
	EXPECT_EQ(ip_address::IPAddressV4::loopback(), ip5);
	EXPECT_TRUE(ip5 == ip_address::IPAddressV4::loopback());
}

TEST(IPAddressV4Test, Any)
{
	/* Any */
	ip_address::IPAddressV4 ip6("0.0.0.0");
	EXPECT_TRUE(ip6.isAny());
	auto aip6 = ip_address::IPAddressV4::any();
	EXPECT_TRUE(aip6.isAny());
	EXPECT_TRUE(ip6.getString() == "0.0.0.0");
}

TEST(IPAddressV6Test, parse)
{

}

TEST(IPAddressV6Test, Loopback)
{
	/* Loopback */
	ip_address::IPAddressV6 ip1("::1");
	EXPECT_EQ(ip1, ip_address::IPAddressV6::loopback());
	EXPECT_TRUE(ip1.isLoopback());
}

TEST(IPAddressV6Test, Operator)
{
	/* Opeator */
	ip_address::IPAddressV6 ip1("::1");
	ip_address::IPAddressV6 ip2("::1");
	EXPECT_TRUE(ip1 == ip2);
	EXPECT_FALSE(ip1 != ip2);
}