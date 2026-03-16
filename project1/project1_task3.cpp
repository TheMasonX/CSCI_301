/* CSCI 301 - Project 1: Fraction Class
 * @author:     Luke Norr
 * @email:      norrtec@gmail.com
 * @star_id:    lx8454qp
 * @due_date:   2026-03-14
 * @instructor: Jie Meichsner
 * @problem:    Implement a fraction class with the following features:
 *              - Constructors
 *              - Accessors and mutators for numerator and denominator
 *              - Display function to print the fraction in the form "numerator/denominator"
 *              - Arithmetic operations: addition, subtraction, multiplication, and division of fractions
 *              - Overload the arithmetic operators (+, -, *, /) to allow for natural syntax when performing operations on fractions
 *              - Overload the stream insertion operator (<<) to allow for easy output of fractions using std::cout
 *
 *              The class should be able to handle basic arithmetic operations on fractions and display them correctly.
*/

#include <iostream>
#include "newfraction2.h"

int main() {
    std::cout << "Enter the first fraction (numerator and denominator): ";
    fraction f1;
    std::cin >> f1;

    std::cout << "Enter the second fraction (numerator and denominator): ";
    fraction f2;
    std::cin >> f2;

    std::cout << "\nThe two fractions entered are:" << std::endl;
    std::cout << "f1 = " << f1 << std::endl;
    std::cout << "f2 = " << f2 << std::endl;

    std::cout << "\nThe arithmetic operations on these two fractions:" << std::endl;
    fraction sum = f1 + f2;
    std::cout << "f1 + f2 = " << sum << std::endl;

    fraction diff = f1 - f2;
    std::cout << "f1 - f2 = " << diff << std::endl;

    fraction prod = f1 * f2;
    std::cout << "f1 * f2 = " << prod << std::endl;

    fraction quot = f1 / f2;
    std::cout << "f1 / f2 = " << quot << std::endl;

    return 0;
}