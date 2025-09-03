#include "PhoneBook.hpp"

Contact::Contact()
{
	firstName = "";
	lastName = "";
	nickName = "";
	phoneNumber = "";
	darkestSecret = "";
}

Contact::~Contact() {}

void    Contact::setFirstName(const std::string& firstName) {this->firstName = firstName; }
void    Contact::setLastName(const std::string& lastName) { this->lastName = lastName; }
void    Contact::setNickName(const std::string& nickName) { this->nickName = nickName; }
void    Contact::setPhoneNumber(const std::string& phoneNumber) { this->phoneNumber = phoneNumber; }
void    Contact::setDarkestSecret(const std::string& darkestSecret) { this->darkestSecret = darkestSecret; }

std::string     Contact::getFirstName(void)const { return firstName;}
std::string     Contact::getLastName(void)const { return lastName;}
std::string     Contact::getNickName(void)const { return nickName;}
std::string     Contact::getPhoneNumber(void)const { return phoneNumber;}
std::string     Contact::getDarkestSecret(void)const { return darkestSecret;}
