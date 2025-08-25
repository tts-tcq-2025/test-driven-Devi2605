#include "StringCalculator.h"
#include <numeric>
#include <algorithm>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) return 0;

    auto [customDelimiter, numberString] = extractCustomDelimiter(numbers);

    // Build delimiter list
    std::vector<std::string> delimiters = {",", "\n"};
    if (!customDelimiter.empty()) delimiters.push_back(customDelimiter);

    // Parse and normalize
    auto tokens = tokenize(normalizeDelimiters(numberString, delimiters));
    auto parsedNumbers = toNumbers(tokens);

    validateNoNegatives(parsedNumbers);

    auto filtered = filterLargeNumbers(parsedNumbers);
    return sumNumbers(filtered);
}

// ------------------- Helpers -------------------

std::vector<std::string> StringCalculator::tokenize(const std::string& normalized) {
    std::vector<std::string> tokens;
    std::stringstream ss(normalized);
    std::string token;
    while (std::getline(ss, token, ',')) {
        if (!token.empty()) tokens.push_back(token);
    }
    return tokens;
}

std::vector<int> StringCalculator::toNumbers(const std::vector<std::string>& tokens) {
    std::vector<int> numbers;
    numbers.reserve(tokens.size());
    std::transform(tokens.begin(), tokens.end(), std::back_inserter(numbers),
                   [](const std::string& s) { return std::stoi(s); });
    return numbers;
}

int StringCalculator::sumNumbers(const std::vector<int>& numbers) {
    return std::accumulate(numbers.begin(), numbers.end(), 0);
}
