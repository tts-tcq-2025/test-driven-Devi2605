#include "gtest/gtest.h"
#include "StringCalculator.hpp"

TEST(StringCalculatorTest, empty_string_should_return_Zero) {
    StringCalculator calc;
    EXPECT_EQ(calc.Add(""), 0);
}
