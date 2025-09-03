#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
    private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
    public:
        Contact();
        ~Contact();
        void    setFirstName(const std::string& firstName);
        void    setLastName(const std::string& lastName);
        void    setNickName(const std::string& nickName);
        void    setPhoneNumber(const std::string& phoneNumber);
        void    setDarkestSecret(const std::string& darkestSecret);
        std::string     getFirstName(void)const;
        std::string     getLastName(void)const;
        std::string     getNickName(void)const;
        std::string     getPhoneNumber(void)const;
        std::string     getDarkestSecret(void)const;
};

#endif

