/**
 * @file project3_tests.h
 * @brief Header file for the unit tests of the kSmall function and its helper functions.
 * 
 * Name: Luke Norr
 * StarID: lx8454qp
 * Instructor: Jie Meichsner
 * Due Date: 3/22/26
 * 
 * This file declares the test functions and utility functions for testing the kSmall function.
 */

#ifndef PROJECT3_TESTS_H_
#define PROJECT3_TESTS_H_

#include <vector>
#include <string>

/**
 * Utility function to run a test case for the kSmall function. It takes the value of k, the expected result, and the input array, and uses the ASSERT macros to validate the correctness of the kSmall function.
 * @param k The order of the smallest element to find (1-based index).
 * @param expected The expected value of the k-th smallest element.
 * @param input The input array from which to find the k-th smallest element.
 * @param testName Optional name for the test case.
 * @return true if the test passes, false otherwise.
 */
bool RunTest(int k, int expected, std::vector<int>& input, std::string testName = "");

/**
 * Test the partition function to ensure it correctly partitions the array around the pivot and returns the correct pivot index.
 * @return true if the test passes, false otherwise.
 */
bool TestPartition();

/**
 * Runs a series of random tests for the kSmall function to ensure its correctness.
 * @param numTests The number of random tests to run (default: 5).
 * @param minSize The minimum size of the test arrays (default: 10).
 * @param maxSize The maximum size of the test arrays (default: 20).
 * @return true if all random tests pass, false otherwise.
 */
bool RunRandomTests(int numTests = 5, int minSize = 10, int maxSize = 20);

/**
 * Test case where the k-th smallest element is in the first partition (S1) of the array after partitioning.
 * @return true if the test passes, false otherwise.
 */
bool Test1();

/**
 * Test case where the k-th smallest element is the pivot itself after partitioning.
 * @return true if the test passes, false otherwise.
 */
bool Test2();

/**
 * Test case where the k-th smallest element is in the second partition (S2) of the array after partitioning.
 * @return true if the test passes, false otherwise.
 */
bool Test3();

/**
 * Runs all the defined test cases for the kSmall function and its helper functions.
 * It keeps track of the number of failed tests and reports the results at the end.
 * @return true if all tests pass, false otherwise.
 */
bool RunTests();

#include "project3_tests.cpp"
#endif // PROJECT3_TESTS_H_
