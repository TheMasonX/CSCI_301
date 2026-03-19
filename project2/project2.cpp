#include "Item.h"
#include <sstream> // Required for istringstream

#define SEPARATOR "\n=================================================\n"

#define DEBUG

#ifdef DEBUG

bool test_item_streams()
{
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
    if (actual_name != test_name)
    {
        passed = false;
        std::cerr << "FAIL: item.get_name() returned: " << actual_name
                  << ". Expected: " << test_name << std::endl;
    }
    else
    {
        std::cout << "PASS: item.get_name() returned: " << actual_name
                  << ". Expected: " << test_name << std::endl;
    }

    float actual_price = item.get_price();
    if (actual_price != test_price)
    {
        passed = false;
        std::cerr << "FAIL: item.get_price() returned: " << actual_price
                  << ". Expected: " << test_price << std::endl;
    }
    else
    {
        std::cout << "PASS: item.get_price() returned: " << actual_price
                  << ". Expected: " << test_price << std::endl;
    }

    int actual_quantity = item.get_quantity();
    if (actual_quantity != test_quantity)
    {
        passed = false;
        std::cerr << "FAIL: item.get_quantity() returned: " << actual_quantity
                  << ". Expected: " << test_quantity << std::endl;
    }
    else
    {
        std::cout << "PASS: item.get_quantity() returned: " << actual_quantity
                  << ". Expected: " << test_quantity << std::endl;
    }

    std::string actual_output_string = test_ostream.str();
    if (actual_output_string != test_output_string)
    {
        passed = false;
        std::cout << "FAIL: << operator returned: " << actual_output_string
                  << ". Expected: " << test_output_string << std::endl;
    }
    else
    {
        std::cout << "PASS: << operator returned: " << actual_output_string
                  << ".\nExpected: " << test_output_string << std::endl;
    }

    return passed;
}

bool test_item_constructor()
{
    bool passed = true;

    // Declare the expected values
    std::string test_name("T-Shirt");
    float test_price(19.99);
    int test_quantity(42);

    Item item(test_name, test_price, test_quantity);

    std::string actual_name = item.get_name();
    if (actual_name != test_name)
    {
        passed = false;
        std::cerr << "FAIL: item.get_name() returned: " << actual_name
                  << ". Expected: " << test_name << std::endl;
    }
    else
    {
        std::cout << "PASS: item.get_name() returned: " << actual_name
                  << ". Expected: " << test_name << std::endl;
    }

    float actual_price = item.get_price();
    if (actual_price != test_price)
    {
        passed = false;
        std::cerr << "FAIL: item.get_price() returned: " << actual_price
                  << ". Expected: " << test_price << std::endl;
    }
    else
    {
        std::cout << "PASS: item.get_price() returned: " << actual_price
                  << ". Expected: " << test_price << std::endl;
    }

    int actual_quantity = item.get_quantity();
    if (actual_quantity != test_quantity)
    {
        passed = false;
        std::cerr << "FAIL: item.get_quantity() returned: " << actual_quantity
                  << ". Expected: " << test_quantity << std::endl;
    }
    else
    {
        std::cout << "PASS: item.get_quantity() returned: " << actual_quantity
                  << ". Expected: " << test_quantity << std::endl;
    }

    return passed;
}

bool test_item_setter()
{
    bool passed = true;

    // Declare the expected values
    std::string test_name("T-Shirt");
    float test_price(19.99);
    int test_quantity(42);

    Item item;
    Item test_item(test_name, test_price, test_quantity);
    if (item == test_item)
    {
        passed = false;
        std::cerr << "FAIL: == operator returned: true"
                  << ". Expected: false" << std::endl;
    }
    else
    {
        std::cout << "PASS: == operator returned: false"
                  << ". Expected: false" << std::endl;
    }

    item.set_name(test_name);
    std::string actual_name = item.get_name();
    if (actual_name != test_name)
    {
        passed = false;
        std::cerr << "FAIL: item.get_name() returned: " << actual_name
                  << ". Expected: " << test_name << std::endl;
    }
    else
    {
        std::cout << "PASS: item.get_name() returned: " << actual_name
                  << ". Expected: " << test_name << std::endl;
    }

    item.set_price(test_price);
    float actual_price = item.get_price();
    if (actual_price != test_price)
    {
        passed = false;
        std::cerr << "FAIL: item.get_price() returned: " << actual_price
                  << ". Expected: " << test_price << std::endl;
    }
    else
    {
        std::cout << "PASS: item.get_price() returned: " << actual_price
                  << ". Expected: " << test_price << std::endl;
    }

    item.set_quantity (test_quantity);
    int actual_quantity = item.get_quantity();
    if (actual_quantity != test_quantity)
    {
        passed = false;
        std::cerr << "FAIL: item.get_quantity() returned: " << actual_quantity
                  << ". Expected: " << test_quantity << std::endl;
    }
    else
    {
        std::cout << "PASS: item.get_quantity() returned: " << actual_quantity
                  << ". Expected: " << test_quantity << std::endl;
    }

    if (item == test_item)
    {
        std::cout << "PASS: == operator returned: true"
                  << ". Expected: true" << std::endl;
    }
    else
    {
        passed = false;
        std::cerr << "FAIL: == operator returned: false"
                  << ". Expected: true" << std::endl;
    }

    return passed;
}

int run_tests()
{
    if (!test_item_streams())
    {
        std::cerr << "test_item_streams() failed!" << std::endl;
        return 1;
    }

    std::cout << SEPARATOR << std::endl;

    if (!test_item_constructor())
    {
        std::cerr << "test_item_constructor() failed!" << std::endl;
        return 1;
    }

    std::cout << SEPARATOR << std::endl;

    if (!test_item_setter())
    {
        std::cerr << "test_item_setter() failed!" << std::endl;
        return 1;
    }

    std::cout << SEPARATOR;
    std::cout << "             ALL TESTS PASSED!";
    std::cout << SEPARATOR;
    return 0;
}

#endif // DEBUG

int main()
{
#ifdef DEBUG
    return run_tests();
#endif // DEBUG
}