#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() : totalPrice(0) {
    Bag<Item>();
}

float ShoppingCart::get_totalPrice() const { return totalPrice; }

bool ShoppingCart::add(const Item& newEntry) {
    totalPrice += newEntry.get_price();
    return Bag<Item>::add(newEntry);
}

bool ShoppingCart::remove(const Item& anEntry) {
    totalPrice -= anEntry.get_price();
    return Bag<Item>::remove(anEntry);
}

void ShoppingCart::clear() {
    totalPrice = 0;
    Bag<Item>::clear();
}