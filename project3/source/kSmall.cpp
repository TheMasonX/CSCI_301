
#include <vector>
#include <iostream>

/**
 * Utility function to print the elements of an array from index first to last.
 * @param msg A message to display before printing the array.
 * @param anArray The array to be printed.
 * @param first The starting index of the subarray to be printed.
 * @param last The ending index of the subarray to be printed.
 */
void printArray(std::string msg, std::vector<int>& anArray, int first, int last) {
    std::cout << msg;
    for (int idx = first; idx <= last; idx++) {
        std::cout << anArray[idx] << " ";
    }
    std::cout << std::endl;
}

/**
 * Partition the array anArray[first..last] about a pivot value and return the index of the pivot after partitioning.
 * The pivot value is chosen as the first element of the array for simplicity.
 * After partitioning, all elements less than the pivot value will be on the left side of the pivot,
 * and all elements greater than or equal to the pivot value will be on the right side.
 * @param anArray The input array to be partitioned.
 * @param first The starting index of the subarray to be partitioned.
 * @param last The ending index of the subarray to be partitioned.
 * @return The index of the pivot after partitioning.
 * @throws std::runtime_error if the partitioning fails
*/
int partition(std::vector<int>& anArray, int first, int last) {
    // Choose a pivot value pivotValue from anArray[first..last]
    // Partition the values of anArray[first..last] about pivotValue

    // Use the first element as the pivot for simplicity
    int pivotIndex = first;
    int pivotValue = anArray[pivotIndex];

#if DEBUG_PRINT
    std::cout << "\tPivot Index: " << pivotIndex << ", Pivot Value: " << pivotValue << std::endl;
    printArray("\tBefore Partition: ", anArray, first, last);
#endif

    // Partition
    for (int i = first; i <= last; i++) {
        if (i == pivotIndex) {
            continue;
        }

#if DEBUG_PRINT
        std::cout << "\t\tIndex: " << i << ", Value: " << anArray[i] << ", Pivot Index: " << pivotIndex << std::endl;
#endif
        if (anArray[i] < pivotValue) {
            std::swap(anArray[++pivotIndex], anArray[i]);
        }
#if DEBUG_PRINT
        printArray("\t\tAfter Swap: ", anArray, first, last);
#endif
    }
    std::swap(anArray[first], anArray[pivotIndex]);

#if DEBUG_PRINT
    printArray("\tAfter Partition: ", anArray, first, last);
#endif

    return pivotIndex;
}

/**
 * Finds the k-th smallest element in the given array.
 * @param k The order of the smallest element to find (1-based index).
 * @param anArray The input array of integers.
 * @param first The starting index of the current subarray.
 * @param last The ending index of the current subarray.
 * @return The k-th smallest element in the array.
 * @throws std::invalid_argument if k is out of bounds or if the array is empty
 * @throws std::runtime_error if the partitioning fails
 */
int kSmall(int k, std::vector<int>& anArray, int first, int last) {
#if DEBUG_PRINT
    std::cout << "k: " << k << ", first: " << first << ", last: " << last << std::endl;
#endif
    
    if (last < first) {
        throw std::invalid_argument("Last index less than first");
    }

    if (last == first) {
        return anArray[first];
    }
    
    int pivotIndex = partition(anArray, first, last);

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

/**
 * Finds the k-th smallest element in the given array.
 * @param k The order of the smallest element to find (1-based index).
 * @param anArray The input array of integers.
 * @return The k-th smallest element in the array.
 * @throws std::invalid_argument if k is out of bounds or if the array is empty
 * @throws std::runtime_error if the partitioning fails
 */
int kSmall(int k, std::vector<int>& anArray) {
    return kSmall(k, anArray, 0, anArray.size() - 1);
}