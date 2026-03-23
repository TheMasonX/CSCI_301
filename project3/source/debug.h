/**
 * @file debug.h
 * @brief Contains unit test macros and utility functions for debugging.
 *
 * Name: Luke Norr
 * StarID: lx8454qp
 * Instructor: Jie Meichsner
 */
#ifndef DEBUG_H_
#define DEBUG_H_

#include <iostream>
#include <sstream> // Required for istringstream

#define SEPARATOR "\n=================================================\n"

/**
 * Macro to print the result of a test case, including the actual and expected values.
 * @param msg The message describing the test case.
 * @param actual The actual value obtained from the test.
 * @param expected The expected value for the test case.
 * @return A formatted string containing the test case message, actual value, and expected value.
*/
#define PRINT_RES(msg, actual, expected) msg << " returned: " << actual << ". Expected: " << expected << std::endl;

/**
 * Macro to assert a condition and print the result of the test case. If the condition is true, it prints a pass message; otherwise, it prints a fail message.
 * @param condition The condition to be evaluated for the test case.
 * @param msg The message describing the test case.
 * @param actual The actual value obtained from the test.
 * @param expected The expected value for the test case.
 */
#define PRINT_PASS(msg, actual, expected) std::cout << "PASS: " << PRINT_RES(msg, actual, expected)

/**
 * Macro to assert a condition and print the result of the test case. If the condition is true, it prints a pass message; otherwise, it prints a fail message and sets the passed variable to false.
 * @param condition The condition to be evaluated for the test case.
 * @param msg The message describing the test case.
 * @param actual The actual value obtained from the test.
 * @param expected The expected value for the test case.
 */
#define PRINT_FAIL(msg, actual, expected) std::cerr << "FAIL: " << PRINT_RES(msg, actual, expected)

/**
 * Macro to assert a condition and print the result of the test case. If the condition is true, it prints a pass message;
 * otherwise, it prints a fail message and sets the passed variable to false.
 * @param condition The condition to be evaluated for the test case.
 * @param msg The message describing the test case.
 * @param actual The actual value obtained from the test.
 * @param expected The expected value for the test case.
 */
#define ASSERT(condition, msg, actual, expected) if (condition) { PRINT_PASS(msg, actual, expected) } \
                                                 else { passed = false; PRINT_FAIL(msg, actual, expected) }

/**
 * Macro to assert that the actual value is equal to the expected value. It uses the ASSERT macro to evaluate the condition and print the result of the test case.
 * @param msg The message describing the test case.
 * @param actual The actual value obtained from the test.
 * @param expected The expected value for the test case.
 */
#define ASSERT_EQUAL(msg, actual, expected) ASSERT(actual == expected, msg, actual, expected)

/**
 * Macro to assert that the actual value is not equal to the expected value. It uses the ASSERT macro to evaluate the condition and print the result of the test case.
 * @param msg The message describing the test case.
 * @param actual The actual value obtained from the test.
 * @param expected The expected value for the test case.
 */
#define ASSERT_NOT_EQUAL(msg, actual, expected) ASSERT(!(actual == expected), msg, actual, expected)

/**
 * Macro to assert that the actual value is less than the expected value. It uses the ASSERT macro to evaluate the condition and print the result of the test case.
 * @param msg The message describing the test case.
 * @param actual The actual value obtained from the test.
 * @param expected The expected value for the test case.
 */
#define ASSERT_TRUE(msg, actual) ASSERT_EQUAL(msg, actual, true)

/**
 * Macro to assert that the actual value is false. It uses the ASSERT macro to evaluate the condition and print the result of the test case.
 * @param msg The message describing the test case.
 * @param actual The actual value obtained from the test.
 */
#define ASSERT_FALSE(msg, actual) ASSERT_EQUAL(msg, actual, false)

/**
 * Utility function to convert a vector of integers to a string representation.
 * @param vec The vector of integers to be converted to a string.
 * @return A string representation of the vector in the format "{ elem1, elem2, ... }".
 */
std::string VectorToString(const std::vector<int>& vec) {
    std::stringstream ss;
    ss << "{ ";
    for (size_t i = 0; i < vec.size(); i++) {
        ss << vec[i];
        if (i < vec.size() - 1) {
            ss << ", ";
        }
    }
    ss << " }";
    return ss.str();
}

/**
 * Generates a random number based on the provided seed and size.
 * @param seed The seed for random number generation (passed by reference).
 * @param size The upper bound for the random number (exclusive).
 * @return A random number between 0 and size - 1.
 */
int GetRandomNumber(int& seed, int size) {
    seed = (seed * 97 + 23) % 1000;
    return (seed % size);
}

/**
 * Generates a random vector of integers from 1 to size, shuffled using the provided seed.
 * @param size The size of the vector to generate.
 * @param seed The seed for random number generation (passed by reference).
 * @return A shuffled vector of integers from 1 to size.
 */
std::vector<int> GenerateRandomVector(int size, int& seed) {
    std::vector<int> input(size);
    for (int i = 0; i < size; i++) {
        input[i] = i + 1;
    }
    // Shuffle the vector using the random seed (Fisher-Yates shuffle)
    for (int j = 0; j < size; j++) {
        int rand = GetRandomNumber(seed, size);
        std::swap(input[j], input[rand]);
    }
    return input;
}

#endif // DEBUG_H_