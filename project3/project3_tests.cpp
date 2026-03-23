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
#include "project3_tests.h"

bool RunTest(int k, int expected, std::vector<int>& input, std::string testName) {
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

bool RunRandomTests(int numTests, int minSize, int maxSize) {
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

bool Test1() {
    // kth smallest is in S1
    std::vector<int> input = {6, 3, 1, 10, 8, 4};
    int k = 2;
    int expected = 3;
    return RunTest(k, expected, input, "kth smallest is in S1 after partitioning");
}

bool Test2() {
    std::vector<int> input = {6, 3, 1, 10, 8, 4};
    int k = 4;
    int expected = 6;
    return RunTest(k, expected, input, "kth smallest is the pivot after partitioning");
}

bool Test3() {
    std::vector<int> input = {6, 3, 1, 10, 8, 4};
    int k = 5;
    int expected = 8;
    return RunTest(k, expected, input, "kth smallest is in S2 after partitioning");
}



// ====================================================================
//   Main Test Runner - runs all tests defined above and reports results
// ====================================================================

void TrackCounts(bool passed, int& testCount, int& failedCount) {
    testCount++;
    if (!passed) {
        failedCount++;
    }
}

bool RunTests() {
    int testCount = 0;
    int failedCount = 0;

    std::cout << "================ Running Required Tests for kSmall Function ================" << std::endl;
    // Tests defined by the project requirements
    TrackCounts(Test1(), testCount, failedCount);
    TrackCounts(Test2(), testCount, failedCount);
    TrackCounts(Test3(), testCount, failedCount);

    // My tests
    std::cout << "\n================ Running Additional Tests for kSmall Function ================" << std::endl;
    TrackCounts(TestPartition(), testCount, failedCount);
    TrackCounts(RunRandomTests(), testCount, failedCount);

    if (failedCount == 0) {
        std::cout << GREEN << "================ All TESTS PASSED ================" << RESET << std::endl;
    }
    else {
        std::cerr << RED << "================ " << failedCount << "/" << testCount << " TESTS FAILED ================" << RESET << std::endl;
    }
    return failedCount == 0;
}