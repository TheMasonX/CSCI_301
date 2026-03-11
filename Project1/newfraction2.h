#ifndef NEWFRACTION2_H
#define NEWFRACTION2_H

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

    /** ========= OPERATORS ========= */

    /** computes the sum of two fractions
	/* @param p1 and p2 are fractions
	/* @pre None
	/* @post The sum of p1 and p2 is returned.*/
		fraction operator +(const fraction& other);

	/** computes the difference of two fractions
	/* @param p1 and p2 are fractions
	/* @pre None
	/* @post The difference of p1 and p2 is returned.*/
		fraction operator -(const fraction& other);

	/** computes the product of two fractions
	/* @param p1 and p2 are fractions
	/* @pre None
	/* @post The product of p1 and p2 is returned.*/
		fraction operator *(const fraction& other);

	/** computes the quotient of two fractions
	/* @param p1 and p2 are fractions
	/* @pre None
	/* @post The quotient of p1 and p2 is returned.*/
		fraction operator /(const fraction& other);

	/** checks if two fractions are identical
	/* @param p1 and p2 are fractions
	/* @pre None
	/* @post The return value is true if p1 and p2 are identical.*/
		bool operator ==(const fraction& other);

	/** checks if two fractions are not identical
	/* @param fq and f2 are fractions
	/* @pre None
	/* @post The return value is true if p1 and p2 are not identical.*/
		bool operator !=(const fraction& other);
		
	/**Nonmember function */
	/** reads the coordinates of a fraction from the istream
	/* @param ins is the istream, target is a fraction
	/* @pre None
	/* @post The numerator and denominator of target have been 
	/*  read from ins. The return value is the istream ins.*/
	friend std::istream& operator >>(std::istream& ins, fraction& target);

};

/** ========= NONMEMBER FUNCTIONS ========= */

/** Returns the sum of two fractions
 * @param lhs is the first fraction
 * @param rhs is the second fraction
 * @pre None
 * @post None
 * @return the sum of lhs and rhs*/
fraction add(const fraction& lhs, const fraction& rhs);

/** Returns the difference of two fractions
 * @param lhs is the first fraction
 * @param rhs is the second fraction
 * @pre None
 * @post None
 * @return the difference of lhs and rhs*/
fraction subtract(const fraction& lhs, const fraction& rhs);

/** Returns the product of two fractions
 * @param lhs is the first fraction
 * @param rhs is the second fraction
 * @pre None
 * @post None
 * @return the product of lhs and rhs*/
fraction multiply(const fraction& lhs, const fraction& rhs);

/** Returns the quotient of two fractions
 * @param lhs is the first fraction
 * @param rhs is the second fraction
 * @pre None
 * @post None
 * @return the quotient of lhs and rhs*/
fraction divide(const fraction& lhs, const fraction& rhs);

/** writes the numerator and denominator of a fraction to the ostream
/* @param outs is the ostream, source is a fraction
/* @pre None
/* @post the numerator and denominator of source have been written to outs.
/* The return value is the ostream outs.*/
std::ostream& operator <<(std::ostream & outs, const fraction& source);

#endif // NEWFRACTION2_H