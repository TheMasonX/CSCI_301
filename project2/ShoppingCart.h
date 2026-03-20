/**
 * @file ShoppingCart.h
 * @brief Declares ShoppingCart, a Bag-derived cart that tracks total price.
 *
 * Problem: Support add/remove/clear cart operations while maintaining a total.
 * StartID and Name: <YOUR_STARTID_AND_NAME>
 * Due Date: <DUE_DATE>
 * Instructor: <INSTRUCTOR_NAME>
 * Comments: ShoppingCart derives publicly from Bag<Item> per assignment.
 */
#ifndef SHOPPINGCART_H_
#define SHOPPINGCART_H_

#include "Item.h"
#include "Bag.h"

class ShoppingCart : public Bag<Item> {
    float totalPrice;

public:
    /** @brief Constructs an empty shopping cart with zero total price. */
    ShoppingCart();
    
    /** @brief Returns the current total charge for all items in the cart. */
    float get_totalPrice() const;

    /**
     * @brief Adds an item to the cart and updates total price on success.
     * @param newEntry Item to add.
     * @return True if item is added to underlying bag.
     */
    bool add(const Item& newEntry);

	/**
	 * @brief Removes an item from the cart and updates total price on success.
	 * @param anEntry Item to remove.
	 * @return True if item is removed from underlying bag.
	 */
	bool remove(const Item& anEntry);

	/** @brief Clears cart contents and resets total price to zero. */
	void clear();
};

#include "ShoppingCart.cpp"
#endif // SHOPPINGCART_H_