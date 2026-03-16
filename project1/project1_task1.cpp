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
 *
 *              The class should be able to handle basic mutations and accessors for the numerator and denominator, as well as display the fraction correctly.
*/

#include <iostream>
#include "fraction.h"

int main() {
    std::cout << "Enter the first fraction (numerator and denominator): ";
    int num1, denom1;
    std::cin >> num1 >> denom1;

    std::cout << "Enter the second fraction (numerator and denominator): ";
    int num2, denom2;
    std::cin >> num2 >> denom2;

    // Excercise the default constructor and the parameterized constructor
    fraction f1;
    fraction f2(num2, denom2);

    std::cout << "Fraction 1 (default constructor): ";
    f1.display();

    std::cout << "Fraction 1 (set values): ";
    f1.set_numerator(num1);
    f1.set_denominator(denom1);
    f1.display();

    std::cout << "Fraction 2 (parameterized constructor): ";
    f2.display();

    std::cout << "Fraction 2 numerator: " << f2.get_numerator() << std::endl;
    std::cout << "Fraction 2 denominator: " << f2.get_denominator() << std::endl;

    return 0;
}