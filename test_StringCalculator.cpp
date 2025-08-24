#include <cassert>
#include "../src/StringCalculator.h"

int main() {
    StringCalculator calc;

    // Smallest failing test
    assert(calc.add("") == 0);

    return 0;
}
