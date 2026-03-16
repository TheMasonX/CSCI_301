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
 *
 *              The class should be able to handle basic arithmetic operations on fractions and display them correctly.
*/

#include <iostream>
#include "newfraction1.h"

int main() {
    std::cout << "Enter the first fraction (numerator and denominator): ";
    int num, denom;
    std::cin >> num >> denom;
    fraction f1(num, denom);

    std::cout << "Enter the second fraction (numerator and denominator): ";
    std::cin >> num >> denom;
    fraction f2(num, denom);

    std::cout << "\nThe two fractions entered are:" << std::endl;
    std::cout << "f1 = ";
    f1.display();
    std::cout << std::endl;
    std::cout << "f2 = ";
    f2.display();
    std::cout << std::endl;

    std::cout << "\nThe arithmetic operations on these two fractions:" << std::endl;
    fraction sum = add(f1, f2);
    std::cout << "f1 + f2 = ";
    sum.display();
    std::cout << std::endl;

    fraction diff = subtract(f1, f2);
    std::cout << "f1 - f2 = ";
    diff.display();
    std::cout << std::endl;

    fraction prod = multiply(f1, f2);
    std::cout << "f1 * f2 = ";
    prod.display();
    std::cout << std::endl;

    fraction quot = divide(f1, f2);
    std::cout << "f1 / f2 = ";
    quot.display();
    std::cout << std::endl;

    return 0;
}