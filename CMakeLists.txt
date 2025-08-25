cmake_minimum_required(VERSION 3.14)
project(StringCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- GoogleTest setup ---
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding parent compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# --- Library sources ---
add_library(String_Calculator
    src/StringCalculator.cpp
    src/StringCalculator.h
)

target_include_directories(string_calculator PUBLIC src)

# --- Test sources ---
add_executable(test_String_Calculator
    tests/test_String_Calculator.cpp
)

target_link_libraries(
    test_String_Calculator
    PRIVATE string_calculator
    PRIVATE GTest::gtest_main
)

# --- Test discovery ---
include(GoogleTest)
gtest_discover_tests(test_String_Calculator)

