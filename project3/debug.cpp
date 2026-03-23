/**
 * @file debug.cpp
 * @brief Contains unit test macros and utility functions for debugging.
 *
 * Name: Luke Norr
 * StarID: lx8454qp
 * Instructor: Jie Meichsner
 */

#include "debug.h"
#include <sstream>
#include <vector>

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

int GetRandomNumber(int& seed, int size) {
    seed = (seed * 4241 + 1777) % 10000;
    return (seed % size);
}

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
