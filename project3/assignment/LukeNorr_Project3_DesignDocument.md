# CSCI 301 - Project 3 - *k<sup>th</sup>* Smallest

## Design Document

### Introduction

This project implements a recursive algorithm to find the *k<sup>th</sup>* smallest element in an array using the quickselect approach. The algorithm partitions the array around the first element and recursively searches only the relevant partition.

### Data Structures Used

- Dynamic array (`int*` with `new[]`): stores input
- Index variables: track bounds and pivot position
- Scalar variables: represent k, size, and pivot value

### Functions and Pseudocodes

The project uses two core functions: `partition` and `kSmall`.

#### Function: `partition`
- Rearranges the array around the first element (pivot) and returns its final index
- Inputs: pointer to array, first and last indices
- Output: pivot index after partitioning

Pseudocode:

```text
partition(anArray, first, last)
	pivotIndex <- first
	pivotValue <- anArray[first]

	for i from first to last
		if i == pivotIndex
			continue
		if anArray[i] < pivotValue
			pivotIndex <- pivotIndex + 1
			swap(anArray[pivotIndex], anArray[i])

	swap(anArray[first], anArray[pivotIndex])
	return pivotIndex
```

#### Function: `kSmall`
- Recursively finds the *k<sup>th</sup>* smallest element
- Inputs: k, array pointer, first and last indices
- Output: the *k<sup>th</sup>* smallest value

Pseudocode:

```text
kSmall(k, anArray, first, last)
	if last < first
		error "invalid range"

	if first == last
		return anArray[first]

	pivotIndex <- partition(anArray, first, last)
	rank <- pivotIndex - first + 1

	if k < rank
		return kSmall(k, anArray, first, pivotIndex - 1)
	else if k == rank
		return anArray[pivotIndex]
	else
		return kSmall(k - rank, anArray, pivotIndex + 1, last)
```

#### Helper Functions

- `kSmall(int k, int* anArray, int size)`: Wrapper that calls the recursive version with full array bounds

### Structure Chart of Main Program

```text
main
	-> read array size from user
	-> allocate dynamic array with new[]
	-> read array elements
	-> read k
	-> call kSmall(k, array, size)
	-> print resulting k-th smallest value
	-> delete[] dynamic array
```

## Code Listing

The Project 3 files are stored in the root folder of my GitHub submission. The main source files for this program are located in:

- `project3.cpp`
- `kSmall.h`
- `kSmall.cpp`
- `project3_tests.h`
- `project3_tests.cpp`
- `debug.h`

## User Document

### Program Description

Finds the *k<sup>th</sup>* smallest element in an array. User inputs the array size, elements, and k; the program outputs the result.

### How to Compile
Compile from `project3` with `mkdir -p` to create the output directory:

```bash
cd project3
mkdir -p output && g++ -Wall -Wextra -g project3.cpp -o output/project3.out
```

#### Debug Mode
Two flags available: `TEST` (units tests) and `DEBUG_PRINT` (verbose output).
```bash
cd project3
mkdir -p output && g++ -Wall -Wextra -g -DTEST project3.cpp -o ./output/project3_tests.out
```

With both flags:
```bash
cd project3
mkdir -p output && g++ -Wall -Wextra -g -DTEST -DDEBUG_PRINT project3.cpp -o ./output/project3_tests.out
```

### How to Run

```bash
cd project3
./output/project3.out
```

To run the debug build:

```bash
cd project3
./output/project3_tests.out
```

### Input Requirements

1. Array size
2. Array elements (integers)
3. Value of k (between 1 and array size)

### Example Run

```text
Enter the size of the array: 6
Enter the elements of the array: 6 3 1 10 8 4
Enter the value of k: 4
The 4-th smallest element is: 6
```

## Test Results

### Test Cases

| Input | k | Expected | Result |
|---|---|---|---|
| `6 3 1 10 8 4` | 2 | 3 | ✓ |
| `6 3 1 10 8 4` | 4 | 6 | ✓ |
| `6 3 1 10 8 4` | 5 | 8 | ✓ |
| `6 3 1 10 8 4` | 1 | 1 | ✓ |
| `6 3 1 10 8 4` | 6 | 10 | ✓ |

### Test Examples

- `6 3 1 10 8 4`, k=2: Result in S1 (left partition)
- `6 3 1 10 8 4`, k=4: Result is the pivot itself
- `6 3 1 10 8 4`, k=5: Result in S2 (right partition)
- `6 3 1 10 8 4`, k=1: Smallest element
- `6 3 1 10 8 4`, k=6: Largest element

All three required cases tested and passed.

## Summary

The main challenge was handling the partitioning in-place. I didn't want to allocate extra memory, as that seemed like it defeated the purpose and I knew there was a way to pull it off. I remembered that quicksort uses a similar algorithm to this, quickselect. I thought that was what the textbook meant when it said this could be extended to use as a sorting algorithm.