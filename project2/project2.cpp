// Uncomment to run unit tests on the Item class
#define DEBUG_ITEM 1

// Uncomment to run unit tests on the ShoppingCart class
#define DEBUG_CART 1

#define DEBUG (DEBUG_ITEM | DEBUG_CART)

// Limit the prompt loop so it doesn't get stuck
#define MAX_ITEM_PROMPTS 999U

constexpr const char* Y = "y";

#include "Item.h"
#include "debug.h"
#include <sstream> // Required for istringstream

void prompt_for_items(ShoppingCart& cart) {
    std::string name;
    float price;
    int quantity;

    std::string prompt_response;

    int attempts = 0;
    while (attempts++ < MAX_ITEM_PROMPTS) {
        std::cin >> name;
        std::cin >> price;
        std::cin >> quantity;

        Item new_item(name, price, quantity);

        std::cout << "Want to continue? [y/n]";
        std::cin >> prompt_response;

        if (prompt_response != "y" && prompt_response != "Y") {
            return;
        }
    }
}

int main()
{
#if DEBUG
    return run_tests();
#endif // DEBUG


std::cout << "Welcome to XXX SHOPPING CENTER." << std::endl;
std::cout << "Enter the item you selected as the following order:" << std::endl;
std::cout << "name unitPrice quantity" << std::endl;
std::cout << "(Name can not contain any space. Otherwise errors happen!)" << std::endl;

std::cout << "Want to continue y/n" << std::endl;


}