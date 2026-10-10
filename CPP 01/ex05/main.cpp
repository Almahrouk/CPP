#include "Harl.hpp"

int main()
{
    Harl h;
    std::cout << "Do you know Harl? We all do, don’t we? In case you don’t, find below the kind of comments Harl makes. They are classified by levels" << std::endl;
    h.complain("DEBUG");
    h.complain("INFO");
    h.complain("WARNING");
    h.complain("ERROR");
    return (EXIT_SUCCESS);
}