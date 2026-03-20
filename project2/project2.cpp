/**
 * @file project2.cpp
 * @brief Application driver for an e-commerce shopping cart simulation.
 *
 * Problem: Collect user-selected items, support cart modifications, and print totals.
 * StartID and Name: <YOUR_STARTID_AND_NAME>
 * Due Date: <DUE_DATE>
 * Instructor: <INSTRUCTOR_NAME>
 * Comments: Interactive mode runs by default. Compile with DEBUG flags to run tests.
 */
// Uncomment to run unit tests on the Item class
#ifndef DEBUG_ITEM
#define DEBUG_ITEM 0
#endif

// Uncomment to run unit tests on the ShoppingCart class
#ifndef DEBUG_CART
#define DEBUG_CART 0
#endif

#define DEBUG (DEBUG_ITEM | DEBUG_CART)

// Limit the prompt loop so it doesn't get stuck
#define MAX_PROMPTS 999

#define EQUALS_YES(input) ((input == "y") || (input == "Y"))

#include "Item.h"
#include "ShoppingCart.h"
#include "debug.h"
#include <sstream> // Required for istringstream
#include <iomanip>

#ifdef SHOPPINGCART_H_

/**
 * @brief Reads one item from standard input.
 * @return Item built from name, unit price, and quantity.
 */
Item get_item_from_input() {
    std::string name;
    float price;
    int quantity;

    std::cin >> name;
    std::cin >> price;
    std::cin >> quantity;
    return Item(name, price, quantity);
}

/**
 * @brief Prompts user to add initial cart items.
 * @param cart Shopping cart being populated.
 */
void prompt_for_items(ShoppingCart& cart) {
    std::string prompt_response;

    int attempts = 0;
    while (attempts++ < MAX_PROMPTS) {
        cart.add(get_item_from_input());

        std::cout << "Want to continue? [y/n]";
        std::cin >> prompt_response;

        if (!(EQUALS_YES(prompt_response))) {
            return;
        }
    }
}

/** @brief Prompts for and adds one item to cart. */
void prompt_add_cart(ShoppingCart& cart) {
    std::cout << "Enter the item to add as the following order:" << std::endl;
    std::cout << "name unitPrice quantity" << std::endl;
    Item item = get_item_from_input();
    if (cart.add(item)) {
        std::cout << "The item has been added." << std::endl;
    }
    else {
        std::cerr << "Failed to add the item!" << std::endl;
    }
}

/** @brief Prompts for and removes one item from cart. */
void prompt_remove_cart(ShoppingCart& cart) {
    std::cout << "Enter the item to be removed as the following order:" << std::endl;
    std::cout << "name unitPrice quantity" << std::endl;
    Item item = get_item_from_input();

    if (cart.remove(item)) {
        std::cout << "The item has been removed." << std::endl;
    }
    else {
        std::cerr << "No such item in your shopping cart!" << std::endl;
    }
}

/**
 * @brief Prompts for an item and replaces its quantity with a new value.
 * @param cart Shopping cart to modify.
 */
void prompt_change_quantity_cart(ShoppingCart& cart) {
    std::cout << "Enter the item to change as the following order:" << std::endl;
    std::cout << "name unitPrice quantity" << std::endl;
    Item item = get_item_from_input();

    if (!cart.remove(item)) {
        std::cerr << "No such item in your shopping cart!" << std::endl;
        return;
    }

    int prompt_response;
    int attempts = 0;
    while (attempts++ < MAX_PROMPTS) {
        std::cout << "Enter a new quantity --> ";
        std::cin >> prompt_response;
        if (prompt_response < 0) {
            std::cerr << prompt_response << " is not a valid input." << std::endl;
        }
        else {
            item.set_quantity(prompt_response);
            cart.add(item);
            std::cout << "The quantity has been modified." << std::endl;
            return;
        }
    }
}

/**
 * @brief Repeatedly prompts user for cart modifications until they decline.
 * @param cart Shopping cart to modify.
 */
void prompt_modify(ShoppingCart& cart) {
    int attempts = 0;
    while (attempts++ < MAX_PROMPTS) {
        std::string prompt_string_response;
        int prompt_int_response;

        std::cout << "Want to modify your order? y/n" << std::endl;
        std::cin >> prompt_string_response;
        if (!EQUALS_YES(prompt_string_response)) {
            return;
        }

        std::cout << "What do you want? Enter 1: add 2: remove 3: change quantity" << std::endl;
        std::cin >> prompt_int_response;

        switch (prompt_int_response)
        {
        case 1:
            prompt_add_cart(cart);
            break;
        case 2:
            prompt_remove_cart(cart);
            break;
        case 3:
            prompt_change_quantity_cart(cart);
            break;
        default:
            std::cerr << prompt_int_response << " is not a valid option. Please choose between 1 and 3." << std::endl;
            break;
        }

    }
}

#define NAME_COL_WIDTH 25
#define PRICE_COL_WIDTH 15
#define QUANTITY_COL_WIDTH 10

/**
 * @brief Prints cart contents in table format.
 * @param cart Shopping cart to display.
 * @param final If true, prints final thank-you message.
 */
void print_cart(ShoppingCart& cart, bool final = false) {
    
    std::cout << "\n----------------------------------------------------------------\n" << std::endl;
    std::cout << "You have ordered the following items:" << std::endl;
    std::cout << std::left
              << std::setw(NAME_COL_WIDTH) << "Name"
              << std::setw(PRICE_COL_WIDTH) << "Unit_Price"
              << std::setw(QUANTITY_COL_WIDTH) << "Quantity"
			  << std::endl;
    
    std::cout << std::fixed << std::setprecision(2);
    std::vector<Item> vec = cart.toVector();
    for (size_t i = 0; i < vec.size(); i++) {
        Item item = vec.at(i);
        std::cout << std::left
                  << std::setw(NAME_COL_WIDTH) << item.get_name()
                  << "$" << std::setw(PRICE_COL_WIDTH - 1) << item.get_price()
                  << std::setw(QUANTITY_COL_WIDTH) << item.get_quantity()
			      << std::endl;
    }

    std::cout << "\nThe total charge is $" << cart.get_totalPrice() << std::endl;
    if (final) {
        std::cout << "Thanks for shopping at TheMasonX's SHOPPING CENTER." << std::endl;
    }

	std::cout << "\n----------------------------------------------------------------\n" << std::endl;
}

#endif

/** @brief Program entry point. */
int main()
{
#if DEBUG
    return run_tests();
#endif // DEBUG
    ShoppingCart cart;

    std::cout << "Welcome to TheMasonX's SHOPPING CENTER." << std::endl;
    std::cout << "Enter the item you selected as the following order:" << std::endl;
    std::cout << "name unitPrice quantity" << std::endl;
    std::cout << "(Name can not contain any space. Otherwise errors happen!)" << std::endl;

    prompt_for_items(cart);

    std::cout << "Here is your order:" << std::endl;
    print_cart(cart);

    prompt_modify(cart);

    std::cout << "Here is your updated order:" << std::endl;
    print_cart(cart, true);
}