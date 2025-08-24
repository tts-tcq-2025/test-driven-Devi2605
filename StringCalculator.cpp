#include "StringCalculator.h"

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }
    return std::stoi(numbers); // stub: works only for "1"
}
