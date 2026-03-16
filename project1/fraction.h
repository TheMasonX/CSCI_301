#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class fraction {
private:
    /** The numerator of the fraction */
    int numerator;
    /** The denominator of the fraction */
    int denominator;
public:
    /** Constructor; 
	* @param num the numerator of the fraction
	* @param denom the denominator of the fraction
	* @pre None
	* @post sets the fraction to(num, denom)*/
    fraction(int num = 0, int denom = 1);

    /** ========= MODIFICATION MEMBER FUNCTIONS ========= */

    /** Sets the numerator of the fraction
	* @param num the new numerator of the fraction
	* @pre None
	* @post sets the numerator to num*/
    void set_numerator(int num);

    /** Sets the denominator of the fraction
	* @param denom the new denominator of the fraction
	* @pre None
	* @post sets the denominator to denom*/
    void set_denominator(int denom);

    /** ========= CONSTANT MEMBER FUNCTIONS ========= */
    
    /** Gets the numerator of the fraction
	* @pre None
	* @post None
	* @return the numerator of the fraction*/
    int get_numerator() const;

    /** Gets the denominator of the fraction
	* @pre None
	* @post None
	* @return the denominator of the fraction*/
    int get_denominator() const;

    /** Displays the fraction in the form numerator/denominator
     * @pre None
     * @post None
     * @return None*/
    void display() const;
};

#endif // FRACTION_H