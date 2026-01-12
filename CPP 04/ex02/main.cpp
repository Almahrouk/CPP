#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static void section(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    // AAnimal* animal  = new AAnimal();

    section("Array of Animals (half Dog, half Cat)");

    const int N = 10;
    AAnimal* animals[N];

    for (int i = 0; i < N; ++i)
    {
        if (i < N / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < N; ++i)
    {
        std::cout << i << ": " << animals[i]->getType() << " -> ";
        animals[i]->makeSound();
    }

    section("Deleting Animals (polymorphic delete)");

    for (int i = 0; i < N; ++i)
        delete animals[i];

    section("Deep copy test (Dog)");

    {
        Dog original;
        original.setIdea(0, "I want a bone");
        original.setIdea(1, "I want to run");

        Dog copy(original);      // copy constructor
        Dog assigned;
        assigned = original;     // copy assignment

        original.setIdea(0, "CHANGED IDEA");
        original.setIdea(1, "ANOTHER CHANGE");

        std::cout << "Original[0]: " << original.getIdea(0) << std::endl;
        std::cout << "Copy[0]:     " << copy.getIdea(0) << std::endl;
        std::cout << "Assigned[0]: " << assigned.getIdea(0) << std::endl;
    }

    section("Deep copy test (Cat)");

    {
        Cat original;
        original.setIdea(0, "I will sleep");
        original.setIdea(1, "I will ignore you");

        Cat copy(original);      // copy constructor
        Cat assigned;
        assigned = original;     // copy assignment

        original.setIdea(0, "CHANGED IDEA");
        original.setIdea(1, "ANOTHER CHANGE");

        std::cout << "Original[0]: " << original.getIdea(0) << std::endl;
        std::cout << "Copy[0]:     " << copy.getIdea(0) << std::endl;
        std::cout << "Assigned[0]: " << assigned.getIdea(0) << std::endl;
    }

    section("End (check with valgrind)");
    return 0;
}
