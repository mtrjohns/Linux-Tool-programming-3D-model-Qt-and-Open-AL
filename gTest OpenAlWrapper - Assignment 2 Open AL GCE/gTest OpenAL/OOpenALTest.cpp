#include <limits.h>
#include "gtest/gtest.h"

#include "AL/al.h"

#include "OOpenALTest.h"
#include "OpenAL.h"

/* Reference: http://www.yolinux.com/TUTORIALS/Cpp-GoogleTest.html */

oOpenALTest::oOpenALTest()
{
    this->odl = NULL;
}

oOpenALTest::~oOpenALTest()
{
    delete this->odl;
    this->odl = NULL;
}

void oOpenALTest::SetUp()
{
    this->odl = new OpenAL(SOURCE_COUNT, BUFFER_COUNT);
}

void oOpenALTest::TearDown()
{
    delete this->odl;
    this->odl = NULL;
}

TEST_F(oOpenALTest,constructor_noArgs)
{
    /*This is a constructor test, don't use the one from the Setup */

    OpenAL *bob = new OpenAL();

    EXPECT_EQ(-1,bob->getMaxSources());
    EXPECT_EQ(-1,bob->getMaxBuffers());

    ALboolean negative = AL_FALSE;
    ALboolean result = bob->init();

    delete bob;

    EXPECT_EQ(negative,result);
}

TEST_F(oOpenALTest,constructor_goodArgs)
{
    /*This is a constructor test, don't use the one from the Setup */

    OpenAL *bob = new OpenAL(BUFFER_COUNT, SOURCE_COUNT);

    int localSc = SOURCE_COUNT;
    int localBc = BUFFER_COUNT;

    EXPECT_EQ(localSc,bob->getMaxSources());
    EXPECT_EQ(localBc,bob->getMaxBuffers());

    ALboolean positive = AL_TRUE;
    ALboolean result = bob->init();

    delete bob;

    EXPECT_EQ(positive,result);
}


TEST_F(oOpenALTest,init)
{
    ALboolean positive = AL_TRUE;
    ALboolean result = odl->init();

    EXPECT_EQ(positive,result);
}
