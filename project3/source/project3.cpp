#include <iostream>
#include <sstream> // Needed for std::stringstream
#include "kSmall.cpp"
#include "debug.h"

bool RunTest(int k, int expected, std::vector<int>& input) {
    bool passed = true;
    std::stringstream msg;
    msg << k << "-th smallest of input {";
    for (size_t i = 0; i < input.size(); i++) {
        msg << input.at(i) << ", ";
    }
    msg << "}" << std::endl;

    int actual = kSmall(k, input);
    ASSERT_EQUAL(msg.str(), actual, expected)
    return passed;
}

bool Test1() {
    return true;
    std::vector<int> input = {4, 5, 2, 3, 1};
    int k = 3;
    int expected = 3;
    return RunTest(k, expected, input);
}

bool Test2() {
    int size = 42;
    std::vector<int> input;
    input.resize(size);
    for (int i = 0; i < size; i++) {
        input[i] = i;
    }
    for (int j = 0; j < size; j++) {
        int rand = (j * 23 + 7) % (size - j);
        std::swap(input[j], input[rand]);
    }
    // std::vector<int> input = {4, 5, 2, 3, 1};
    int k = 3;
    int expected = 3;
    return RunTest(k, expected, input);
}

bool RunTests() {
    bool passed = Test1() && Test2();
    if (passed) {
        std::cout << "================ TESTS PASSED ================" << std::endl;
    }
    else {
        std::cerr << "================ TESTS FAILED ================" << std::endl;
    }
    return passed;
}

std::vector<int> GetArray() {
    return std::vector<int>({4, 5, 2, 3, 1});
    // return std::vector<int>({4, 7, 3, 6, 8, 1, 9, 2});
}

int main() {
    if (!RunTests())
    {
        return 1;
    }
    // std::vector<int> inputArray = GetArray();
    // int k = 3; // Example: Find the 3rd smallest element
    // int result = kSmall(k, inputArray, 0, inputArray.size() - 1);
    // std::cout << "The " << k << "-th smallest element is: " << result << std::endl;
    // std::cout << "-----------------------------\n" << std::endl;

    // for (int k = 1; k <= inputArray.size(); k++) {
    //     int result = kSmall(k, inputArray, 0, inputArray.size() - 1);
    //     std::cout << "The " << k << "-th smallest element is: " << result << std::endl;
    //     std::cout << "-----------------------------\n" << std::endl;
    //     std::vector<int> inputArray = GetArray();
    // }

    return 0;
}