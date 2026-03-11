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