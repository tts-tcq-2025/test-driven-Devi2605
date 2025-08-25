This project implements the String Calculator Kata in C++ using the principles of Test Driven Development (TDD).


REQ_IMP:

--Empty string returns 0
--A single number returns its value
--Two numbers (comma separated) return their sum
--Handles an unknown amount of numbers
--Supports newlines (\n) as delimiters
--Allows custom delimiters in the form:
//;\n1;2 → 3
//[***]\n1***2***3 → 6 (delimiter of any length)
 --Negative numbers throw an exception with message listing all negatives
         Example: 1,-2,3,-4 → "negatives not allowed: -2, -4"
         
 --Numbers greater than 1000 are ignored
        Example: "2,1001,6" → 8



FILE STRUCTURE:

├── CMakeLists.txt             # Build configuration
├── README.md                  # Documentation
├── StringCalculator.h         # Class interface
├── StringCalculator.cpp       # Implementation
└── test_string_calculator.cpp # GoogleTest unit tests
