/**
 * @file kSmall.h
 * @brief Header file for the kSmall function to find the k-th smallest element in an array.
 *
 * Name: Luke Norr
 * StarID: lx8454qp
 * Instructor: Jie Meichsner
 * Due Date: 3/22/26
 */

#ifndef KSMALL_H_
#define KSMALL_H_

#include <vector>

/**
 * Partitions the array anArray[first..last] about a pivot value and returns the index of the pivot after partitioning.
 * The pivot value is chosen as the first element of the array for simplicity.
 * After partitioning, all elements less than the pivot value will be on the left side of the pivot,
 * and all elements greater than or equal to the pivot value will be on the right side.
 * @param anArray The input array to be partitioned.
 * @param first The starting index of the subarray to be partitioned.
 * @param last The ending index of the subarray to be partitioned.
 * @return The index of the pivot after partitioning.
*/
int partition(std::vector<int>& anArray, int first, int last);

/**
 * Returns the k-th smallest element in the array anArray.
 * @param k The order of the smallest element to find (1-based index).
 * @param anArray The input array from which to find the k-th smallest element.
 * @param first The starting index of the current subarray.
 * @param last The ending index of the current subarray.
 * @return The k-th smallest element in the array.
 */
int kSmall(int k, std::vector<int>& anArray, int first, int last);

/**
 * Overloaded function to call kSmall with the full array range.
 * @param k The order of the smallest element to find (1-based index).
 * @param anArray The input array from which to find the k-th smallest element.
 * @return The k-th smallest element in the array.
 */
int kSmall(int k, std::vector<int>& anArray) {
    return kSmall(k, anArray, 0, anArray.size() - 1);
}

#include "kSmall.cpp" // Include the implementation of the functions
#endif // KSMALL_H_