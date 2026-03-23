/**
 * @file project3.cpp
 * @brief Main entry point for the k-th smallest element project.
 * This file includes the main function which runs unit tests for the kSmall function and its helper functions.
 * The tests are defined in project3_debug.cpp and utilize the ASSERT macros defined in debug.h to validate the correctness of the functions.
 *
 * Name: Luke Norr
 * StarID: lx8454qp
 * Instructor: Jie Meichsner
 * Due Date: 3/22/26
 */

#define DEBUG // Define DEBUG to enable debug mode and run tests
// #define DEBUG_PRINT // Uncomment to enable debug print statements

#include <iostream>
#include <sstream> // Needed for std::stringstream
#include "kSmall.h"

#ifdef DEBUG
#include "project3_debug.cpp"
#endif // DEBUG

int main() {
#ifdef DEBUG
    if (!RunTests()) {
        return 1;
    }
#endif // DEBUG

    return 0;
}