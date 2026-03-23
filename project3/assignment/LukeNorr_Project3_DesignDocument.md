# CSCI 301 - Project 3 - *k*th Smallest

## Design Document

### Introduction

The *k*th smallest element of an array 

### Data Structures Used

[List all data structures used in your solution, such as dynamic arrays, variables for indices, and recursion-related parameters.]

- [Data structure 1]: [Purpose]
- [Data structure 2]: [Purpose]

[If classes are used, include UML diagrams as required.]

### Functions and Pseudocodes

[Document each function you implemented, including preconditions and postconditions.]

#### Function: `partition`
- Purpose: [Explain what partition does in this project.]
- Inputs: [array pointer, first, last, etc.]
- Output: [pivot index or equivalent]
- Precondition: [State required assumptions]
- Postcondition: [State guarantees after execution]

Pseudocode:

```text
[Write pseudocode for partition here]
```

#### Function: `kSmall`
- Purpose: [Explain recursive kth-smallest selection logic]
- Inputs: [array pointer, first, last, k]
- Output: [kth smallest value]
- Precondition: [State valid range assumptions]
- Postcondition: [State returned value meaning]

Pseudocode:

```text
[Write pseudocode for kSmall here]
```

#### Additional Helper Functions (if any)

[Add any helper functions in the same format as above.]

### Structure Chart of Main Program

```text
main
	-> [initialize dynamic array]
	-> [print original array]
	-> [call kSmall for test case 1: kth in S1]
	-> [call kSmall for test case 2: kth is pivot]
	-> [call kSmall for test case 3: kth in S2]
	-> [cleanup dynamic memory]
```

## Code Listing

[Paste or reference your final source code files.]

[Ensure your program includes required top comments: problem description, startID and name, due date, instructor, and comments.]

[Ensure functions use Javadoc-style comments with pre and post conditions.]

## User Document

### Program Description

[Briefly describe what the program does for a user.]

### File Location on GitHub

[Provide repository path to your project files.]

### How to Compile

```bash
[Example: g++ -std=c++17 -Wall -Wextra -o project3 main.cpp]
```

### How to Run

```bash
[Example: ./project3]
```

### Input Requirements

[State any assumptions about array size, k range, and valid input format.]

### Example Run

```text
[Paste one complete sample run here]
```

## Test Plan and Running Results

[Include at least valid, boundary, and invalid cases where applicable.]

### Test Cases Summary

| Test Category | Test ID | Input Data | Why This Case | Expected Result | Actual Result |
|---|---|---|---|---|---|
| Valid | V1 | [array], k=[ ] | [reason] | [expected] | [actual] |
| Valid | V2 | [array], k=[ ] | [reason] | [expected] | [actual] |
| Boundary | B1 | [array], k=1 | [minimum order statistic] | [expected] | [actual] |
| Boundary | B2 | [array], k=n | [maximum order statistic] | [expected] | [actual] |
| Invalid | I1 | [array], k=0 | [out of range] | [error handling behavior] | [actual] |
| Invalid | I2 | [array], k>n | [out of range] | [error handling behavior] | [actual] |

### Required Project 3 Coverage

| Required Scenario | Input Example | k | Expected Condition | Actual Condition |
|---|---|---|---|---|
| kth smallest in S1 | [your array] | [ ] | kth is in S1 after partition | [fill] |
| kth smallest is pivot | `6 3 1 10 8 4` | 4 | kth equals pivot after partition | [fill] |
| kth smallest in S2 | [your array] | [ ] | kth is in S2 after partition | [fill] |

### Script Output Notes

[Attach or summarize your GitHub run script outputs. Do not include source code in script files.]

## Summary

[Write what you learned, what was challenging, and how the solution could be improved or extended.]