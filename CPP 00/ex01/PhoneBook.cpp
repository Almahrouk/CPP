#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), currentIndex(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addField(const std::string& prompt, void (Contact::*setter)(const std::string&), Contact& contact) const
{
    std::string input;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof()) return; // handle CTRL+D
        if (!input.empty())
        {
            (contact.*setter)(input);
            break;
        }
        std::cout << "This field cannot be empty. Try again.\n";
    }
}

void PhoneBook::addContact()
{
    Contact& contact = contacts[currentIndex];

    addField("Enter First Name: ", &Contact::setFirstName, contact);
    addField("Enter Last Name: ", &Contact::setLastName, contact);
    addField("Enter Nickname: ", &Contact::setNickname, contact);
    addField("Enter Phone Number: ", &Contact::setPhoneNumber, contact);
    addField("Enter Darkest Secret: ", &Contact::setDarkestSecret, contact);

    currentIndex = (currentIndex + 1) % maxContacts;
    if (contactCount < maxContacts)
        contactCount++;

    std::cout << "✅ Contact added successfully!\n";
}

std::string PhoneBook::truncate(const std::string& str) const
{
    return (str.length() > 10 ? str.substr(0, 9) + "." : str);
}

void PhoneBook::displayAllContacts() const
{
    if (contactCount == 0)
    {
        std::cout << "📂 PhoneBook is empty.\n";
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "\n";

    for (int i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getNickname()) << "\n";
    }
}

void PhoneBook::displayContact(int index) const
{
    if (index < 0 || index >= contactCount)
    {
        std::cout << "❌ Invalid index.\n";
        return;
    }

    const Contact& c = contacts[index];
    std::cout << "First Name: " << c.getFirstName() << "\n";
    std::cout << "Last Name: " << c.getLastName() << "\n";
    std::cout << "Nickname: " << c.getNickname() << "\n";
    std::cout << "Phone Number: " << c.getPhoneNumber() << "\n";
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << "\n";
}

void PhoneBook::searchContact() const
{
    displayAllContacts();

    if (contactCount == 0)
        return;

    std::string input;
    std::cout << "Enter index to view details: ";
    std::getline(std::cin, input);
    if (std::cin.eof()) return;

    if (input.size() == 1 && std::isdigit(input[0]))
        displayContact(atoi(input.c_str()));
    else
        std::cout << "❌ Invalid input.\n";
}

// #include "PhoneBook.hpp"

// void PhoneBook::addContact() {
//     if (contactCount < maxContacts) {
//         Contact& contact = contacts[currentIndex];
//         addContact("Enter First Name: ", &Contact::setFirstName, contact);
//         addContact("Enter Last Name: ", &Contact::setLastName, contact);
//         addContact("Enter Nickname: ", &Contact::setNickname, contact);
//         addContact("Enter Phone Number: ", &Contact::setPhoneNumber, contact);
//         addContact("Enter Darkest Secret: ", &Contact::setDarkestSecret, contact);

//         currentIndex = (currentIndex + 1) % maxContacts;
//         if (contactCount < maxContacts) {
//             contactCount++;
//         }
//     } else {
//         std::cout << "PhoneBook is full. Cannot add more contacts." << std::endl;
//     }
// }

// void addContact(const std::string& prompt, void (Contact::*setter)(const std::string&), Contact& contact)
// {
//     std::string input;
//     while (true) {
//         std::cout << prompt;
//         std::getline(std::cin, input);
//         if (!input.empty()) {
//             (contact.*setter)(input);
//             break;
//         } else {
//             std::cout << "This field cannot be empty. Please try again." << std::endl;
//         }
//     }
// }
