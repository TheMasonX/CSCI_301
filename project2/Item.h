#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include <iostream>

class Item {
private:
    std::string name;
    float price;
    int quantity;

public:
    Item();
    Item(std::string name, float price, int quantity);

    std::string get_name() const;
    void set_name(const std::string name);

    float get_price() const;
    void set_price(const float price);

    int get_quantity() const;
    void set_quantity(const int quantity);

    bool operator == (const Item& other) const;

    friend std::istream& operator >> (std::istream& ins, Item& target);
};

std::ostream& operator << (std::ostream & outs, const Item& source);

#endif // ITEM_H_