#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

class StringCalculator {
public:
    int add(const std::string& input) {
        if (input.empty()) return 0;

        std::string numbers = input;
        std::string delimiter = ",|\n"; // default

        // custom delimiter case
        if (input.rfind("//", 0) == 0) {
            auto pos = input.find('\n');
            delimiter = input.substr(2, pos - 2);
            numbers = input.substr(pos + 1);
        }

        std::vector<std::string> tokens = split(numbers, delimiter);
        std::vector<int> values = toInts(tokens);
        return sum(values);
    }

private:
    std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
        std::vector<std::string> tokens;
        size_t start = 0, end;

        while ((end = str.find_first_of(delimiter, start)) != std::string::npos) {
            if (end > start) tokens.push_back(str.substr(start, end - start));
            start = end + 1;
        }
        if (start < str.size()) tokens.push_back(str.substr(start));

        return tokens;
    }

    std::vector<int> toInts(const std::vector<std::string>& tokens) {
        std::vector<int> values;
        std::vector<int> negatives;

        for (auto& t : tokens) {
            int n = std::stoi(t);
            if (n < 0) negatives.push_back(n);
            else if (n <= 1000) values.push_back(n);
        }

        if (!negatives.empty()) {
            std::ostringstream oss;
            oss << "negatives not allowed: ";
            for (size_t i = 0; i < negatives.size(); i++) {
                if (i > 0) oss << ", ";
                oss << negatives[i];
            }
            throw std::runtime_error(oss.str());
        }

        return values;
    }

    int sum(const std::vector<int>& values) {
        int total = 0;
        for (int v : values) total += v;
        return total;
    }
};

int main() {
    StringCalculator calc;

    std::cout << "Empty: " << calc.add("") << "\n";                // 0
    std::cout << "\"1\": " << calc.add("1") << "\n";              // 1
    std::cout << "\"1,2\": " << calc.add("1,2") << "\n";          // 3
    std::cout << "\"1\\n2,3\": " << calc.add("1\n2,3") << "\n";   // 6
    std::cout << "\"//;\\n1;2\": " << calc.add("//;\n1;2") << "\n"; // 3
    std::cout << "\"2,1001\": " << calc.add("2,1001") << "\n";    // 2

    try {
        calc.add("1,-2,3");
    } catch (const std::exception& ex) {
        std::cout << "Exception: " << ex.what() << "\n";
    }

    return 0;
}

