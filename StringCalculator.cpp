#include "StringCalculator.h"

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) return 0;

    // Step 1: Extract custom delimiter if present
    auto [customDelimiter, numberString] = extractCustomDelimiter(numbers);

    // Step 2: Build list of delimiters
    std::vector<std::string> delimiters = {",", "\n"};
    if (!customDelimiter.empty()) {
        delimiters.push_back(customDelimiter);
    }

    // Step 3: Normalize delimiters to commas
    std::string normalized = normalizeDelimiters(numberString, delimiters);

    // Step 4: Split and convert
    std::vector<int> parsedNumbers;
    std::stringstream ss(normalized);
    std::string token;

    while (std::getline(ss, token, ',')) {
        if (!token.empty()) {
            parsedNumbers.push_back(std::stoi(token));
        }
    }

    // Step 5: Validate negatives
    validateNoNegatives(parsedNumbers);

    // Step 6: Filter > 1000
    parsedNumbers = filterLargeNumbers(parsedNumbers);

    // Step 7: Sum
    int sum = 0;
    for (int n : parsedNumbers) {
        sum += n;
    }
    return sum;
}

std::pair<std::string, std::string> StringCalculator::extractCustomDelimiter(const std::string& input) {
    if (input.rfind("//", 0) != 0) {
        return {"", input}; // no custom delimiter
    }

    auto newlinePos = input.find("\n");
    if (newlinePos == std::string::npos) {
        return {"", input}; // invalid format
    }

    std::string delimiterLine = input.substr(2, newlinePos - 2);
    std::string numberString = input.substr(newlinePos + 1);

    std::string delimiter = extractDelimiterFromLine(delimiterLine);
    return {delimiter, numberString};
}

std::string StringCalculator::extractDelimiterFromLine(const std::string& line) {
    if (line.size() >= 2 && line.front() == '[' && line.back() == ']') {
        return line.substr(1, line.size() - 2);
    }
    return line;
}

std::string StringCalculator::normalizeDelimiters(const std::string& numbers, const std::vector<std::string>& delimiters) {
    std::string normalized = numbers;
    for (const auto& d : delimiters) {
        normalized = replaceDelimiter(normalized, d);
    }
    return normalized;
}

std::string StringCalculator::replaceDelimiter(const std::string& text, const std::string& delimiter) {
    if (delimiter == ",") return text; // don’t replace commas

    std::string result = text;
    size_t pos = 0;
    while ((pos = result.find(delimiter, pos)) != std::string::npos) {
        result.replace(pos, delimiter.size(), ",");
        pos += 1;
    }
    return result;
}

void StringCalculator::validateNoNegatives(const std::vector<int>& numbers) {
    auto negatives = findNegativeNumbers(numbers);
    if (!negatives.empty()) {
        raiseNegativeError(negatives);
    }
}

std::vector<int> StringCalculator::findNegativeNumbers(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    for (int n : numbers) {
        if (n < 0) negatives.push_back(n);
    }
    return negatives;
}

void StringCalculator::raiseNegativeError(const std::vector<int>& negatives) {
    std::ostringstream oss;
    oss << "negatives not allowed: ";
    for (size_t i = 0; i < negatives.size(); i++) {
        oss << negatives[i];
        if (i < negatives.size() - 1) oss << ", ";
    }
    throw std::invalid_argument(oss.str());
}

std::vector<int> StringCalculator::filterLargeNumbers(const std::vector<int>& numbers, int maxValue) {
    std::vector<int> filtered;
    for (int n : numbers) {
        if (n <= maxValue) filtered.push_back(n);
    }
    return filtered;
}
