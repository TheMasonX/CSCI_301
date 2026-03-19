# Project 2 - E-commerce

## Introduction
- In this project, students will use class inheritance to solve a problem.
- Students should produce correct, well-documented, and readable programs in a reasonable amount of time.

## Problem Description
When shopping online, users select items and add them to a shopping cart. Duplicate items are permitted because users may buy multiples of the same item. Users can also remove items from the cart. The shopping cart should display current contents, item prices, and total cost.

Design the ADTs `Item` and `ShoppingCart`.

## Task 1 - `Item` (regular class, not a template)
- Declare three data members:
	- name of item
	- unit price of item
	- quantity of item
- Define a default constructor.
- Define a constructor that initializes all three data members from parameters.
- Define set and get functions for each data member.
- Define the following operators:
	- `==`
		- Two items are considered the same if their name and price are the same.
		- Quantity does not have to be the same.
	- `>>`
	- `<<`
- Test the `Item` class before moving to Task 2.

## Task 2 - `ShoppingCart` (regular class)
Design `ShoppingCart` as a derived class from `Bag` using public inheritance:

```cpp
class ShoppingCart : public Bag<Item>
```

Use the `Bag` class provided in lectures and the textbook. You do not need to create it.

- Declare total price as a data member.
- Define a default constructor.
- Define a member function to get total price.
- Override the base class methods:
	- `add`
	- `remove`
	- `clear`
- Hint: this is similar to `setItem()` in the toyBox class.
- Test the class before moving to the application/testing task.

## Implementation Requirement
- Write and document classes in header and implementation files.
- Compile separately from the client program.
- Add the implementation include at the end of `ShoppingCart.h`:

```cpp
#include "ShoppingCart.cpp"
```

Place this include before `#endif`.

This is required for correct execution on GitHub.

## Testing Requirements
Design test data to cover all `ShoppingCart` operations:
- Add
- Remove:
	- item exists in cart
	- item does not exist in cart
- Change quantity:
	- item exists in cart (validate quantity)
	- item does not exist in cart

A run of this program must look like this:

```text
>g++ project2.cpp

>a.out


Welcome to XXX SHOPPING CENTER.

Enter the item you selected as the following order:

name unitPrice quantity

(Name can not contain any space. Otherwise errors happen!)

--> T-shirt 19.99 2

Want to continue y/n-->y



-->Sweater 39.99 1

Want to continue y/n-->y



-->iphone_case 25.50 3

Want to continue y/n-->y



-->Towel 9.99 5

Want to continue y/n-->n



Here is your order:

-------------------------------------------------

Name                Unit_Price          Quantity

T-shirt               $19.99               2

Sweater               $39.99               2

iphone_case           $25.5                3

Towel                 $9.99                5

The total charge is $246.41

--------------------------------------------------



Want to modify your order? y/n-->y

What do you want? Enter 1: add 2: remove 3: change quantity

--> 1

Enter the item to add as the following order:

name unitPrice quantity

--> shoe 99.99 1

The item has been added.



Want to modify your order? y/n-->y

What do you want? Enter 1: add 2: remove 3: change quantity

--> 2

Enter the item to remove as the following order:

name unitPrice quantity

--> Sweater 29.99 2

No such item in your shopping cart!



Want to modify your order? y/n-->y

What do you want? Enter 1: add 2: remove 3: change quantity

--> 2

Enter the item to remove as the following order:

name unitPrice quantity

--> Sweater 39.99 2

The item has been removed.



Want to modify your order? y/n-->y

What do you want? Enter 1: add 2: remove 3: change quantity

--> 3

Enter the item to change as the following order:

name unitPrice quantity

--> Towel 9.99 5

Enter a new quantity --> -2

-2 is not a valid input.

Enter a new quantity --> 2

The quantity has been modified.



Want to modify your order? y/n-->n



Here is your updated order:

-------------------------------------------------

You have ordered the following items:

Name                Unit_Price          Quantity

T-shirt               $19.99               2

Shoe                  $99.99               1

iphone_case           $25.5                3

Towel                 $9.99                2

The total charge is $236.45

Thanks for shopping in XXX SHOPPING CENTER.

---------------------------------------------------
```

## Other Requirements
For each program, add the following information at the top of the file:
- Description of the problem to solve
- Your startID and name
- Due Date
- Instructor
- Comments

For classes and functions, add necessary documentation/comments using Javadoc-style comments.

References:
- Textbook pages 759-760
- Appendix I on page 809 (7th edition)
- `CSCI 301 - About Programming Assignments` on D2L

## Submission Instructions
- Submit all source programs to your account in GitHub.
- Test your program on GitHub to ensure it works correctly.
- Submit the following to the D2L drop box `Project2`:
	- `bag.h`, `bag.cpp`, `bagInterface.h`
	- Use the Bag class provided in lectures and textbook.
	- `item.h`, `item.cpp`
	- `shoppingCart.h`, `shoppingCart.cpp`
	- The application program that simulates online shopping cart
	- A script file for test runs on GitHub
	- Do not list source code in the script file
	- A Word file containing:
		- a simple UML diagram for `Item`
		- a simple UML diagram for `ShoppingCart`
		- the design document

Note: UML is covered in Chapter 13 of the CSCI 201 textbook. Slides are posted on D2L.

Also include a user document with:
- Description of the problem to solve
- File location on GitHub
- How to compile the program
- How to run the program

Follow the document `CSCI 301 - About Programming Assignments` posted on D2L.

## Grading Rubric
| Requirements                          | points |
|---------------------------------------|--------|
| Comments in the program               | 20     |
| Program correctness                   | 30     |
| Script file from several test runs    | 30     |
| Design document                       | 10     |
| User document                         | 10     |
| TOTAL POINTS                          | 100    |
