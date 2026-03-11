#include "newfraction1.h"
#include <math.h>

fraction::fraction(int num, int denom) : numerator(num), denominator(denom) {}

int fraction::get_denominator() const { return denominator; }
void fraction::set_denominator(int denom) { denominator = denom; }

void fraction::set_numerator(int num) { numerator = num; }
int fraction::get_numerator() const { return numerator; }

void fraction::display() const { std::cout << this; }

fraction add(const fraction& lhs, const fraction& rhs) {
    int num_l = lhs.get_numerator();
    int denom_l = lhs.get_denominator();
    int num_r = rhs.get_numerator();
    int denom_r = rhs.get_denominator();

    // If the denominators are the same, we can just add the numerators
    if (denom_l == denom_r) {
        return fraction(num_l + num_r, denom_l);
    }
    else if (denom_l % denom_r == 0) {
        // If the left denominator is a multiple of the right, we can just scale the right fraction
        int scale = denom_l / denom_r;
        return fraction(num_l + num_r * scale, denom_l);
    }
    else if (denom_r % denom_l == 0) {
        // If the right denominator is a multiple of the left, we can just scale the left fraction
        int scale = denom_r / denom_l;
        return fraction(num_l * scale + num_r, denom_r);
    }

    int num = num_l * denom_r + num_r * denom_l;
    int denom = denom_l * denom_r;
    return fraction(num, denom);
}

fraction subtract(const fraction& lhs, const fraction& rhs) {
    int num_l = lhs.get_numerator();
    int denom_l = lhs.get_denominator();
    int num_r = rhs.get_numerator();
    int denom_r = rhs.get_denominator();

    // If the denominators are the same, we can just subtract the numerators
    if (denom_l == denom_r) {
        return fraction(num_l - num_r, denom_l);
    }
    else if (denom_l % denom_r == 0) {
        // If the left denominator is a multiple of the right, we can just scale the right fraction
        int scale = denom_l / denom_r;
        return fraction(num_l - num_r * scale, denom_l);
    }
    else if (denom_r % denom_l == 0) {
        // If the right denominator is a multiple of the left, we can just scale the left fraction
        int scale = denom_r / denom_l;
        return fraction(num_l * scale - num_r, denom_r);
    }

    int num = num_l * denom_r - num_r * denom_l;
    int denom = denom_l * denom_r;
    return fraction(num, denom);
}

fraction multiply(const fraction& lhs, const fraction& rhs) {
    int num_l = lhs.get_numerator();
    int denom_l = lhs.get_denominator();
    int num_r = rhs.get_numerator();
    int denom_r = rhs.get_denominator();

    int num = num_l * num_r;
    int denom = denom_l * denom_r;
    return fraction(num, denom);
}

fraction divide(const fraction& lhs, const fraction& rhs) {
    int num_l = lhs.get_numerator();
    int denom_l = lhs.get_denominator();
    int num_r = rhs.get_numerator();
    int denom_r = rhs.get_denominator();

    int num = num_l * denom_r;
    int denom = denom_l * num_r;
    return fraction(num, denom);
}

std::ostream& operator <<(std::ostream& outs, const fraction& source)
// Library facilities used: iostream
{
    outs << source.get_numerator() << "/" << source.get_denominator();
    return outs;
}

std::istream& operator >>(std::istream& ins, fraction& target)
// Library facilities used: iostream
// Friend of: fraction class
{
    ins >> target.numerator >> target.denominator;
    return ins;
}