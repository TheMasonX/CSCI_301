#ifndef DEBUG_H_
#define DEBUG_H_

#include "Item.h"
#include "ShoppingCart.h"
#include <sstream> // Required for istringstream

#define SEPARATOR "\n=================================================\n"

#ifdef DEBUG_ITEM

bool test_item_streams() {
    bool passed = true;

    // Declare the expected values
    std::string test_name("T-Shirt");
    float test_price(19.99);
    int test_quantity(42);

    std::ostringstream test_output;
    test_output << "Name: " << test_name
                << " | Price: " << test_price
                << " | Quantity: " << test_quantity;
    std::string test_output_string = test_output.str();

    // Create an input string to test the istream operator
    std::ostringstream input_string;
    input_string << test_name << " " 
                 << test_price << " " 
                 << test_quantity;

    std::istringstream test_istream(input_string.str());
    std::ostringstream test_ostream;

    Item item;
    test_istream >> item;
    test_ostream << item;

    std::string actual_name = item.get_name();
    if (actual_name != test_name) {
        passed = false;
        std::cerr << "FAIL: item.get_name() returned: " << actual_name
                  << ". Expected: " << test_name << std::endl;
    }
    else {
        std::cout << "PASS: item.get_name() returned: " << actual_name
                  << ". Expected: " << test_name << std::endl;
    }

    float actual_price = item.get_price();
    if (actual_price != test_price) {
        passed = false;
        std::cerr << "FAIL: item.get_price() returned: " << actual_price
                  << ". Expected: " << test_price << std::endl;
    }
    else {
        std::cout << "PASS: item.get_price() returned: " << actual_price
                  << ". Expected: " << test_price << std::endl;
    }

    int actual_quantity = item.get_quantity();
    if (actual_quantity != test_quantity) {
        passed = false;
        std::cerr << "FAIL: item.get_quantity() returned: " << actual_quantity
                  << ". Expected: " << test_quantity << std::endl;
    }
    else {
        std::cout << "PASS: item.get_quantity() returned: " << actual_quantity
                  << ". Expected: " << test_quantity << std::endl;
    }

    std::string actual_output_string = test_ostream.str();
    if (actual_output_string != test_output_string) {
        passed = false;
        std::cout << "FAIL: << operator returned: " << actual_output_string
                  << ". Expected: " << test_output_string << std::endl;
    }
    else {
        std::cout << "PASS: << operator returned: " << actual_output_string
                  << ". Expected: " << test_output_string << std::endl;
    }

    return passed;
}

bool test_item_constructor() {
    bool passed = true;

    // Declare the expected values
    std::string test_name("T-Shirt");
    float test_price(19.99);
    int test_quantity(42);

    Item item(test_name, test_price, test_quantity);

    std::string actual_name = item.get_name();
    if (actual_name != test_name) {
        passed = false;
        std::cerr << "FAIL: item.get_name() returned: " << actual_name
                  << ". Expected: " << test_name << std::endl;
    }
    else {
        std::cout << "PASS: item.get_name() returned: " << actual_name
                  << ". Expected: " << test_name << std::endl;
    }

    float actual_price = item.get_price();
    if (actual_price != test_price) {
        passed = false;
        std::cerr << "FAIL: item.get_price() returned: " << actual_price
                  << ". Expected: " << test_price << std::endl;
    }
    else {
        std::cout << "PASS: item.get_price() returned: " << actual_price
                  << ". Expected: " << test_price << std::endl;
    }

    int actual_quantity = item.get_quantity();
    if (actual_quantity != test_quantity) {
        passed = false;
        std::cerr << "FAIL: item.get_quantity() returned: " << actual_quantity
                  << ". Expected: " << test_quantity << std::endl;
    }
    else {
        std::cout << "PASS: item.get_quantity() returned: " << actual_quantity
                  << ". Expected: " << test_quantity << std::endl;
    }

    return passed;
}

bool test_item_setter() {
    bool passed = true;

    // Declare the expected values
    std::string test_name("T-Shirt");
    float test_price(19.99);
    int test_quantity(42);

    Item item;
    Item test_item(test_name, test_price, test_quantity);
    if (item == test_item) {
        passed = false;
        std::cerr << "FAIL: == operator returned: true"
                  << ". Expected: false" << std::endl;
    }
    else {
        std::cout << "PASS: == operator returned: false"
                  << ". Expected: false" << std::endl;
    }

    item.set_name(test_name);
    std::string actual_name = item.get_name();
    if (actual_name != test_name) {
        passed = false;
        std::cerr << "FAIL: item.get_name() returned: " << actual_name
                  << ". Expected: " << test_name << std::endl;
    }
    else {
        std::cout << "PASS: item.get_name() returned: " << actual_name
                  << ". Expected: " << test_name << std::endl;
    }

    item.set_price(test_price);
    float actual_price = item.get_price();
    if (actual_price != test_price) {
        passed = false;
        std::cerr << "FAIL: item.get_price() returned: " << actual_price
                  << ". Expected: " << test_price << std::endl;
    }
    else {
        std::cout << "PASS: item.get_price() returned: " << actual_price
                  << ". Expected: " << test_price << std::endl;
    }

    item.set_quantity (test_quantity);
    int actual_quantity = item.get_quantity();
    if (actual_quantity != test_quantity) {
        passed = false;
        std::cerr << "FAIL: item.get_quantity() returned: " << actual_quantity
                  << ". Expected: " << test_quantity << std::endl;
    }
    else {
        std::cout << "PASS: item.get_quantity() returned: " << actual_quantity
                  << ". Expected: " << test_quantity << std::endl;
    }

    if (item == test_item) {
        std::cout << "PASS: == operator returned: true"
                  << ". Expected: true" << std::endl;
    }
    else {
        passed = false;
        std::cerr << "FAIL: == operator returned: false"
                  << ". Expected: true" << std::endl;
    }

    return passed;
}

int run_item_tests() {
    if (!test_item_streams()) {
        std::cerr << "test_item_streams() failed!" << std::endl;
        return 1;
    }

    std::cout << SEPARATOR << std::endl;

    if (!test_item_constructor()) {
        std::cerr << "test_item_constructor() failed!" << std::endl;
        return 1;
    }

    std::cout << SEPARATOR << std::endl;

    if (!test_item_setter()) {
        std::cerr << "test_item_setter() failed!" << std::endl;
        return 1;
    }

    return 0;
}

#endif // DEBUG_ITEM

#ifdef DEBUG_CART

bool test_cart_add() {
    bool passed;

    std::string item_name = "T-Shirt";
    float item_price = 19.99;
    int item_quantity = 42;
    Item test_item(item_name, item_price, item_quantity);
    ShoppingCart test_cart;

    int initial_total = test_cart.get_totalPrice();
    if (initial_total == 0) {
        std::cout << "PASS: initial cart total was 0"
                  << ". Expected: 0" << std::endl;
    }
    else {
        passed = false;
        std::cerr << "FAIL: initial cart total was: " << initial_total
                  << ". Expected: 0" << std::endl;
    }

    int initial_size = test_cart.getCurrentSize();
    if (initial_size == 0) {
        std::cout << "PASS: initial cart size was 0"
                  << ". Expected: 0" << std::endl;
    }
    else {
        passed = false;
        std::cerr << "FAIL: initial cart size was: " << initial_size
                  << ". Expected: 0" << std::endl;
    }

    bool added = test_cart.add(test_item);
    if (added) {
        std::cout << "PASS: item was added to cart" << std::endl;
    }
    else {
        passed = false;
        std::cerr << "FAIL: item was not added to cart" << std::endl;
    }
    
    int actual_size = test_cart.getCurrentSize();
    int expected_size = 1;
    if (actual_size == expected_size) {
        std::cout << "PASS: cart size was: " << actual_size
                  << ". Expected: " << expected_size << std::endl;
    }
    else {
        passed = false;
        std::cerr << "FAIL: cart size was: " << actual_size
                  << ". Expected: " << expected_size << std::endl;
    }

    float actual_total = test_cart.get_totalPrice();
    if (actual_total == item_price) {
        std::cout << "PASS: cart total was: " << actual_total
                  << ". Expected: " << item_price << std::endl;
    }
    else {
        passed = false;
        std::cerr << "FAIL: cart total was: " << actual_total
                  << ". Expected: " << item_price << std::endl;
    }

    return passed;
}

bool test_cart_remove() {
    bool passed;
    
    // Exists in cart

    // DNE in cart
    
    return passed;
}

bool test_cart_change() {
    bool passed;
    
    // Exists in cart

    // DNE in cart
    return passed;
}

int run_cart_tests() {
    if (!test_cart_add()) {
        std::cerr << "test_item_streams() failed!" << std::endl;
        return 1;
    }

    std::cout << SEPARATOR << std::endl;

    if (!test_cart_remove()) {
        std::cerr << "test_item_constructor() failed!" << std::endl;
        return 1;
    }

    std::cout << SEPARATOR << std::endl;

    if (!test_cart_change()) {
        std::cerr << "test_item_setter() failed!" << std::endl;
        return 1;
    }

    return 0;
}

#endif // DEBUG_CART

int run_tests() {
    int result = 0;

#ifdef DEBUG_ITEM
    result += run_item_tests();
#endif // DEBUG_ITEM

#ifdef DEBUG_CART
    result += run_cart_tests();
#endif // DEBUG_CART

    if (result == 0) {
        std::cout << SEPARATOR;
        std::cout << "               ALL TESTS PASSED!";
        std::cout << SEPARATOR;
    }
    return result;
}

#endif // DEBUG_H_