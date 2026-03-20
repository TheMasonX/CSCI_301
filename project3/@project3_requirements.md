# Project 3 - kth Smallest

## Introduction
The purpose of this project is to gain experience using recursive thinking to solve problems.

## Completion Instructions
Implement the algorithm `kSmall`, discussed in class (Chapter 2, Section 2.4.4), as a C++ function. Use the first value of the array as the pivot. The partition of the array must be implemented using a function as well. Test your functions in a main program.

### Hints

1. The partition function not only rearranges the array elements but also calculates the pivot's index when the partition is done. Make sure your function has the correct type and parameters.

2. Please note that S1 could be empty. For example, when the array has the following elements:

```
1 3 5 2 19 3 4
```

If the first element is used as the pivot, S1 is empty. In this case, no swap is needed. Eventually, the array will have no change. Your partition function must handle this special case, otherwise you will get a runtime error such as a core dump.

## Requirements
- The array parameter MUST be passed as a pointer.
- The array passed to the function in the main program must be generated as a dynamic array using the `new` operator.

## Other Requirements
Add the following information at the top of the main program:
- Description of the problem to solve
- Your startID and name
- Due date
- Instructor
- Comments

For functions, add necessary documentation and comments using Javadoc-style comments. Refer to the textbook on Javadoc-style comments from pages 759-760 and Appendix I on page 809 (7th edition). You can also follow the document `About Programming Assignments` posted on D2L.

Test the algorithm with all three cases:
- kth smallest is in S1
- kth smallest is the pivot
    - For example, if an array contains the following elements:
    ```
    6 3 1 10 8 4
    ```
    You need to test `k=4` because after the partition the array is:
    ```
    4 3 1 6 8 10
    ```
    The 4th smallest is `6`, which is the pivot. Therefore you need to choose `k=4` to test this case.
- kth smallest is in S2

## Submission Instructions
- Submit all source programs to your account in the GitHub system.
- Test your program on GitHub to make sure it works correctly.
- Submit the following documents to the drop box `Project3` on D2L:
    - The source program
    - A script file for test runs on GitHub
        - Do not list your program source code in the script file
    - A Word file that contains:
        - Test data with an explanation
        - A user document with the following sections:
            - Description of the problem to solve
            - File location on GitHub
            - How to compile the program
            - How to run the program

Follow the details of the document `CSCI 301 - About Programming Assignments` posted on D2L.

## Grading Rubric
| Requirements                          | Points  |
|---------------------------------------|---------|
| Comments in the program               | 10      |
| Program correctness                   | 50      |
| Script file from test runs on GitHub  | 20      |
| Test data with explanation            | 10      |
| User document                         | 10      |
| **TOTAL POINTS**                      | **100** |
