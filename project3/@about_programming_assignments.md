# CSCI 301 - General Requirements for Programming Assignments

## Design Document

A design document describes the design of the program: what it does and how it does it. This document should be typed or word-processed. It should provide a description of the problem and enough detail about the program you have written to solve it that a reader, seeing nothing more than the design document, could substantially reproduce your program. Be sure not to plagiarize the project handouts.

This document should include at least the following parts:
- Introduction
- Data structures used (such as classes, arrays, and so on)
    - If C++ classes are used, UML diagrams are required (please refer to Chapter 13 of the CSCI 201 Textbook about UML)
- Functions and their pseudocodes
- Structure chart of the main program

## Code Listing

The code should be formatted for good readability and should include the usual comments, including an introductory comment that summarizes the program's purpose and design and includes the author's name, the course and section numbers, and the date the project is submitted. Each function's comments must include pre- and post-conditions: what must be true of the values going in, and what the calling code can expect to be true of the values coming back, assuming that the precondition is satisfied.

For all projects, it is required to use Javadoc-style comments. Please refer to the textbook on Javadoc-style comments from pages 759-760 and Appendix I on page 809 (7th edition).

## User Document

A user document describes how to use the program. This document should include an example of how to run the program. You must clearly instruct where the program and related files are located, how to compile the program, and then how to run the program. Please be sure to describe any requirements that input data must satisfy. The grader will run your program by following this document for directions. Note that a user should not be told anything about how the program is implemented.

## Test Plan and Running Results

The test data should be verified and be appropriate. Generally, you should have at least three sets of test data: valid values, boundary values, and invalid values, to show that the program does what it is supposed to do. You will design your own test data. On the printout, annotate each data file and test to describe what feature(s) of the program the run is testing.

## Summary

A summary of what you learned from the assignment, how your solution to the problem might be extended or improved, and answers to any questions posed on the project page. This, too, should be typed or word-processed.

---

## Examples

### 1. Design Document

#### Introduction

Formatting text is arranging it on the screen or page in a particular way. This program is a simple text formatter: it reads an input file of text and writes the text to an output file, arranged into lines no longer than a fixed maximum length. The program considers any block of contiguous characters to be a word and white space---blanks, tabs, ends of lines---separates words. The program breaks output lines between words.

The program reads the names of the input and output files and the output line length from the terminal.

#### Data Structures

The program uses only one data structure, a string (array of characters) called `s`. This array holds each word read from the input file, in turn. A program constant sets the maximum allowed value of the output line length, and the string `s` is declared to be of this maximum length; an output line may be filled by one word. Another program constant sets the minimum allowed value of the output line length. It is assumed that no word in the input file exceeds the line length the user specifies.

A variable keeps track of the current length of the output line. This variable is reset when the program begins each new output line.

#### Functions

The program uses three functions:
- Two read the names of the files and open them for input and output, respectively. They continue to prompt for file names until each file is opened successfully.
- Another function reads the output line length, which must fall between the bounds set by the two program constants. This function, too, continues to prompt for input until the user enters a value within those bounds. The program also calls `strlen()` from the `string.h` library and `eof()` and `fail()` from `fstream.h`.

#### Structure Chart of the Main Program

```
Main Program
    |
    |-- open_input_file()
    |-- open_output_file()
    |-- read_int()
```

---

### 2. Code Listing

```cpp
/** A text formatter.
 * @file location: /home/STCLOUDSTATE/jq4933kt/CSCI301/Project3/format.cpp
 * @author John Smith, CSCI 301-Section 1
 * @startID jq2342we
 * @due date September 21, Friday
 *
 * This program reads an input file of text and writes an output file of the
 * same text, formatted into lines no longer than a maximum length. The names
 * of the input and output files and the maximum line length are read from the
 * terminal. Functions open the files, and continue prompting for file names
 * until names are entered that can be successfully opened. Another function
 * reads the maximum line length, which must fall within bounds set by two
 * program constants.
 *
 * The program reads and writes words from the input file one at a time. It
 * keeps track of the length of the current line so far; if the next word would
 * cause that line to exceed the maximum length, the program terminates that
 * line, writes the word on the next line, and resets the line length. The
 * program writes a blank after each word, except perhaps the last word on a
 * line. A word is a string of contiguous non-blank characters, and we assume
 * that no input word is longer than the input line.
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

const int MIN = 30;  // Minimum line length
const int MAX = 80;  // Maximum line length

/** Opens for input a file named from the terminal.
 * @param in_f is ifstream
 * @pre None
 * @post A file stream has been opened for input.
 */
void open_input_file(ifstream& in_f);

/** Opens for output a file named from the terminal.
 * @param out_f is ofstream
 * @pre None
 * @post A file stream has been opened for output.
 */
void open_output_file(ofstream& out_f);

/** Reads an input value within specified bounds.
 * @param small and large are two integers
 * @pre small and large are positive integers, with small <= large.
 * @post The function returns a value in [small, large] entered from the terminal.
 */
int read_int(int small, int large);

int main()
{
    ifstream in_file;    // The input file stream
    ofstream out_file;   // The output file stream
    int max_length;      // Maximum line length
    char s[MAX + 1];     // Each string read in and printed out
    int s_len;           // The length of the string s
    int line_len;        // The length of the current output line so far

    open_input_file(in_file);
    open_output_file(out_file);
    max_length = read_int(MIN, MAX);

    line_len = 0;
    in_file >> s;
    while (!in_file.eof())
    {
        s_len = strlen(s);
        if (line_len + s_len <= max_length)
        {
            out_file << s;
            line_len = line_len + s_len;
        }
        else
        {
            out_file << endl << s;
            line_len = s_len;
        }

        if (line_len < max_length)
        {
            out_file << ' ';
            ++line_len;
        }
        in_file >> s;
    }
    out_file << endl;
    in_file.close();
    out_file.close();

    return EXIT_SUCCESS;
}

void open_input_file(ifstream& in_f)
{
    char input_file_name[80];
    do {
        in_f.clear();
        cout << "Enter input file name: ";
        cin >> input_file_name;
        in_f.open(input_file_name);
    } while (in_f.fail());
}

void open_output_file(ofstream& out_f)
{
    char output_file_name[80];
    do {
        out_f.clear();
        cout << "Enter output file name: ";
        cin >> output_file_name;
        out_f.open(output_file_name);
    } while (out_f.fail());
}

int read_int(int small, int large)
{
    int value;
    do {
        cout << "Enter an integer value between " << setw(1) << small
             << " and " << setw(1) << large << ": ";
        cin >> value;
    } while (value < small || value > large);
    return value;
}
```

---

### 3. User Document

Formatting text is arranging it on the screen or page. The program `format` is a text formatter. It reads a file of text and prints a new file containing the same text, but formatted into lines no longer than a maximum length. The user enters the names of the input and output files and the maximum line length, which must fall between 30 and 80. The program inserts line breaks in the white space between words, which are defined to be blocks of contiguous non-blank characters.

The program's name is `format.cpp`. It is located at the following directory on CentOS:

```
/home/STCLOUDSTATE/jq4933kt/CSCI301/Project3
```

To compile and link it, simply enter:

```
g++ -o format format.cpp
```

To run the program, enter `format`, then respond to the program's prompts to specify the input and output files and the maximum line length. The program will continue to prompt for input should it be unable to open a file or should the entered maximum line length not fall between 30 and 80. The program assumes that no word is longer than the entered line length.

For example, if an input file called `inp.dat` contains this text:

```
The puzzle was invented by the French mathematician Edouard Lucas in 1883. There
is a legend about a Vietnamese temple which contains a large room with three
time-worn posts in it surrounded by 64 golden disks. The priests of Hanoi,
acting out the command of an ancient prophecy, have been moving these disks, in
accordance with the rules of the puzzle, since that time. The puzzle is therefore
also known as the Tower of Brahma puzzle.
```

The following exchange will run the program on this file:

```
prompt> format
Enter input file name: inp.dat
Enter output file name: outp.dat
Enter an integer value between 30 and 80: 80
```

When the program terminates, the output file `outp.dat` will contain the text formatted so that no line exceeds 80 characters.

---

### 4. Test Data Plan

Your test data should contain the following sections:

**(a) Valid input values** — reasons to choose these values, and expected results

**(b) Boundary input values** (if applicable) — reasons to choose these values, and expected results

**(c) Invalid input values** — reasons to choose these values, and expected results

#### Example Test Plan

**Valid Input Values**

| Input                        | Value    | Expected Output              |
|------------------------------|----------|------------------------------|
| A number between 30 and 80   | 60       | Formatted output file        |
| Input file name              | inp.dat  | No message                   |
| Output file name             | oup.dat  | No message                   |

**Boundary Values**

| Input                        | Value    | Expected Output              |
|------------------------------|----------|------------------------------|
| A number between 30 and 80   | 80       | Formatted output file        |
| Input file name              | inp.dat  | No message                   |
| Output file name             | oup.dat  | No message                   |

| Input                        | Value    | Expected Output              |
|------------------------------|----------|------------------------------|
| A number between 30 and 80   | 30       | Formatted output file        |
| Input file name              | inp.dat  | No message                   |
| Output file name             | oup.dat  | No message                   |

**Invalid Input Values**

| Input                        | Value        | Expected Output              |
|------------------------------|--------------|------------------------------|
| A number between 30 and 80   | 85           | Error message                |
| Input file name              | inp.dat      | —                            |
| Output file name             | oup.dat      | —                            |

| Input                        | Value        | Expected Output              |
|------------------------------|--------------|------------------------------|
| A number between 30 and 80   | 25           | Error message                |
| Input file name              | inp.dat      | —                            |
| Output file name             | oup.dat      | —                            |

| Input                        | Value        | Expected Output              |
|------------------------------|--------------|------------------------------|
| A number between 30 and 80   | 70           | —                            |
| Input file name              | inputFile.dat | Error message               |
| Output file name             | oup.dat      | —                            |

---

### 5. Summary

In this project we implemented a program that formats input text into lines no longer than a maximum length. The program reads from and writes to both the terminal and files. Because it manipulates text, it uses a string type (an array of characters) and string functions from the `<cstring>` library.

Because the program uses functions to read the file names and open the input and output files, it illustrates passing file streams as parameters. Because these functions each continue to prompt for a file name when the named file cannot be opened, they also illustrate the use of the `ifstream` and `ofstream` member functions `fail()`, which return `true` if a file operation such as opening a file fails.

The program could be extended in several ways that would make it more useful as a text formatter. These include:
- Writing two blanks, rather than one, when a string ends in a period
- Treating blank lines in the input file as paragraph indicators and formatting the output text to indicate the start of a paragraph
- Indenting the beginnings of paragraphs a specified number of spaces
