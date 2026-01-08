#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// Helper: prints a title separator
static void section(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    // section("Array of Animals (half Dog, half Cat)");

    // const int N = 10;
    // Animal* animals[N];

    // // Fill first half with Dogs, second half with Cats
    // for (int idx = 0; idx < N; ++idx) {
    //     if (idx < N / 2)
    //         animals[idx] = new Dog();
    //     else
    //         animals[idx] = new Cat();
    // }

    // // Optional: make sounds to verify polymorphism
    // for (int idx = 0; idx < N; ++idx) {
    //     std::cout << idx << ": " << animals[idx]->getType() << " -> ";
    //     animals[idx]->makeSound();
    // }

    // // Delete as Animals (must call derived destructors then Animal)
    // section("Deleting Animals (must call proper destructors)");
    // for (int idx = 0; idx < N; ++idx) {
    //     delete animals[idx];
    // }

    // section("Deep copy tests (Dog)");

    // {
    //     Dog original;
    //     original.setIdea(0, "I want a bone");
    //     original.setIdea(1, "I want to run");

    //     Dog copyConstructed(original); // copy ctor
    //     Dog assigned;
    //     assigned = original;           // copy assignment

    //     // Change original after copying
    //     original.setIdea(0, "CHANGED IDEA");
    //     original.setIdea(1, "ANOTHER CHANGE");

    //     std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
    //     std::cout << "CopyCtor idea[0]: " << copyConstructed.getIdea(0) << std::endl;
    //     std::cout << "Assigned idea[0]: " << assigned.getIdea(0) << std::endl;

    //     std::cout << "Original idea[1]: " << original.getIdea(1) << std::endl;
    //     std::cout << "CopyCtor idea[1]: " << copyConstructed.getIdea(1) << std::endl;
    //     std::cout << "Assigned idea[1]: " << assigned.getIdea(1) << std::endl;

        // If deep copy is correct:
        // copyConstructed / assigned should still have the old values, not "CHANGED IDEA".
    // }

    section("Deep copy tests (Cat)");

    {
        Cat original;
        original.setIdea(0, "I will sleep");
        original.setIdea(1, "I will ignore you");

        Cat copyConstructed(original); // copy ctor
        Cat assigned;
        assigned = original;           // copy assignment

        // Change original after copying
        original.setIdea(0, "CHANGED IDEA");
        original.setIdea(1, "ANOTHER CHANGE");

        std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
        std::cout << "CopyCtor idea[0]: " << copyConstructed.getIdea(0) << std::endl;
        std::cout << "Assigned idea[0]: " << assigned.getIdea(0) << std::endl;

        std::cout << "Original idea[1]: " << original.getIdea(1) << std::endl;
        std::cout << "CopyCtor idea[1]: " << copyConstructed.getIdea(1) << std::endl;
        std::cout << "Assigned idea[1]: " << assigned.getIdea(1) << std::endl;
    }

    section("End (run with valgrind / leaks check)");
    return 0;
}
