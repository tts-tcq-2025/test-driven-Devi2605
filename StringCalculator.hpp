// #ifndef STRING_CALCULATOR_H
// #define STRING_CALCULATOR_H

// #include <string>

// class StringCalculator {
// public:
//     int Add(const std::string& input);
// };

// #endif

#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>

class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    // Parsing helpers
    std::pair<std::string, std::string> extractCustomDelimiter(const std::string& input);
    std::string extractDelimiterFromLine(const std::string& line);
    std::string normalizeDelimiters(const std::string& numbers, const std::vector<std::string>& delimiters);
    std::string replaceDelimiter(const std::string& text, const std::string& delimiter);

    // Validation helpers
    void validateNoNegatives(const std::vector<int>& numbers);
    std::vector<int> findNegativeNumbers(const std::vector<int>& numbers);
    void raiseNegativeError(const std::vector<int>& negatives);

    // Filtering
    std::vector<int> filterLargeNumbers(const std::vector<int>& numbers, int maxValue = 1000);
};

