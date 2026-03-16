#include "fraction.h"

fraction::fraction(int num, int denom) : numerator(num), denominator(denom) {}

int fraction::get_denominator() const { return denominator; }
void fraction::set_denominator(int denom) { denominator = denom; }

void fraction::set_numerator(int num) { numerator = num; }
int fraction::get_numerator() const { return numerator; }

void fraction::display() const {
    std::cout << numerator << "/" << denominator << std::endl;
}