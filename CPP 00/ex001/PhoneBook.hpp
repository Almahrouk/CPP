#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <sstream>
#include <cstdlib>
#include "Contact.hpp"
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
class PhoneBook
{
    private:
        static const int MAX_CONTACTS = 8;
        int currentNumberOfContact;
        int currentIndex;
        Contact ContactList[8];

        void setFirstName(Contact &contact) const;
        void setLastName(Contact &contact) const;
        void setNickName(Contact &contact) const;
        void setPhoneNumber(Contact &contact) const;
        void setDarkestSecret(Contact &contact) const;
    public:
        PhoneBook();
        ~PhoneBook();

        void addContact();
        void searchContact() const;
        void displayContact(int index) const;
        void displayAllContact() const;
};

#endif
