// #include "gtest/gtest.h"
// #include "StringCalculator.hpp"

// TEST(StringCalculatorTest, empty_string_should_return_Zero) {
//     StringCalculator calc;
//     EXPECT_EQ(calc.Add(""), 0);
// }

#include <gtest/gtest.h>
#include "StringCalculator.h"

class StringCalculatorTest : public ::testing::Test {
protected:
    StringCalculator calc;
};

TEST_F(StringCalculatorTest, EmptyStringReturnsZero) {
    EXPECT_EQ(calc.add(""), 0);
}

TEST_F(StringCalculatorTest, SingleNumberReturnsValue) {
    EXPECT_EQ(calc.add("5"), 5);
}

TEST_F(StringCalculatorTest, TwoNumbersCommaSeparated) {
    EXPECT_EQ(calc.add("1,2"), 3);
}

TEST_F(StringCalculatorTest, UnknownAmountOfNumbers) {
    EXPECT_EQ(calc.add("1,2,3,4,5"), 15);
}

TEST_F(StringCalculatorTest, HandlesNewlineDelimiter) {
    EXPECT_EQ(calc.add("1\n2,3"), 6);
}

TEST_F(StringCalculatorTest, CustomDelimiter) {
    EXPECT_EQ(calc.add("//;\n1;2"), 3);
}

TEST_F(StringCalculatorTest, CustomDelimiterOfAnyLength) {
    EXPECT_EQ(calc.add("//[***]\n1***2***3"), 6);
}

TEST_F(StringCalculatorTest, IgnoresNumbersGreaterThan1000) {
    EXPECT_EQ(calc.add("2,1001,6"), 8);
}

TEST_F(StringCalculatorTest, ThrowsOnNegativeNumbers) {
    try {
        calc.add("1,-2,3,-4");
        FAIL() << "Expected invalid_argument";
    } catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "negatives not allowed: -2, -4");
    }
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

