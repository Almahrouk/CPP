#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): currentNumberOfContact(0), currentIndex(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact()
{
    Contact newContact;

    PhoneBook::setFirstName(newContact);
    PhoneBook::setLastName(newContact);
    PhoneBook::setNickName(newContact);
    PhoneBook::setPhoneNumber(newContact);
    PhoneBook::setDarkestSecret(newContact);
    ContactList[currentIndex] = newContact;
    currentIndex = (currentIndex + 1) % MAX_CONTACTS;
    if (currentNumberOfContact < MAX_CONTACTS)
        currentNumberOfContact++;
    std::cout << "Contact added successfully!\n";
}

std::string truncate(const std::string &str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::displayAllContact() const
{
    int num;
    int i;

    num = currentNumberOfContact;
    i = 0;
    if(!num)
    {
        std::cout << "List is empty" << std::endl;
        return ;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "\n";

    for (int i = 0; i < currentNumberOfContact; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(ContactList[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(ContactList[i].getLastName()) << "|"
                  << std::setw(10) << truncate(ContactList[i].getNickName()) << "\n";
    }
}

void PhoneBook::displayContact(int index) const
{
    if (index < 0 || index >= currentNumberOfContact)
    {
        std::cout << "❌ Invalid index.\n";
        return;
    }

    const Contact& c = ContactList[index];
    std::cout << "First Name: " << c.getFirstName() << "\n";
    std::cout << "Last Name: " << c.getLastName() << "\n";
    std::cout << "Nickname: " << c.getNickName() << "\n";
    std::cout << "Phone Number: " << c.getPhoneNumber() << "\n";
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << "\n";
}


void PhoneBook::searchContact() const
{
    std::string input;

    displayAllContact();
    if (!currentNumberOfContact)
        return ;
    std::cout << "Enter index to view details: ";
    std::getline(std::cin, input);
    if (std::cin.eof()) return;
    if (input.size() == 1 && std::isdigit(input[0]))
        displayContact(atoi(input.c_str()));
    else
        std::cout << "Invalid input.\n";
}
