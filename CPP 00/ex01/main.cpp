#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "\n📞 Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (std::cin.eof()) break;

        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "❌ Invalid command.\n";
    }
    return 0;
}

/*
std::basic_istream<_CharT, _Traits> & getline<_CharT, _Traits, _Alloc>(
            std::basic_istream<_CharT, _Traits> &&__is, 
            std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, 
            _CharT __delim)
*/

// #include "PhoneBook.hpp"

// int main()
// {
//     PhoneBook phoneBook;
//     std::string command;

//     while (true)
//     {
//         std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
//         std::getline(std::cin, command);

//         if (command == "ADD")
//         {
//             phoneBook.addContact();
//         }
//         else if (command == "SEARCH")
//         {
//             phoneBook.searchContact();
//         }
//         else if (command == "EXIT")
//         {
//             break;
//         }
//         else
//         {
//             std::cout << "Invalid command. Please try again." << std::endl;
//         }
//     }

//     return 0;
// }