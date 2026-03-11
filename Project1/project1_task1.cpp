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
    fraction f1;
    fraction f2(3, 4);

    std::cout << "f1 (original): ";
    f1.display();

    std::cout << "f1 (modified): ";
    f1.set_numerator(1);
    f1.set_denominator(2);
    f1.display();

    std::cout << "f2: ";
    f2.display();

    std::cout << "f2 numerator: " << f2.get_numerator() << std::endl;
    std::cout << "f2 denominator: " << f2.get_denominator() << std::endl;

    return 0;
}