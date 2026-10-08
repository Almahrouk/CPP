#include <iostream>
#include <string>
#include "Array.hpp"

template <typename T>
void printArray(const Array<T>& arr)
{
    for (unsigned int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    std::cout << "===== 1. Empty array =====" << std::endl;
    Array<int> empty;
    std::cout << "Size: " << empty.size() << std::endl;
    try
    {
        std::cout << empty[0] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    // std::cout << "\n===== 2. Array of integers =====" << std::endl;
    // Array<int> numbers(5);
    // std::cout << "Size: " << numbers.size() << std::endl;
    // std::cout << "Default values: ";
    // printArray(numbers);
    // // Modify elements
    // for (unsigned int i = 0; i < numbers.size(); ++i)
    //     numbers[i] = static_cast<int>(i + 1);
    // std::cout << "After modification: ";
    // printArray(numbers);
    // std::cout << "\n===== 3. Array of strings =====" << std::endl;
    // Array<std::string> words(3);
    // words[0] = "Hello";
    // words[1] = "World";
    // words[2] = "Array";
    // std::cout << "Size: " << words.size() << std::endl;
    // std::cout << "Contents: ";
    // printArray(words);
    // std::cout << "\n===== 4. Copy constructor =====" << std::endl;
    // Array<int> original(3);
    // original[0] = 10;
    // original[1] = 20;
    // original[2] = 30;
    // Array<int> copy(original);
    // std::cout << "Original: ";
    // printArray(original);
    // std::cout << "Copy:     ";
    // printArray(copy);
    // // Modify original
    // original[0] = 999;
    // std::cout << "\nAfter modifying original:" << std::endl;
    // std::cout << "Original: ";
    // printArray(original);
    // std::cout << "Copy:     ";
    // printArray(copy);
    // std::cout << "The copy should still contain 10 20 30." << std::endl;
    // std::cout << "\n===== 5. Assignment operator =====" << std::endl;
    // Array<int> a(3);
    // a[0] = 1;
    // a[1] = 2;
    // a[2] = 3;
    // Array<int> b(1);
    // b[0] = 100;
    // std::cout << "Before assignment:" << std::endl;
    // std::cout << "A: ";
    // printArray(a);
    // std::cout << "B: ";
    // printArray(b);
    // b = a;
    // std::cout << "\nAfter B = A:" << std::endl;
    // std::cout << "A: ";
    // printArray(a);
    // std::cout << "B: ";
    // printArray(b);
    // // Modify B
    // b[0] = 999;
    // std::cout << "\nAfter modifying B:" << std::endl;
    // std::cout << "A: ";
    // printArray(a);
    // std::cout << "B: ";
    // printArray(b);
    // std::cout << "A should still contain 1 2 3." << std::endl;
    // std::cout << "\n===== 6. Out-of-bounds access =====" << std::endl;
    // Array<int> test(5);
    // try
    // {
    //     std::cout << "Accessing test[5]..." << std::endl;
    //     std::cout << test[5] << std::endl;
    // }
    // catch (const std::exception& e)
    // {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }
    // try
    // {
    //     std::cout << "Accessing test[100]..." << std::endl;
    //     std::cout << test[100] << std::endl;
    // }
    // catch (const std::exception& e)
    // {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }
    // std::cout << "\n===== 7. Negative index =====" << std::endl;
    // try
    // {
    //     std::cout << "Accessing test[-1]..." << std::endl;
    //     std::cout << test[-1] << std::endl;
    // }
    // catch (const std::exception& e)
    // {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }
    // std::cout << "\n===== 8. Const array =====" << std::endl;
    // const Array<int> constArray(numbers);
    // std::cout << "Size: " << constArray.size() << std::endl;
    // std::cout << "Contents: ";
    // for (unsigned int i = 0; i < constArray.size(); ++i)
    //     std::cout << constArray[i] << " ";
    // std::cout << std::endl;
    // std::cout << "\n===== 9. Different types =====" << std::endl;
    // Array<double> doubles(3);
    // doubles[0] = 1.1;
    // doubles[1] = 2.2;
    // doubles[2] = 3.3;
    // std::cout << "Doubles: ";
    // printArray(doubles);
    // Array<char> chars(4);
    // chars[0] = 'A';
    // chars[1] = 'B';
    // chars[2] = 'C';
    // chars[3] = 'D';
    // std::cout << "Chars: ";
    // printArray(chars);
    std::cout << "\n===== All tests finished =====" << std::endl;
    return 0;
}
