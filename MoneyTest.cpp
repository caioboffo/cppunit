#include <cppunit/config/SourcePrefix.h>
#include "Money.h"
#include "MoneyTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( MoneyTest );

void MoneyTest::setUp() {}

void MoneyTest::tearDown() {}

void MoneyTest::testConstructor()
{
    const std::string currencyFF( "FF" );
    const double longNumber = 1234.5678;

    Money money( longNumber, currencyFF );

    CPPUNIT_ASSERT_EQUAL( longNumber, money.getAmount() );
    CPPUNIT_ASSERT_EQUAL( currencyFF, money.getCurrency() );

}

void MoneyTest::testEqual()
{
    const Money money123FF( 123, "FF" );
    const Money money123USD( 123, "USD" );
    const Money money12FF( 12, "FF" );
    const Money money12USD( 12, "USD" );

    CPPUNIT_ASSERT( money123FF == money123FF );
    CPPUNIT_ASSERT( money12FF != money123FF );
    CPPUNIT_ASSERT( money123USD != money123FF );
    CPPUNIT_ASSERT( money12USD != money123FF );
}

void MoneyTest::testAdd()
{
    const Money money12FF( 12, "FF" );
    const Money expectedMoney( 135, "FF" );

    Money money( 123, "FF" );
    money += money12FF;

    CPPUNIT_ASSERT_EQUAL( expectedMoney, money );
    CPPUNIT_ASSERT( &money == &(money += money12FF) );
}

void MoneyTest::testAddThrow()
{
    const Money money123FF( 123, "FF" );

    Money money( 123, "USD" );
    CPPUNIT_ASSERT_THROW( money += money123FF, IncompatibleMoneyError );
}
