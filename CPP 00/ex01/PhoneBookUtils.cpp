#include "PhoneBook.hpp"

int isInvalidName(std::string input)
{
    int i = 0;
    while(input[i])
    {
        if(input[i] >= '0' && input[i] <= '9')
        {
            std::cerr << "Name field can't contain any number, Try again.\n";
            return 1;
        }
        i++;
    }
    return 0;
}

void PhoneBook::setFirstName(Contact &contact) const
{
    std::string input;
    while (true)
    {
        std::cout << "Enter First Name: ";
        std::getline(std::cin, input);
        if (isInvalidName(input))
            continue;
        if (std::cin.eof()) return ;
        if (!input.empty())
        {
            contact.setFirstName(input);
            break;
        }
        std::cout << "This field cannot be empty. Try again.\n";
    }
}
void PhoneBook::setLastName(Contact &contact) const
{
    std::string input;
    while (true)
    {
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, input);
        if (isInvalidName(input))
            continue;
        if (std::cin.eof()) return ;
        if (!input.empty())
        {
            contact.setLastName(input);
            break;
        }
        std::cout << "This field cannot be empty. Try again.\n";
    }
}
void PhoneBook::setNickName(Contact &contact) const
{
    std::string input;
    while (true)
    {
        std::cout << "Enter Nick Name: ";
        std::getline(std::cin, input);
        if (std::cin.eof()) return ;
        if (!input.empty())
        {
            contact.setNickName(input);
            break;
        }
        std::cout << "This field cannot be empty. Try again.\n";
    }
}

int isInvalidNumber(std::string input)
{
    int i = 0;
    while(input[i])
    {
        if(input[i] < '0' || input[i] > '9')
        {
            std::cerr << "You must input a valid phone number\n";
            return 1;
        }
        i++;
    }
    return 0;
}

void PhoneBook::setPhoneNumber(Contact &contact) const
{
    std::string input;
    while (true)
    {
        std::cout << "Enter Phone Name: ";
        std::getline(std::cin, input);
        if (isInvalidNumber(input))
            continue;
        if (std::cin.eof()) return ;
        if (!input.empty())
        {
            contact.setPhoneNumber(input);
            break;
        }
        std::cout << "This field cannot be empty. Try again.\n";
    }
}
void PhoneBook::setDarkestSecret(Contact &contact) const
{
    std::string input;
    while (true)
    {
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, input);
        if (std::cin.eof()) return ;
        if (!input.empty())
        {
            contact.setDarkestSecret(input);
            break;
        }
        std::cout << "This field cannot be empty. Try again.\n";
    }
}
