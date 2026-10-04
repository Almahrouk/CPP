#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <cctype>
#include <limits>
#include <limits.h>
#include <string>
#include <iostream>
#include <cerrno>


enum DataType
{
    CHAR,
    INT,
    DOUBLE,
    FLOAT,
    NAN,
    FLOAT_SPECIAL,
    DOUBLE_SPECIAL,
    INVALID,
    // INF,
    // INFF
};

struct Data
{
    char character;
    int integer;
    float float_val;
    double double_val;
};

DataType isValidFloat(const std::string &literal);
DataType isValidDouble(const std::string &literal);
DataType isValidInt(const std::string &literal);


class ScalarConverter
{
    private:

    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter & operator=(const ScalarConverter &obj);
        static void convert(const std::string &literal);
};

std::ostream& operator<<(std::ostream& os, const ScalarConverter& ScalarConverter);

#endif