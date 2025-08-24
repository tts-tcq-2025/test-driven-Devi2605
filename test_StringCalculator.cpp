#include "StringCalculator.h"
#include <string>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;   // ✅ minimum code to pass first test
    }
    return std::stoi(numbers);  // temporary stub for next test
}
