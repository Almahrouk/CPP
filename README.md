# 42 C++ Modules (CPP 00 to CPP 09)

My solutions to the 42 C++ modules, written in **C++98** and compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

Each module folder has the subject PDF and one folder per exercise. Each exercise has its own `Makefile`.

```bash
cd "CPP 09/ex02"
make          # build
./PmergeMe 3 5 9 7 4 1
make fclean   # remove objects and binary
```

---

## CPP 00: Namespaces, classes, member functions, streams

**ex00: Megaphone**
Prints its arguments in uppercase. With no arguments it prints `* LOUD AND UNBEARABLE FEEDBACK NOISE *`.

**ex01: My Awesome PhoneBook**
A small contact manager with `Contact` and `PhoneBook` classes. Commands: `ADD`, `SEARCH`, `EXIT`. It stores up to 8 contacts and replaces the oldest when full. `SEARCH` shows a table with columns truncated to 10 characters, then the full details of the chosen index.

**ex02: The Job Of Your Dreams**
Only `Account.hpp`, `tests.cpp` and the reference log are in the folder. The goal is to write `Account.cpp` so the output matches the log.

---

## CPP 01: Memory allocation, references, pointers to members, switch

**ex00: BraiiiiiiinnnzzzZ**
A `Zombie` class that announces itself. `newZombie()` creates one on the heap, and `randomChump()` creates one on the stack. The exercise is about choosing between the two.

**ex01: Moar brainz!**
`zombieHorde(N, name)` allocates N zombies in a single allocation and returns a pointer to the first one.

**ex02: HI THIS IS BRAIN**
A string, a pointer to it and a reference to it. The program prints their addresses and values to show how they relate.

**ex03: Unnecessary violence**
`Weapon`, `HumanA` and `HumanB`. `HumanA` always has a weapon, so it holds a reference. `HumanB` may have none, so it holds a pointer.

**ex04: Sed is for losers**
Reads a file and writes `<filename>.replace` with every occurrence of `s1` replaced by `s2`, without using `std::string::replace`.

**ex05: Harl 2.0**
`Harl` complains at four levels (`DEBUG`, `INFO`, `WARNING`, `ERROR`). It picks the right member function through an array of pointers to member functions, with no `if/else` chain.

**ex06: Harl filter**
Extends `Harl` with a log-level filter. It uses a `switch` so that all messages from the given level upward are printed.

---

## CPP 02: Ad-hoc polymorphism, operator overloading, canonical form

**ex00: My First Class in Orthodox Canonical Form**
`Fixed` stores a fixed-point number as an integer with 8 fractional bits. It has a default constructor, copy constructor, copy assignment, destructor and raw-bits accessors.

**ex01: Towards a more useful fixed-point number class**
Adds constructors from `int` and `float`, `toInt()`, `toFloat()` and an overload of `operator<<`.

**ex02: Now we're talking**
Adds the comparison operators, the four arithmetic operators, pre/post increment and decrement, and static `min` and `max` functions.

**ex03: BSP**
`Point` class (immutable `Fixed` coordinates) and `bsp()`, which tells whether a point is strictly inside a triangle. *Not finished yet: `Point.*` and `bsp.cpp` are empty.*

---

## CPP 03: Inheritance

**ex00: Aaaaand... OPEN!**
`ClapTrap` with hit points, energy points and attack damage. It can `attack()`, `takeDamage()` and `beRepaired()`, and each action costs energy.

**ex01: Serena, my love!**
`ScavTrap` inherits from `ClapTrap` with different starting stats and a `guardGate()` special ability. Constructor and destructor order is visible in the output.

**ex02: Repetitive work**
`FragTrap` inherits from `ClapTrap` and adds `highFivesGuys()`.

**ex03: Now it's weird!**
`DiamondTrap` inherits from both `ScavTrap` and `FragTrap` (diamond problem, solved with virtual inheritance). `whoAmI()` prints its own name and its `ClapTrap` name.

---

## CPP 04: Subtype polymorphism, abstract classes

**ex00: Polymorphism**
`Animal`, `Dog` and `Cat` with a virtual `makeSound()`. `WrongAnimal` and `WrongCat` show what happens without `virtual`.

**ex01: I don't want to set the world on fire**
Adds a `Brain` with 100 ideas. `Dog` and `Cat` own a `Brain` and must make a deep copy when copied. The test builds an array of animals and deletes them through the base class.

**ex02: Abstract class**
`Animal` becomes abstract, so it can no longer be instantiated.

---

## CPP 05: Repetition and exceptions

**ex00: Mommy, when I grow up, I want to be a bureaucrat!**
`Bureaucrat` with a name and a grade from 1 (highest) to 150. Grades can be incremented and decremented, and invalid grades throw `GradeTooHighException` or `GradeTooLowException`.

**ex01: Form up, maggots!**
A `Form` with a signing grade and an execution grade. A bureaucrat can sign it only if their grade is high enough.

**ex02: No, you need form 28B, not 28C...**
`AForm` becomes abstract, with three concrete forms:
- `ShrubberyCreationForm` writes ASCII trees to `<target>_shrubbery`.
- `RobotomyRequestForm` makes drilling noises and succeeds 50% of the time.
- `PresidentialPardonForm` announces a pardon from Zaphod Beeblebrox.

**ex03: At least this beats coffee-making**
`Intern` with `makeForm(name, target)` that creates the right form by name, with no `if/else` chain.

---

## CPP 06: C++ casts

**ex00: Conversion of scalar types**
`ScalarConverter` (non-instantiable) has a static `convert()` that takes a string literal and prints it as `char`, `int`, `float` and `double`. It handles special values such as `nan`, `inf` and `-inf` and reports impossible or non-displayable conversions.

**ex01: Serialization**
`Serializer` with `serialize()` and `deserialize()`. It converts a `Data*` to `uintptr_t` and back with `reinterpret_cast`, and the test checks the pointer is unchanged.

**ex02: Identify real type**
`Base` with empty classes `A`, `B` and `C`. `generate()` creates a random one, and `identify()` finds its real type from a pointer or from a reference, without `typeinfo`.

---

## CPP 07: Templates

**ex00: Start with a few functions**
Function templates `swap`, `min` and `max`.

**ex01: Iter**
`iter(array, length, function)` applies a function to every element of an array of any type.

**ex02: Array**
Class template `Array<T>` with a default constructor, a constructor taking a size, deep copy, `operator[]` that throws on an out-of-range index, and `size()`.

---

## CPP 08: Templated containers, iterators, algorithms

**ex00: Easy find**
Template function `easyfind(container, value)` that finds the first occurrence of an integer in a container and throws if it isn't there.

**ex01: Span**
`Span` stores up to N integers. It has `addNumber()`, `shortestSpan()` and `longestSpan()`, and it can add a whole range of numbers at once using iterators.

**ex02: Mutated abomination**
`MutantStack<T>` extends `std::stack<T>` and exposes iterators, so the stack can be traversed like a normal container.

---

## CPP 09: STL

**ex00: Bitcoin Exchange**
Reads a historical price database (`data.csv`) and an input file with `date | value` lines. For each line it prints the value of that amount of bitcoin on the date, using the closest earlier date if there is no exact match. Invalid dates, negative numbers and values above 1000 produce error messages.

**ex01: Reverse Polish Notation**
Evaluates an RPN expression such as `8 9 * 9 - 9 - 9 - 4 - 1 +` with a stack. Operands are single digits, and operators are `+ - * /`. Errors print `Error`.

**ex02: PmergeMe**
Sorts a sequence of positive integers with the **Ford-Johnson (merge-insertion) algorithm**. It is implemented separately with `std::vector` and `std::deque`, and each sort is timed.
1. Pair the elements (winner = larger, loser = smaller).
2. Sort the winners recursively.
3. Build the main chain `b1, a1, a2, ...`.
4. Insert the remaining losers by binary search in **Jacobsthal order** (`b3, b2, b5, b4, b11, ...`), searching only up to each loser's winner.
5. An odd leftover element is treated as the last loser.

```
$ ./PmergeMe 7 3 9 1 5 8 2
Before: 7 3 9 1 5 8 2
After:  1 2 3 5 7 8 9
Time to process a range of 7 elements with std::vector : ... us
Time to process a range of 7 elements with std::deque  : ... us
```

Invalid input prints `Error` on stderr. `PmergeMe_using_merge.*` is an earlier version that used a plain merge sort on the winners.

---

## Notes

- Some folders contain compiled files (`*.o` and executables). Run `make fclean` or add a `.gitignore` before committing.

## Author

Intra name: dal-mahr
Dana Al-Mahrouk, 42 Amman
