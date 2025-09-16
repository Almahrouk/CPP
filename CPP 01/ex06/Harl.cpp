#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug( void )
{
    std::cout << BLUE << "🐞 [DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET << std::endl;
}
void Harl::info( void )
{
    std::cout << GREEN << "ℹ️  [INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << RESET << std::endl;
}

void Harl::warning( void )
{
    std::cout << YELLOW << "⚠️  [WARNING] I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << RESET << std::endl;
}

void Harl::error( void )
{
    std::cout << RED << "❌ [ERROR] This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

void Harl::complain( std::string level )
{
    // std::cout << level << std::endl;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funcPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = 0;
    while (i < 4)
    {
        if (level == levels[i])
            break ;
        i++;
    }
    switch (i)
    {
    case 0:
        (this->*funcPtr[0])();
    case 1:
        (this->*funcPtr[1])();
    case 2:
        (this->*funcPtr[2])();
    case 3:
        (this->*funcPtr[3])();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]\n";
        break;
    }
    // std::cout << "Invalid level!" << std::endl;
}
