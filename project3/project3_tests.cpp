/**
 * @file project3_tests.cpp
 * @brief Contains unit tests for the kSmall function and its helper functions.
 * 
 * Name: Luke Norr
 * StarID: lx8454qp
 * Instructor: Jie Meichsner
 * Due Date: 3/22/26
 * 
 * This file includes tests for the partition function and the kSmall function using both static and random test cases.
 * The tests utilize the ASSERT macros defined in debug.h to validate the correctness of the functions.
 */

#include <iostream>
#include <sstream> // Needed for std::stringstream
#include "kSmall.h"
#include "debug.h"

/**
 * Utility function to run a test case for the kSmall function. It takes the value of k, the expected result, and the input array, and uses the ASSERT macros to validate the correctness of the kSmall function.
 * @param k The order of the smallest element to find (1-based index).
 * @param expected The expected value of the k-th smallest element.
 * @param input The input array from which to find the k-th smallest element.
 * @return true if the test passes, false otherwise.
 */
bool RunTest(int k, int expected, std::vector<int>& input, std::string testName = "") {
    bool passed = true;
    std::stringstream msg;
    if (!testName.empty()) {
        msg << testName << ": ";
    }
    msg << k << "-th smallest of input " << VectorToString(input);
    int actual = kSmall(k, input.data(), input.size());
    ASSERT_EQUAL(msg.str(), actual, expected)
    return passed;
}

// ====================================================================
//             Extra tests defined by me to validate the correctness of the partition function and to run random tests on the kSmall function
// ====================================================================

/**
 * Test the partition function to ensure it correctly partitions the array around the pivot and returns the correct pivot index.
 * The input array is {4, 10, 5, 1, 3, 6, 2, 9, 8, 7} and the pivot is the first element (4).
 * After partitioning, the pivot should be in its correct position, and the function should return the index of the pivot.
 * @return true if the test passes, false otherwise.
 */
bool TestPartition() {
    bool passed = true;
    std::vector<int> input = {4, 10, 5, 1, 3, 6, 2, 9, 8, 7};
    int first = 0;
    int last = input.size() - 1;
    int expectedPivotIndex = input.at(first) - 1; // Assuming the first element (4) is the pivot
    int actualPivotIndex = partition(input.data(), first, last);
    ASSERT_EQUAL("Partition Test of " + VectorToString(input), actualPivotIndex, expectedPivotIndex)
    return passed;
}

/**
 * Runs a series of random tests for the kSmall function to ensure its correctness.
 * It generates random input arrays of varying sizes and random values of k, and checks if the kSmall function returns the correct k-th smallest element.
 * @return true if all random tests pass, false otherwise.
 */
bool RunRandomTests(int numTests = 5, int minSize = 10, int maxSize = 20) {
    int seed = 0;
    int failedCount = 0;
    for (int i = 0; i < numTests; i++) {
        int size = GetRandomNumber(seed, maxSize - minSize + 1) + minSize; // Size between minSize and maxSize
        int k = GetRandomNumber(seed, size) + 1; // k between 1 and size
        std::vector<int> input = GenerateRandomVector(size, seed);
        if (!RunTest(k, k, input, "Random Test " + std::to_string(i + 1))) {
            failedCount++;
        }
    }

    if (failedCount > 0) {
        std::cerr << "Failed " << failedCount << " out of " << numTests << " random tests." << std::endl;
    }
    return failedCount == 0;
}

// ====================================================================
//             Tests defined by the Project 3 requirements
// ====================================================================

/**
 * Test case where the k-th smallest element is in the first partition (S1) of the array after partitioning.
 * The input array is {6, 3, 1, 10, 8, 4} and we are looking for the 2nd smallest element, which is expected to be 2.
 * @return true if the test passes, false otherwise.
 */
bool Test1() {
    // kth smallest is in S1
    std::vector<int> input = {6, 3, 1, 10, 8, 4};
    int k = 2;
    int expected = 3;
    return RunTest(k, expected, input, "kth smallest is in S1 after partitioning");
}

/**
 * Test case where the k-th smallest element is the pivot itself after partitioning.
 * The input array is {6, 3, 1, 10, 8, 4} and we are looking for the 4th smallest element, which is expected to be 6 (the pivot).
 * @return true if the test passes, false otherwise.
 */
bool Test2() {
    std::vector<int> input = {6, 3, 1, 10, 8, 4};
    int k = 4;
    int expected = 6;
    return RunTest(k, expected, input, "kth smallest is the pivot after partitioning");
}

/**
 * Test case where the k-th smallest element is in the second partition (S2) of the array after partitioning.
 * The input array is {6, 3, 1, 10, 8, 4} and we are looking for the 5th smallest element, which is expected to be 8.
 * @return true if the test passes, false otherwise.
 */
bool Test3() {
    std::vector<int> input = {6, 3, 1, 10, 8, 4};
    int k = 5;
    int expected = 8;
    return RunTest(k, expected, input, "kth smallest is in S2 after partitioning");
}



// ====================================================================
//   Main Test Runner - runs all tests defined above and reports results
// ====================================================================


/**
 * Runs all the defined test cases for the kSmall function and its helper functions.
 * It keeps track of the number of failed tests and reports the results at the end.
 * @return true if all tests pass, false otherwise.
 */
bool RunTests() {
    int testCount = 0;
    int failedCount = 0;

#define TRACK_COUNTS(test) testCount++; failedCount += test() ? 0 : 1;

    std::cout << "================ Running Required Tests for kSmall Function ================" << std::endl;
    // Tests defined by the project requirements
    TRACK_COUNTS(Test1)
    TRACK_COUNTS(Test2)
    TRACK_COUNTS(Test3)

    // My tests
    std::cout << "\n================ Running Additional Tests for kSmall Function ================" << std::endl;
    TRACK_COUNTS(TestPartition)
    TRACK_COUNTS(RunRandomTests)

    if (failedCount == 0) {
        std::cout << GREEN << "================ All TESTS PASSED ================" << RESET << std::endl;
    }
    else {
        std::cerr << RED << "================ " << failedCount << "/" << testCount << " TESTS FAILED ================" << RESET << std::endl;
    }
    return failedCount == 0;
}