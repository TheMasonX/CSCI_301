/**
 * @file project3.cpp
 * @brief Main entry point for the k-th smallest element project.
 * This file includes the main function that takes input from the user.
 * It then calls the kSmall function to find the k-th smallest element in the array.
 * 
 * Alternately, compiling with DEBUG defined runs unit tests for the kSmall function and its helper functions.
 * The tests are defined in project3_tests.cpp and utilize the ASSERT macros defined in debug.h to validate the correctness of the functions.
 *
 * Name: Luke Norr
 * StarID: lx8454qp
 * Instructor: Jie Meichsner
 * Due Date: 3/22/26
 */

// #define TEST // Uncomment to run unit tests for the kSmall function and its helper functions
// #define DEBUG_PRINT // Uncomment to enable verbose debug print statements

#include <iostream>
#include "kSmall.h"

#ifdef TEST
#include "project3_tests.cpp"
#endif // TEST

int main() {
#ifdef TEST
    return RunTests() ? 0 : 1;
#endif // TEST

    std::cout << "Enter the size of the array: ";
    int size;
    std::cin >> size;
    int* array = new int[size];

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
    std::cout << "Enter the value of k: ";
    int k;
    std::cin >> k;
    try {
        int result = kSmall(k, array, size);
        std::cout << "The " << k << "-th smallest element is: " << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    delete[] array;

    return 0;
}