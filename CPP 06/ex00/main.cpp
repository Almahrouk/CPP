// #include "ScalarConverter.hpp"

// int main(int ac, char **av)
// {
//     if(ac != 2)
//         return 1;
//     ScalarConverter s;
//     s.convert(av[1]);
//     return 0;
// }

#include "ScalarConverter.hpp"
#include <iostream>

int main(void)
{
    // std::cout << "===== CHAR =====" << std::endl;
    // std::cout << "converting char: a" << std::endl;
    // ScalarConverter::convert("'a'");
    // std::cout << "converting char: 0" << std::endl;
    // ScalarConverter::convert("'0'");
    // std::cout << "converting char: space" << std::endl;
    // ScalarConverter::convert("' '");

    // std::cout << "\n===== INT =====" << std::endl;
    // std::cout << "converting int: 0" << std::endl;
    // ScalarConverter::convert("0");
    // std::cout << "converting int: 42" << std::endl;
    // ScalarConverter::convert("42");
    // std::cout << "converting int: -42" << std::endl;
    // ScalarConverter::convert("-42");
    // std::cout << "converting int INT_MAX: 2147483647" << std::endl;
    // ScalarConverter::convert("2147483647");
    // std::cout << "converting int INT_MIN: -2147483648" << std::endl;
    // ScalarConverter::convert("-2147483648");
    // std::cout << "converting int Over INT_MAX: 2147483600000000000000000000000000000000000000000000000000000000000000000000000000000444444" << std::endl;
    // ScalarConverter::convert("2147483600000000000000000000000000000000000000000000000000000000000000000000000000000444444");
    // std::cout << "converting int Under INT_MIN: -2147483600000000000000000000000000000000000000000000000000000000000000000000000000000444444" << std::endl;
    // ScalarConverter::convert("-2147483600000000000000000000000000000000000000000000000000000000000000000000000000000444444");

    // std::cout << "\n===== FLOAT =====" << std::endl;
    // std::cout << "converting float: 0.0f" << std::endl;
    // ScalarConverter::convert("0.0f");
    // std::cout << "converting float: 42.0f" << std::endl;
    // ScalarConverter::convert("42.0f");
    // std::cout << "converting float: -42.5f" << std::endl;
    // ScalarConverter::convert("-42.5f");
    // std::cout << "converting float: 4.2f" << std::endl;
    // ScalarConverter::convert("4.2f");
    // std::cout << "converting float: -42000000000000000000000000000000000000000000000000000000000000000000000000000000000.58f" << std::endl;
    // ScalarConverter::convert("-42000000000000000000000000000000000000000000000000000000000000000000000000000000000.5f");
    // std::cout << "converting float: 42000000000000000000000000000000000000000000000000000000000000000000000000000000000.2f" << std::endl;
    // ScalarConverter::convert("42000000000000000000000000000000000000000000000000000000000000000000000000000000000.2f");

    // std::cout << "\n===== DOUBLE =====" << std::endl;
    // std::cout << "converting double: 0.0" << std::endl;
    // ScalarConverter::convert("0.0");
    // std::cout << "converting double: 42.0" << std::endl;
    // ScalarConverter::convert("42.0");
    // std::cout << "converting double: -42.5" << std::endl;
    // ScalarConverter::convert("-42.5");
    // std::cout << "converting double: 4.2" << std::endl;
    // ScalarConverter::convert("4.2");
    // std::cout << "converting double: nan" << std::endl;
    // ScalarConverter::convert("nan");
    // std::cout << "converting double: +inf" << std::endl;
    // ScalarConverter::convert("+inf");
    // std::cout << "converting double: -inf" << std::endl;
    // ScalarConverter::convert("-inf");

    // std::cout << "\n===== CONVERSION / CHAR RANGE =====" << std::endl;
    // std::cout << "converting int: 32" << std::endl;
    // ScalarConverter::convert("32");
    // std::cout << "converting int: 33" << std::endl;
    // ScalarConverter::convert("33");
    // std::cout << "converting int: 126" << std::endl;
    // ScalarConverter::convert("126");
    // std::cout << "converting int: 127" << std::endl;
    // ScalarConverter::convert("127");
    // std::cout << "converting int: 31" << std::endl;
    // ScalarConverter::convert("31");

    // std::cout << "\n===== DECIMAL VALUES =====" << std::endl;
    // std::cout << "converting double: 42.42" << std::endl;
    // ScalarConverter::convert("42.42");
    // std::cout << "converting double: -42.42" << std::endl;
    // ScalarConverter::convert("-42.42");
    // std::cout << "converting float: 42.42f" << std::endl;
    // ScalarConverter::convert("42.42f");
    // std::cout << "converting float: -42.42f" << std::endl;
    // ScalarConverter::convert("-42.42f");

    // std::cout << "\n===== OVERFLOW =====" << std::endl;
    // std::cout << "converting int: 2147483648" << std::endl;
    // ScalarConverter::convert("2147483648");
    // std::cout << "converting int: -2147483649" << std::endl;
    // ScalarConverter::convert("-2147483649");
    // std::cout << "converting double: 999999999999999999999999.0" << std::endl;
    // ScalarConverter::convert("9999999999999999999999 ninety.0");
    // std::cout << "converting float:  ninety.0f" << std::endl;
    // ScalarConverter::convert(" ninety.0f");

    std::cout << "\n===== INVALID INPUT =====" << std::endl;
    std::cout << "converting empty string" << std::endl;
    ScalarConverter::convert("");
    std::cout << "converting nan" << std::endl;
    ScalarConverter::convert("nan");
    std::cout << "converting string: abc" << std::endl;
    ScalarConverter::convert("abc");
    std::cout << "converting string: 42abc" << std::endl;
    ScalarConverter::convert("42abc");
    std::cout << "converting string: 42.5abc" << std::endl;
    ScalarConverter::convert("42.5abc");
    std::cout << "converting string: 42..5" << std::endl;
    ScalarConverter::convert("42..5");
    std::cout << "converting string: 42.5ff" << std::endl;
    ScalarConverter::convert("42.5ff");

    return 0;
}
