/**
 * @file Item.h
 * @brief Declares the Item class used by the shopping cart application.
 *
 * Problem: Represent purchasable items with name, unit price, and quantity.
 * StartID and Name: <YOUR_STARTID_AND_NAME>
 * Due Date: <DUE_DATE>
 * Instructor: <INSTRUCTOR_NAME>
 * Comments: Quantity is intentionally ignored in equality checks per project spec.
 */
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
    /** @brief Constructs an empty item. */
    Item();

    /**
     * @brief Constructs an item from all data fields.
     * @param name Item name.
     * @param price Unit price.
     * @param quantity Quantity selected.
     */
    Item(std::string name, float price, int quantity);

    /** @brief Gets the item name. */
    std::string get_name() const;

    /** @brief Sets the item name. */
    void set_name(const std::string name);

    /** @brief Gets the unit price. */
    float get_price() const;

    /** @brief Sets the unit price. */
    void set_price(const float price);

    /** @brief Gets the item quantity. */
    int get_quantity() const;

    /** @brief Sets the item quantity. */
    void set_quantity(const int quantity);

    /**
     * @brief Compares two items by name and price.
     * @param other Item to compare against.
     * @return True when name and price match.
     */
    bool operator == (const Item& other) const;

    /**
     * @brief Reads item fields from input stream in order: name price quantity.
     */
    friend std::istream& operator >> (std::istream& ins, Item& target);
};

/** @brief Writes item fields to an output stream. */
std::ostream& operator << (std::ostream & outs, const Item& source);

#endif // ITEM_H_