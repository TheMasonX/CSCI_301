#include <iostream>
#include "newfraction1.h"

int main() {

    std::cout << "Enter the first fraction (numerator and denominator): ";
    fraction f1;
    std::cin >> f1;

    std::cout << "Enter the second fraction (numerator and denominator): ";
    fraction f2;
    std::cin >> f2;

    std::cout << "The two fractions entered are:" << std::endl;
    std::cout << "f1 = " << f1 << std::endl;
    std::cout << "f2 = " << f2 << std::endl;

    fraction sum = add(f1, f2);
    std::cout << "f1 + f2 = " << sum << std::endl;

    fraction diff = subtract(f1, f2);
    std::cout << "f1 - f2 = " << diff << std::endl;

    fraction prod = multiply(f1, f2);
    std::cout << "f1 * f2 = " << prod << std::endl;

    fraction quot = divide(f1, f2);
    std::cout << "f1 / f2 = " << quot << std::endl;

    return 0;
}