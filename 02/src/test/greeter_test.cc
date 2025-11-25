#include <gtest/gtest.h>
#include "greeter.h"

TEST(GreeterTest, ReturnsHello) {
    EXPECT_EQ(simple_app::GetGreet("World"), "Hello World");
}