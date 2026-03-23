/**
 * @file kSmall.cpp
 * @brief Implementation of the kSmall function to find the k-th smallest element in an array.
 *
 * Name: Luke Norr
 * StarID: lx8454qp
 * Instructor: Jie Meichsner
 * Due Date: 3/22/26
 * 
 * This file contains the implementation of the partition function and the kSmall function, which uses a quickselect algorithm to efficiently find the k-th smallest element in an array.
 * The partition function rearranges the elements of the array around a pivot, and the kSmall function recursively narrows down the search space based on the position of the pivot relative to k.
 */

#include "kSmall.h"
#include <vector>
#include <iostream>

/**
 * Utility function to print the elements of an array from index first to last.
 * @param msg A message to display before printing the array.
 * @param anArray The array to be printed.
 * @param first The starting index of the subarray to be printed.
 * @param last The ending index of the subarray to be printed.
 */
void debugPrintArray(const std::string& msg, const std::vector<int>& anArray, int first, int last) {
#ifndef DEBUG_PRINT
    return; // Skip printing if DEBUG_PRINT is not defined
#endif // DEBUG_PRINT

    std::cout << msg;
    for (int idx = first; idx <= last; idx++) {
        std::cout << anArray[idx] << " ";
    }
    std::cout << std::endl;
}

int partition(std::vector<int>& anArray, int first, int last) {
    // Use the first element as the pivot for simplicity
    int pivotIndex = first;
    int pivotValue = anArray[pivotIndex];

    debugPrintArray("\tBefore Partition: ", anArray, first, last);

    // Partition
    for (int i = first; i <= last; i++) {
        // Skip the pivot element itself
        if (i == pivotIndex) {
            continue;
        }

        // If the current element is less than the pivot value, swap it with the element at pivotIndex + 1
        if (anArray[i] < pivotValue) {
            std::swap(anArray[++pivotIndex], anArray[i]);
        }
    }

    // Finally, swap the pivot element with the element at pivotIndex to place it in its correct position
    std::swap(anArray[first], anArray[pivotIndex]);

    //debugPrintArray("\tAfter Partition: ", anArray, first, last);

    std::string partitionResult = "Partitioned around pivot " + std::to_string(pivotValue) + " at index " + std::to_string(pivotIndex);
    debugPrintArray("\t" + partitionResult + ": ", anArray, first, last);
    return pivotIndex;
}

int kSmall(int k, std::vector<int>& anArray, int first, int last) {
#ifdef DEBUG_PRINT // Print the current state of the parameters for debugging purposes
    std::cout << "k: " << k << ", first: " << first << ", last: " << last << std::endl;
#endif // DEBUG_PRINT
    
    // Validate input parameters
    if (last < first) {
        throw std::invalid_argument("Last index less than first");
    }

    // Base case: If the subarray has only one element, return that element
    if (last == first) {
        return anArray[first];
    }

    // Partition the array and get the index of the pivot
    int pivotIndex = partition(anArray, first, last);

    // Determine which side of the pivot the k-th smallest element lies and recurse accordingly
    if (k < pivotIndex - first + 1) {
        return kSmall(k, anArray, first, pivotIndex - 1);
    }
    else if (k == pivotIndex - first + 1) {
        return anArray[pivotIndex];
    }
    else {
        return kSmall(k - (pivotIndex - first + 1), anArray, pivotIndex + 1, last);
    }
}