#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl h;
    std::string level;

    if(ac > 2)
    {
        std::cout << "Invalid Input" << std::endl;
        return (EXIT_FAILURE);
    }
    std::cout << "Do you know Harl? We all do, don’t we? In case you don’t, find below the kind of comments Harl makes. They are classified by levels" << std::endl;
    level = av[1];
    // std::cout << level << std::endl;
    h.complain(level);
    return (EXIT_SUCCESS);
}