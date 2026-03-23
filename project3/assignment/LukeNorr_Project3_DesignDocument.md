# CSCI 301 - Project 3 - *k*th Smallest

## Design Document

### Introduction

The *k*th smallest element problem asks for the value that would appear in position `k` if the array were sorted, without necessarily sorting the full array. In this project, I implemented a recursive quickselect-style solution that uses a partition function and always chooses the first value of the current subarray as the pivot.

The solution repeatedly partitions the array and then recurses only into the side that can contain the desired order statistic. This gives good practical performance and demonstrates recursive problem decomposition.

### Data Structures Used

- Dynamic integer array (`int*` created with `new[]`): stores user input and satisfies the project requirement to use a pointer-based array.
- Index variables (`first`, `last`, `pivotIndex`): track subarray bounds and pivot position during partitioning.
- Scalar variables (`k`, `size`, `pivotValue`): represent requested order statistic, array size, and pivot value.
- Recursion call stack: stores each recursive `kSmall` state until the base case is reached.

No classes were used, so UML diagrams are not applicable for this program.

### Functions and Pseudocodes

The project uses two core functions: `partition` and `kSmall`.

#### Function: `partition`
- Purpose: Rearranges `anArray[first..last]` around the first element as pivot and returns the pivot's final index.
- Inputs: `int* anArray`, `int first`, `int last`.
- Output: Integer index where the pivot is placed after partitioning.
- Precondition: `anArray` points to valid memory; `0 <= first <= last`; `last` is within the allocated array range.
- Postcondition: All values left of returned pivot index are `< pivot`; all values right of it are `>= pivot`; pivot is in final sorted position relative to the current subarray.

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
- Purpose: Recursively finds the k-th smallest element in the current subarray.
- Inputs: `int k`, `int* anArray`, `int first`, `int last`.
- Output: The k-th smallest integer value in `anArray[first..last]` (where `k` is 1-based within that subarray).
- Precondition: `anArray` is valid; `first <= last`; `1 <= k <= (last - first + 1)`.
- Postcondition: Returns the correct order statistic for the requested `k` in the current subarray.

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

#### Additional Helper Functions (if any)

- `kSmall(int k, int* anArray, int size)`
	- Purpose: Convenience wrapper that calls the recursive function over the full array bounds.
	- Inputs: `k`, `anArray`, `size`.
	- Output: k-th smallest value in the full array.
	- Precondition: `size > 0` and `1 <= k <= size`.
	- Postcondition: Returns the correct k-th smallest value for the full input array.

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

The Project 3 files are stored in the `project3` folder of my GitHub submission. The main source files for this program are located in:

- `project3/project3.cpp`
- `project3/kSmall.h`
- `project3/kSmall.cpp`
- `project3/project3_tests.h`
- `project3/project3_tests.cpp`
- `project3/debug.h`

## User Document

### Program Description

This program finds the k-th smallest element in an unsorted array of integers. It uses the quickselect approach with recursion and a partition function that always uses the first element in the current subarray as the pivot. The user enters the size of the array, the array values, and the value of k. The program then reports the k-th smallest value.

### How to Compile
I compile from the `project3` directory to the `output` folder with `-Wall` and `-Wextra` enabled.
I use `mkdir` to ensure the `output` folder exists.

```bash
cd project3
mdkir output && g++ -Wall -Wextra -g project3.cpp -o output/project3.out
```

#### Debug Mode
Two preprocessor flags exist for debugging purposes:
`TEST` and `DEBUG_PRINT`

Use `-D{DEFINE}` to define a preprocessor

To enable the unit tests in `project3_tests.cpp`:
```bash
cd project3
mdkir output && g++ -Wall -Wextra -g -DTEST project3.cpp -o output/project3_tests.out
```

To enable debug logging, particularly of the partition function, define `DEBUG_PRINT`:
```bash
cd project3
mdkir output && g++ -Wall -Wextra -g -DTEST -DDEBUG_PRINT project3.cpp -o output/project3_tests.out
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

- The first input must be the size of the array.
- The next inputs must be exactly that many integer values.
- The final input must be the value of `k`.
- `k` should be in the range `1` through `size`.
- The program assumes the user enters valid integer input.

### Example Run

```text
Enter the size of the array: 6
Enter the elements of the array: 6 3 1 10 8 4
Enter the value of k: 4
The 4-th smallest element is: 6
```

## Test Plan and Running Results

The program was tested with normal cases, required project cases, and out-of-range cases. The goal of the test data was to confirm that the recursive selection logic works when the k-th smallest element is in the first partition, is the pivot itself, and is in the second partition.

### Test Cases Summary

| Test Category | Test ID | Input Data | Why This Case | Expected Result | Actual Result |
|---|---|---|---|---|---|
| Valid | V1 | `{6, 3, 1, 10, 8, 4}`, `k = 2` | Confirms the k-th smallest value is in `S1` after partition | `3` | `3` |
| Valid | V2 | `{6, 3, 1, 10, 8, 4}`, `k = 4` | Confirms the k-th smallest value is the pivot after partition | `6` | `6` |
| Boundary | B1 | `{6, 3, 1, 10, 8, 4}`, `k = 1` | Smallest valid order statistic | `1` | `1` |
| Boundary | B2 | `{6, 3, 1, 10, 8, 4}`, `k = 6` | Largest valid order statistic | `10` | `10` |
| Invalid | I1 | `{6, 3, 1, 10, 8, 4}`, `k = 0` | Out of valid range on the low end | Error or invalid input handling should occur | Not validated by the current main program |
| Invalid | I2 | `{6, 3, 1, 10, 8, 4}`, `k = 7` | Out of valid range on the high end | Error or invalid input handling should occur | Not validated by the current main program |

### Test Data with Explanation

1. `6 3 1 10 8 4`, `k = 2`
	Explanation: After partitioning around the first element `6`, the 2nd smallest value falls in the first partition `S1`. This verifies the recursive call into the left side of the array.

2. `6 3 1 10 8 4`, `k = 4`
	Explanation: After partitioning, the pivot `6` ends up as the 4th smallest value. This verifies the case where the algorithm should return the pivot immediately.

3. `6 3 1 10 8 4`, `k = 5`
	Explanation: After partitioning, the 5th smallest value is in the second partition `S2`. This verifies the recursive call into the right side of the array with an adjusted k value.

4. `6 3 1 10 8 4`, `k = 1`
	Explanation: This boundary test checks whether the program can correctly return the smallest element in the array.

5. `6 3 1 10 8 4`, `k = 6`
	Explanation: This boundary test checks whether the program can correctly return the largest element in the array.

### Required Project 3 Coverage

| Required Scenario | Input Example | k | Expected Condition | Actual Condition |
|---|---|---|---|---|
| kth smallest in S1 | `6 3 1 10 8 4` | 2 | kth is in S1 after partition | Passed |
| kth smallest is pivot | `6 3 1 10 8 4` | 4 | kth equals pivot after partition | Passed |
| kth smallest in S2 | `6 3 1 10 8 4` | 5 | kth is in S2 after partition | Passed |

### Script Output Notes

The debug run showed that the partition test passed, the random tests passed, and all three required project cases passed. A sample interactive run also returned the correct answer for the input `6 3 1 10 8 4` with `k = 4`.

## Summary

This project reinforced how recursive algorithms can reduce work by focusing only on the relevant partition of the array instead of fully sorting it. The most challenging part was implementing in-place partitioning while keeping pivot movement correct and avoiding index mistakes. I learned how to connect pivot rank to recursive subproblems and how to adjust `k` when recursing into the right partition.

If I continued improving this program, I would add input validation for out-of-range `k` in `main` and include more automated tests for invalid user input cases.