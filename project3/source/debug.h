/**
 * @file debug.h
 * @brief Contains unit test macros.
 *
 * Name: Luke Norr
 * StarID: lx8454qp
 * Due Date: 3/19/26
 * Instructor: Jie Meichsner
 */
#ifndef DEBUG_H_
#define DEBUG_H_

#include <iostream>
#include <sstream> // Required for istringstream

#define SEPARATOR "\n=================================================\n"

#define PRINT_RES(msg, actual, expected) msg << " returned: " << actual << ". Expected: " << expected << std::endl;
#define PRINT_PASS(msg, actual, expected) std::cout << "PASS: " << PRINT_RES(msg, actual, expected)
#define PRINT_FAIL(msg, actual, expected) std::cerr << "FAIL: " << PRINT_RES(msg, actual, expected)
#define ASSERT(condition, msg, actual, expected) if (condition) { PRINT_PASS(msg, actual, expected) } \
                                                 else { passed = false; PRINT_FAIL(msg, actual, expected) }

#define ASSERT_EQUAL(msg, actual, expected) ASSERT(actual == expected, msg, actual, expected)
#define ASSERT_NOT_EQUAL(msg, actual, expected) ASSERT(!(actual == expected), msg, actual, expected)

#define ASSERT_TRUE(msg, actual) ASSERT_EQUAL(msg, actual, true)
#define ASSERT_FALSE(msg, actual) ASSERT_EQUAL(msg, actual, false)

#endif // DEBUG_H_