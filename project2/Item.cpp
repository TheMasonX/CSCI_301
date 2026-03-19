#include "Item.h"

Item::Item() : name(""), price(0), quantity(0)
{ }

Item::Item(std::string name, float price, int quantity)
{
    this->name = name;
    this->price = price;
    this->quantity = quantity;
}

std::string Item::get_name() const { return name; }
void Item::set_name(const std::string name) { this->name = name; }

float Item::get_price() const { return price; }
void Item::set_price(const float price) { this->price = price; }

int Item::get_quantity() const { return quantity; }
void Item::set_quantity(const int quantity) { this->quantity = quantity; }

bool Item::operator == (const Item& other) const
{
    return (other.name == name) && (other.price == price);
}

std::istream& operator >> (std::istream& ins, Item& target)
{
    ins >> target.name;
    ins >> target.price;
    ins >> target.quantity;
    return ins;
}

std::ostream& operator << (std::ostream & outs, const Item& source)
{
    return outs << "Name: " << source.get_name() 
                << " | Price: " << source.get_price()
                << " | Quantity: " << source.get_quantity();
}