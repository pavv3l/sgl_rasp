#include <mock_sgl.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using testing::AtLeast;

TEST(MockSGL, 1)
{
    MockSGL tst(240, 320);
    EXPECT_CALL(tst, drawPixel(10,10,1,SGL::Mode::px_copy)).Times(AtLeast(1));
    tst.drawRectangle(10, 10, 15, 15, 1, SGL::Fill::hole, SGL::Mode::px_copy);

}

TestSGL tstsgl(240, 320);
TEST(constructor, width)
{
    EXPECT_EQ(240, tstsgl.get_width());
}
TEST(constructor, height)
{
    EXPECT_EQ(320, tstsgl.get_height());
}