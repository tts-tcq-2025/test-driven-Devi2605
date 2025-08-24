#include "StringCalculator.hpp"
#include <sstream>

int StringCalculator::Add(const std::string& numbers) {
    if (numbers.empty()) return 0;

    std::stringstream ss(numbers);
    std::string item;
    int sum = 0;
    int count = 0;
    while (std::getline(ss, item, ',')) {
        if (!item.empty()) {
            sum += std::stoi(item);
            count++;
            if (count == 2) break;
        }
    }
    return sum;
}
