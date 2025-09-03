#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << std::endl;
    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (std::cin.eof() || command == "EXIT")
        {
            std::cout << std::endl;
            break ;
        }
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else
            std::cout << "Invalid command.\n";
    }
    return EXIT_SUCCESS;
}
