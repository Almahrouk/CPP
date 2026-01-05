#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string name;
        unsigned int hit_point;
        int energy_point;
        int attack_damage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &obj);
        ClapTrap &operator=(const ClapTrap &obj);
        ~ClapTrap();
        std::string getName(void) const;
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        
    };
    

#endif 