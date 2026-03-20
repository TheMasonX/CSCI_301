/**
 * @file ShoppingCart.cpp
 * @brief Implements ShoppingCart operations.
 */
#include "ShoppingCart.h"

#ifndef SHOPPINGCART_CPP_
#define SHOPPINGCART_CPP_

inline ShoppingCart::ShoppingCart() : totalPrice(0) { }

inline float ShoppingCart::get_totalPrice() const { return totalPrice; }

inline bool ShoppingCart::add(const Item& newEntry) {
    bool added = Bag<Item>::add(newEntry);
    if (added) {
        totalPrice += newEntry.get_price() * newEntry.get_quantity();
    }
    return added;
}

inline bool ShoppingCart::remove(const Item& anEntry) {
    bool removed = Bag<Item>::remove(anEntry);
    if (removed) {
        totalPrice -= anEntry.get_price() * anEntry.get_quantity();
    }
    return removed;
}

inline void ShoppingCart::clear() {
    totalPrice = 0;
    Bag<Item>::clear();
}

#endif // SHOPPINGCART_CPP_