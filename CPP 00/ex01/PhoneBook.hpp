#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    ~Contact();

    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setNickname(const std::string &nickname);
    void setPhoneNumber(const std::string &phoneNumber);
    void setDarkestSecret(const std::string &darkestSecret);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

class PhoneBook
{
private:
    static const int maxContacts = 8;
    Contact contacts[maxContacts];
    int contactCount;
    int currentIndex;

    void addField(const std::string &prompt, void (Contact::*setter)(const std::string &), Contact &contact) const;
    std::string truncate(const std::string &str) const;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContact() const;
    void displayContact(int index) const;
    void displayAllContacts() const;
};

#endif

// #ifndef PHONEBOOK_HPP
// #define PHONEBOOK_HPP

// #include <iostream>
// #include <string>

// class Contact
// {
// 	private:
// 		std::string firstName;
// 		std::string lastName;
// 		std::string nickname;
// 		std::string phoneNumber;
// 		std::string darkestSecret;
// 	public:
// 		Contact();
// 		~Contact();
// 		void setFirstName(const std::string& firstName);
// 		void setLastName(const std::string& lastName);
// 		void setNickname(const std::string& nickname);
// 		void setPhoneNumber(const std::string& phoneNumber);
// 		void setDarkestSecret(const std::string& darkestSecret);
// 		std::string getFirstName() const;
// 		std::string getLastName() const;
// 		std::string getNickname() const;
// 		std::string getPhoneNumber() const;
// 		std::string getDarkestSecret() const;
// };

// class PhoneBook
// {
// 	private:
// 		static const int maxContacts = 8;
// 		Contact contacts[maxContacts];
// 		int contactCount;
// 		int currentIndex;
// 	public:
// 		PhoneBook();
// 		~PhoneBook();
// 		void addContact();
// 		void addContact(const std::string& prompt, void (Contact::*setter)(const std::string&), Contact& contact);
// 		void searchContact() const;
// 		void displayContact(int index) const;
// 		void displayAllContacts() const;
// };

// #endif