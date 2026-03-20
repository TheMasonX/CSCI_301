#ifndef SHOPPINGCART_H_
#define SHOPPINGCART_H_

#include "Item.h"
#include "Bag.h"

class ShoppingCart : public Bag<Item> {
    float totalPrice;

public:
    ShoppingCart();
    
    float get_totalPrice() const;
    bool add(const Item& newEntry);
	bool remove(const Item& anEntry);
	void clear();
};

// #include "ShoppingCart.cpp"
#endif // SHOPPINGCART_H_