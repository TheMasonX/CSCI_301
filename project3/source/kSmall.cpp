
#include <vector>
#include <iostream>

void printArray(std::string msg, std::vector<int>& anArray, int first, int last) {
    std::cout << msg;
    for (int idx = first; idx <= last; idx++) {
        std::cout << anArray[idx] << " ";
    }
    std::cout << std::endl;
}

int partition(int k, std::vector<int>& anArray, int first, int last) {
    // Choose a pivot value pivotValue from anArray[first..last]
    // Partition the values of anArray[first..last] about pivotValue

    // Example pivot selection (middle element)
    int pivotIndex = first + (last - first) / 2;
    int pivotValue = anArray[pivotIndex];
    std::cout << "\tPivot Index: " << pivotIndex << ", Pivot Value: " << pivotValue << std::endl;
    printArray("\tBefore Partition: ", anArray, first, last);

    // Partition
    int count = (last - first) + 1;
    std::vector<int> partition;
    partition.resize(count);
    int before = first;
    int after = count - 1;
    
    for (int i = first; i <= last; i++) {
        int val = anArray[i];
        if (val < pivotValue)
            partition[before++] = val;
        else if (val > pivotValue)
            partition[after--] = val;
    }
    
    for (int j = 0; j <= count; j++) {
        int index = j + first;
        if (j >= before && j <= after) {
            anArray[index] = pivotValue;
        }
        else {
            anArray[index] = partition[j];
        }
    }

    printArray("\tAfter Partition: ", anArray, first, last);
    return pivotIndex;
}

int kSmall(int k, std::vector<int>& anArray, int first, int last) {
    std::cout << "k: " << k << ", first: " << first << ", last: " << last << std::endl;
    
    if (last < first) {
        throw "Last index less than first";
    }

    if (last == first) {
        return anArray[first];
    }
    
    int pivotIndex = partition(k, anArray, first, last);

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

int kSmall(int k, std::vector<int>& anArray) {
    return kSmall(k, anArray, 0, anArray.size() - 1);
}