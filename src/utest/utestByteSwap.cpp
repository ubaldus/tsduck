//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2023, Thierry Lelegard
// BSD-2-Clause license, see LICENSE.txt file or https://tsduck.io/license
//
//----------------------------------------------------------------------------
//
//  TSUnit test suite for ByteSwap.h
//
//----------------------------------------------------------------------------

#include "tsByteSwap.h"
#include "tsunit.h"


//----------------------------------------------------------------------------
// The test fixture
//----------------------------------------------------------------------------

class ByteSwapTest: public tsunit::Test
{
public:
    virtual void beforeTest() override;
    virtual void afterTest() override;

    void testSignExtend24();
    void testSignExtend40();
    void testSignExtend48();
    void testByteSwap16();
    void testByteSwap24();
    void testByteSwap32();
    void testByteSwap64();
    void testCondByteSwap16BE();
    void testCondByteSwap16LE();
    void testCondByteSwap32BE();
    void testCondByteSwap32LE();
    void testCondByteSwap64BE();
    void testCondByteSwap64LE();

    TSUNIT_TEST_BEGIN(ByteSwapTest);
    TSUNIT_TEST(testSignExtend24);
    TSUNIT_TEST(testSignExtend40);
    TSUNIT_TEST(testSignExtend48);
    TSUNIT_TEST(testByteSwap16);
    TSUNIT_TEST(testByteSwap24);
    TSUNIT_TEST(testByteSwap32);
    TSUNIT_TEST(testByteSwap64);
    TSUNIT_TEST(testCondByteSwap16BE);
    TSUNIT_TEST(testCondByteSwap16LE);
    TSUNIT_TEST(testCondByteSwap32BE);
    TSUNIT_TEST(testCondByteSwap32LE);
    TSUNIT_TEST(testCondByteSwap64BE);
    TSUNIT_TEST(testCondByteSwap64LE);
    TSUNIT_TEST_END();
};

TSUNIT_REGISTER(ByteSwapTest);


//----------------------------------------------------------------------------
// Initialization.
//----------------------------------------------------------------------------

// Test suite initialization method.
void ByteSwapTest::beforeTest()
{
}

// Test suite cleanup method.
void ByteSwapTest::afterTest()
{
}


//----------------------------------------------------------------------------
// Unitary tests.
//----------------------------------------------------------------------------

void ByteSwapTest::testSignExtend24()
{
    TSUNIT_EQUAL(0x00723456, ts::SignExtend24(0xAA723456));
    TSUNIT_EQUAL(0xFF923456, ts::SignExtend24(0xAA923456));
}

void ByteSwapTest::testSignExtend40()
{
    TSUNIT_EQUAL(0x000000723456789A, ts::SignExtend40(0xAAAAAA723456789A));
    TSUNIT_EQUAL(0xFFFFFFA23456789A, ts::SignExtend40(0xAAAAAAA23456789A));
}

void ByteSwapTest::testSignExtend48()
{
    TSUNIT_EQUAL(0x0000723456789ABC, ts::SignExtend48(0xAAAA723456789ABC));
    TSUNIT_EQUAL(0xFFFFA23456789ABC, ts::SignExtend48(0xAAAAA23456789ABC));
}

void ByteSwapTest::testByteSwap16()
{
    TSUNIT_EQUAL(0x3412, ts::ByteSwap16(0x1234));
}

void ByteSwapTest::testByteSwap24()
{
    TSUNIT_EQUAL(0x563412, ts::ByteSwap24(0x123456));
    TSUNIT_EQUAL(0xEFCDAB, ts::ByteSwap24(0xABCDEF));
}

void ByteSwapTest::testByteSwap32()
{
    TSUNIT_EQUAL(0x78563412, ts::ByteSwap32(0x12345678));
}

void ByteSwapTest::testByteSwap64()
{
    TSUNIT_EQUAL(0xEFCDAB8967452301, ts::ByteSwap64(0x0123456789ABCDEF));
}

void ByteSwapTest::testCondByteSwap16BE()
{
#if defined(TS_LITTLE_ENDIAN)
    TSUNIT_EQUAL(0x3412, ts::CondByteSwap16BE(0x1234));
#else
    TSUNIT_EQUAL(0x1234, ts::CondByteSwap16BE(0x1234));
#endif
}

void ByteSwapTest::testCondByteSwap16LE()
{
#if defined(TS_LITTLE_ENDIAN)
    TSUNIT_EQUAL(0x1234, ts::CondByteSwap16LE(0x1234));
#else
    TSUNIT_EQUAL(0x3412, ts::CondByteSwap16LE(0x1234));
#endif
}

void ByteSwapTest::testCondByteSwap32BE()
{
#if defined(TS_LITTLE_ENDIAN)
    TSUNIT_EQUAL(0x78563412, ts::CondByteSwap32BE(0x12345678));
#else
    TSUNIT_EQUAL(0x12345678, ts::CondByteSwap32BE(0x12345678));
#endif
}

void ByteSwapTest::testCondByteSwap32LE()
{
#if defined(TS_LITTLE_ENDIAN)
    TSUNIT_EQUAL(0x12345678, ts::CondByteSwap32LE(0x12345678));
#else
    TSUNIT_EQUAL(0x78563412, ts::CondByteSwap32LE(0x12345678));
#endif
}

void ByteSwapTest::testCondByteSwap64BE()
{
#if defined(TS_LITTLE_ENDIAN)
    TSUNIT_EQUAL(0xEFCDAB8967452301, ts::CondByteSwap64BE(0x0123456789ABCDEF));
#else
    TSUNIT_EQUAL(0x0123456789ABCDEF, ts::CondByteSwap64BE(0x0123456789ABCDEF));
#endif
}

void ByteSwapTest::testCondByteSwap64LE()
{
#if defined(TS_LITTLE_ENDIAN)
    TSUNIT_EQUAL(0x0123456789ABCDEF, ts::CondByteSwap64LE(0x0123456789ABCDEF));
#else
    TSUNIT_EQUAL(0xEFCDAB8967452301, ts::CondByteSwap64LE(0x0123456789ABCDEF));
#endif
}
