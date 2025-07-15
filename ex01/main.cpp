#include "iter.hpp"
#include <iostream>

/*
There are 2 solutions to the const problem:
either explicitly 
*/

//READ
template <typename T>
void printValue(T &val)
{
    std::cout << val << " ";
}

//CHANGE
template <typename T>
void incrementValue(T &val)
{
    val++;
}

int main()
{
    std::cout << "--- 1. Testing with a MODIFIABLE array ---" << std::endl;
    int numbers[] = {10, 20, 30};
    size_t len = 3;

    // Test 1: Modifiable array with a reader function (printValue) -> Should work
    std::cout << "Reading from modifiable array: ";
    iter(numbers, len, printValue<int>);
    std::cout << std::endl;

    // Test 2: Modifiable array with a writer function (incrementValue) -> Should work
    std::cout << "Writing to modifiable array..." << std::endl;
    iter(numbers, len, incrementValue<int>);
    std::cout << "Result after writing:        ";
    iter(numbers, len, printValue<int>);
    std::cout << std::endl
              << std::endl;

    std::cout << "--- 2. Testing with a CONSTANT (read-only) array ---" << std::endl;
    const int const_numbers[] = {100, 200, 300};
    size_t const_len = 3;

    // Test 3: Constant array with a reader function (printValue) -> Should work
    std::cout << "Reading from constant array:   ";
    iter(const_numbers, const_len, printValue<const int>);
    std::cout << std::endl;

    // Test 4: Constant array with a writer function (incrementValue) -> Should FAIL to compile
    // The compiler error proves your iter function respects const-correctness.

    // UNCOMMENT THE LINE BELOW TO SEE THE COMPILER ERROR
    // iter(const_numbers, const_len, incrementValue);

    std::cout << "\nDemonstration complete. If you uncomment the final line, compilation will fail as expected." << std::endl;

    return 0;
}
