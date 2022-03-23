#ifndef OOPENALTEST_H
#define OOPENALTEST_H

#include <limits.h>
#include <gtest/gtest.h>

class OpenAL;

class oOpenALTest : public ::testing::Test
{
protected:
    virtual void SetUp();
    virtual void TearDown();

    //Make sure these are differet, else parameter
    //reversal in the constructor is masked.
    static const int SOURCE_COUNT = 4;
    static const int BUFFER_COUNT = 3;
    OpenAL *odl;

public:
    oOpenALTest();
    virtual ~oOpenALTest();
};

#endif // OOPENALTEST_H
