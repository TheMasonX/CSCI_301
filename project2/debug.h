#ifndef DEBUG_H_
#define DEBUG_H_

#include <iostream> // Required for istringstream
#include <sstream> // Required for istringstream

#define SEPARATOR "\n=================================================\n"

#define PRINT_RES(msg, actual, expected) msg << " returned: " << actual << ". Expected: " << expected << std::endl;
#define PRINT_PASS(msg, actual, expected) std::cout << "PASS: " << PRINT_RES(msg, actual, expected)
#define PRINT_FAIL(msg, actual, expected) std::cerr << "FAIL: " << PRINT_RES(msg, actual, expected)
#define ASSERT(condition, msg, actual, expected) if (condition) { PRINT_PASS(msg, actual, expected) } \
                                                 else { passed = false; PRINT_FAIL(msg, actual, expected) }

#define ASSERT_EQUAL(msg, actual, expected) ASSERT(actual == expected, msg, actual, expected)
#define ASSERT_NOT_EQUAL(msg, actual, expected) ASSERT(!(actual == expected), msg, actual, expected)

#define ASSERT_TRUE(msg, actual) ASSERT_EQUAL(msg, actual, true)
#define ASSERT_FALSE(msg, actual) ASSERT_EQUAL(msg, actual, false)

#if DEBUG_ITEM
#include "Item.h"

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

    Item actual_item;
    test_istream >> actual_item;
    test_ostream << actual_item;

    std::string actual_name = actual_item.get_name();
    ASSERT_EQUAL("Item.get_name()", actual_name, test_name)

    float actual_price = actual_item.get_price();
    ASSERT_EQUAL("Item.get_price()", actual_price, test_price)

    int actual_quantity = actual_item.get_quantity();
    ASSERT_EQUAL("Item.get_quantity()", actual_quantity, test_quantity)

    std::string actual_output_string = test_ostream.str();
    ASSERT_EQUAL("<< operator", actual_output_string, test_output_string);

    return passed;
}

bool test_item_constructor() {
    bool passed = true;

    // Declare the expected values
    std::string test_name("T-Shirt");
    float test_price(19.99);
    int test_quantity(42);

    Item actual_item(test_name, test_price, test_quantity);

    std::string actual_name = actual_item.get_name();
    ASSERT_EQUAL("Item.get_name()", actual_name, test_name)

    float actual_price = actual_item.get_price();
    ASSERT_EQUAL("Item.get_price()", actual_price, test_price)

    int actual_quantity = actual_item.get_quantity();
    ASSERT_EQUAL("Item.get_quantity()", actual_quantity, test_quantity)

    return passed;
}

bool test_item_setter() {
    bool passed = true;

    // Declare the expected values
    std::string test_name("T-Shirt");
    float test_price(19.99);
    int test_quantity(42);

    Item actual_item;
    Item test_item(test_name, test_price, test_quantity);
    ASSERT_NOT_EQUAL("== operator", actual_item, test_item);

    actual_item.set_name(test_name);
    std::string actual_name = actual_item.get_name();
    ASSERT_EQUAL("Item.get_name()", actual_name, test_name);

    actual_item.set_price(test_price);
    float actual_price = actual_item.get_price();
    ASSERT_EQUAL("Item.get_price()", actual_price, test_price);

    actual_item.set_quantity (test_quantity);
    int actual_quantity = actual_item.get_quantity();
    ASSERT_EQUAL("Item.get_quantity()", actual_quantity, test_quantity);

    ASSERT_EQUAL("== operator", actual_item, test_item);

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

#if DEBUG_CART

#include "ShoppingCart.h"

bool test_cart_add() {
    bool passed = true;

    std::string item_name = "T-Shirt";
    float item_price = 19.99;
    int item_quantity = 42;
    Item test_item(item_name, item_price, item_quantity);
    ShoppingCart test_cart;

    int initial_total = test_cart.get_totalPrice();
    ASSERT_EQUAL("initial ShoppingCart.get_totalPrice()", initial_total, 0)

    int initial_size = test_cart.getCurrentSize();
    ASSERT_EQUAL("initial ShoppingCart.getCurrentSize()", initial_size, 0)

    bool added = test_cart.add(test_item);
    ASSERT_TRUE("ShoppingCart.add(item)", added)
    
    int actual_size = test_cart.getCurrentSize();
    int expected_size = 1;
    ASSERT_EQUAL("after adding, ShoppingCart.getCurrentSize()", actual_size, expected_size)

    float actual_total = test_cart.get_totalPrice();
    ASSERT_EQUAL("after adding, ShoppingCart.getCurrentSize()", actual_total, item_price)

    return passed;
}

bool test_cart_remove() {
    bool passed = true;
    
    std::string item_name = "T-Shirt";
    float item_price = 19.99;
    int item_quantity = 42;
    Item test_item(item_name, item_price, item_quantity);
    ShoppingCart test_cart;
    test_cart.add(test_item);
    float total_before = test_cart.get_totalPrice();
    ASSERT_EQUAL("ShoppingCart.getCurrentSize() before removal", total_before, item_price)

    // Exists in cart
    bool removed = test_cart.remove(test_item);
    ASSERT_TRUE("ShoppingCart.remove(item) first removal", removed)

    // DNE in cart
    bool removed_again = test_cart.remove(test_item);
    ASSERT_FALSE("ShoppingCart.remove(item) second removal", removed_again)

    return passed;
}

bool test_cart_change() {
    bool passed = true;
    
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

#if DEBUG_ITEM
    result += run_item_tests();
#endif // DEBUG_ITEM

#if DEBUG_CART
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