#include <iostream>
#include <sstream> // Needed for std::stringstream
#include "kSmall.cpp"
#include "debug.h"

bool TestPartition() {
    bool passed = true;
    std::vector<int> input = {4, 10, 5, 1, 3, 6, 2, 9, 8, 7};
    int first = 0;
    int last = input.size() - 1;
    int expectedPivotIndex = input.at(first) - 1; // Assuming the first element (4) is the pivot
    int actualPivotIndex = partition(input, first, last);
    ASSERT_EQUAL("Partition Test of " + VectorToString(input), actualPivotIndex, expectedPivotIndex)
    return passed;
}

bool RunTest(int k, int expected, std::vector<int>& input) {
    bool passed = true;
    std::stringstream msg;
    msg << k << "-th smallest of input " << VectorToString(input);
    int actual = kSmall(k, input);
    ASSERT_EQUAL(msg.str(), actual, expected)
    return passed;
}

bool StaticTest() {
    std::vector<int> input = {4, 5, 2, 3, 1};
    int k = 3;
    int expected = 3;
    return RunTest(k, expected, input);
}

bool RunRandomTests() {
    int seed = 0;
    int failedCount = 0;
    for (int i = 0; i < 5; i++) {
        int size = GetRandomNumber(seed, 20) + 5; // Size between 5 and 24
        int k = GetRandomNumber(seed, size) + 1; // k between 1 and size
        std::vector<int> input = GenerateRandomVector(size, seed);
        if (!RunTest(k, k, input)) {
            failedCount++;
        }
    }

    if (failedCount > 0) {
        std::cerr << "Failed " << failedCount << " out of 5 random tests." << std::endl;
    }
    return failedCount == 0;
}

bool RunTests() {
    bool passed = true;
    passed &= TestPartition();
    passed &= StaticTest();
    passed &= RunRandomTests();

    if (passed) {
        std::cout << "================ TESTS PASSED ================" << std::endl;
    }
    else {
        std::cerr << "================ TESTS FAILED ================" << std::endl;
    }
    return passed;
}

int main() {
    if (!RunTests()) {
        return 1;
    }

    return 0;
}