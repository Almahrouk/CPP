#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    // std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    // std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &obj)
{
    // std::cout << "ScalarConverter assignment operator called" << std::endl;
    if (this != &obj)
    {

    }
    return *this;
}

bool isFloat(const std::string &s)
{
    size_t i = 0;

    if (s.empty())
        return false;

    if (s[i] == '+' || s[i] == '-')
        i++;

    if (i == s.length())
        return false;

    bool dot = false;
    bool digit = false;

    while (i < s.length())
    {
        if (std::isdigit(s[i]))
            digit = true;
        else if (s[i] == '.' && !dot)
            dot = true;
        else if (s[i] == 'f' && i == s.length() - 1)
            return dot && digit;
        else
            return false;
        i++;
    }

    return false;
}


bool isDouble(const std::string &s)
{
    size_t i = 0;

    if (s.empty())
        return false;

    if (s[i] == '+' || s[i] == '-')
        i++;

    if (i == s.length())
        return false;

    bool dot = false;
    bool digit = false;

    while (i < s.length())
    {
        if (std::isdigit(s[i]))
            digit = true;
        else if (s[i] == '.' && !dot)
            dot = true;
        else
            return false;
        i++;
    }

    return dot && digit;
}



DataType isValidInt(const std::string &literal)
{
    if (literal.length() == 0)
        return INVALID;
    if (literal[0] == '-' || literal[0] == '+')
    {
        if (literal.length() == 1)
            return INVALID;
        for (size_t i = 1; i < literal.length(); i++)
        {
            if (!std::isdigit(literal[i]))
                return INVALID;
        }
        return INT;
    }
    else
    {
        for (size_t i = 0; i < literal.length(); i++)
        {
            if (!std::isdigit(literal[i]))
                return INVALID;
        }
        return INT;
    }
}

DataType InputToType(const std::string &literal)
{
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return CHAR;
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return DOUBLE_SPECIAL;
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return FLOAT_SPECIAL;
    if (isValidInt(literal) == INT)
        return INT;
    if (isFloat(literal))
        return FLOAT;
    if (isDouble(literal))
        return DOUBLE;
    return INVALID;
}


void initializeData(Data &dataStruct)
{
    dataStruct.character = 0;
    dataStruct.integer = 0;
    dataStruct.float_val = 0.0f;
    dataStruct.double_val = 0.0;
}

void TypeToData(DataType data, const std::string &literal, Data &dataStruct)
{
    switch (data)
    {
        case CHAR:
            dataStruct.character = literal[1];
            dataStruct.float_val = static_cast<float>(dataStruct.character);
            dataStruct.double_val = static_cast<double>(dataStruct.character);
            break;
        case INT:
        {
            errno = 0;
            long value = std::strtol(literal.c_str(), NULL, 10);

            if (errno == ERANGE)
            {
                if (literal[0] == '-')
                {
                    dataStruct.integer = std::numeric_limits<int>::min();
                    dataStruct.float_val = -std::numeric_limits<float>::infinity();
                    dataStruct.double_val = -std::numeric_limits<double>::infinity();
                }
                else
                {
                    dataStruct.integer = std::numeric_limits<int>::max();
                    dataStruct.float_val = std::numeric_limits<float>::infinity();
                    dataStruct.double_val = std::numeric_limits<double>::infinity();
                }
            }
            else
            {
                dataStruct.integer = static_cast<int>(value);
                dataStruct.character = static_cast<char>(dataStruct.integer);
                dataStruct.float_val = static_cast<float>(value);
                dataStruct.double_val = static_cast<double>(value);
            }

            break;
        }
        case FLOAT:
            dataStruct.float_val = std::strtof(literal.c_str(), NULL);
            dataStruct.character = static_cast<char>(dataStruct.float_val);
            dataStruct.double_val = static_cast<double>(dataStruct.float_val);
            break;
        case DOUBLE:
            dataStruct.double_val = std::strtod(literal.c_str(), NULL);
            dataStruct.character = static_cast<char>(dataStruct.double_val);
            dataStruct.float_val = static_cast<float>(dataStruct.double_val);
            break;
        case FLOAT_SPECIAL:
            if (literal == "nanf")
                dataStruct.float_val = std::numeric_limits<float>::quiet_NaN();
            else if (literal == "+inff")
                dataStruct.float_val = std::numeric_limits<float>::infinity();
            else if (literal == "-inff")
                dataStruct.float_val = -std::numeric_limits<float>::infinity();

            dataStruct.double_val = static_cast<double>(dataStruct.float_val);
            break;
        case DOUBLE_SPECIAL:
            if (literal == "nan")
                dataStruct.double_val = std::numeric_limits<double>::quiet_NaN();
            else if (literal == "+inf")
                dataStruct.double_val = std::numeric_limits<double>::infinity();
            else if (literal == "-inf")
                dataStruct.double_val = -std::numeric_limits<double>::infinity();

            dataStruct.float_val = static_cast<float>(dataStruct.double_val);
            break;
        default:
            std::cerr << "Invalid data type" << std::endl;
            break;
    }
}


void printInt(DataType data, Data &dataStruct, const std::string &literal)
{
    // Check Int
    switch (data)
    {
        case CHAR:
            dataStruct.integer = static_cast<int>(dataStruct.character);
            std::cout << "int: " << dataStruct.integer << std::endl;
            break;
        case INT:
        {
            errno = 0;
            long value = std::strtol(literal.c_str(), NULL, 10);

            if (errno == ERANGE)
            {
                if (literal[0] == '-')
                    std::cout << "int: -inf" << std::endl;
                else
                    std::cout << "int: inf" << std::endl;
            }
            else if (value > std::numeric_limits<int>::max())
                std::cout << "int: inf" << std::endl;
            else if (value < std::numeric_limits<int>::min())
                std::cout << "int: -inf" << std::endl;
            else
                std::cout << "int: " << value << std::endl;

            break;
        }
        case FLOAT:   
            if (dataStruct.float_val <= static_cast<float>(std::numeric_limits<int>::max()) && dataStruct.float_val >= static_cast<float>(std::numeric_limits<int>::min()))
            {
                dataStruct.integer = static_cast<int>(dataStruct.float_val);
                std::cout << "int: " << dataStruct.integer << std::endl;
            }
            else if (dataStruct.float_val > std::numeric_limits<int>::max())
                std::cout << "int: inf" << std::endl;
            else if (dataStruct.float_val < std::numeric_limits<int>::min())
                std::cout << "int: -inf" << std::endl;
            break;
        case DOUBLE:
            if (dataStruct.double_val <= static_cast<double>(std::numeric_limits<int>::max()) && dataStruct.double_val >= static_cast<double>(std::numeric_limits<int>::min()))
            {
                dataStruct.integer = static_cast<int>(dataStruct.double_val);
                std::cout << "int: " << dataStruct.integer << std::endl;
            }
            else if (dataStruct.double_val > std::numeric_limits<int>::max())
                std::cout << "int: inf" << std::endl;
            else if (dataStruct.double_val < std::numeric_limits<int>::min())
                std::cout << "int: -inf" << std::endl;
            break;
        case FLOAT_SPECIAL:
        case DOUBLE_SPECIAL:
            std::cout << "int: impossible" << std::endl;
            break;
        default:
            std::cout << "int: impossible" << std::endl;
            break;
    }
}

void printFloatAndDouble(DataType data, Data &dataStruct)
{
    if (data == CHAR || data == INT)
    {
        // Float
        if (dataStruct.float_val == std::numeric_limits<float>::infinity())
            std::cout << "float: inff" << std::endl;
        else if (dataStruct.float_val == -std::numeric_limits<float>::infinity())
            std::cout << "float: -inff" << std::endl;
        else
            std::cout << "float: " << dataStruct.float_val << ".0f" << std::endl;

        // Double
        if (dataStruct.double_val == std::numeric_limits<double>::infinity())
            std::cout << "double: inf" << std::endl;
        else if (dataStruct.double_val == -std::numeric_limits<double>::infinity())
            std::cout << "double: -inf" << std::endl;
        else
            std::cout << "double: " << dataStruct.double_val << ".0" << std::endl;
    }
    else if (data == FLOAT_SPECIAL || data == DOUBLE_SPECIAL)
    {
        if (dataStruct.float_val != dataStruct.float_val)
            std::cout << "float: nanf" << std::endl;
        else if (dataStruct.float_val == std::numeric_limits<float>::infinity())
            std::cout << "float: inff" << std::endl;
        else if (dataStruct.float_val == -std::numeric_limits<float>::infinity())
            std::cout << "float: -inff" << std::endl;

        if (dataStruct.double_val != dataStruct.double_val)
            std::cout << "double: nan" << std::endl;
        else if (dataStruct.double_val == std::numeric_limits<double>::infinity())
            std::cout << "double: inf" << std::endl;
        else if (dataStruct.double_val == -std::numeric_limits<double>::infinity())
            std::cout << "double: -inf" << std::endl;
    }
    else if (data == FLOAT || data == DOUBLE)
    {
        // Float
        if (dataStruct.float_val == std::numeric_limits<float>::infinity())
            std::cout << "float: inff" << std::endl;
        else if (dataStruct.float_val == -std::numeric_limits<float>::infinity())
            std::cout << "float: -inff" << std::endl;
        else if (dataStruct.float_val == static_cast<int>(dataStruct.float_val))
            std::cout << "float: " << dataStruct.float_val << ".0f" << std::endl;
        else
            std::cout << "float: " << dataStruct.float_val << "f" << std::endl;

        // Double
        if (dataStruct.double_val == std::numeric_limits<double>::infinity())
            std::cout << "double: inf" << std::endl;
        else if (dataStruct.double_val == -std::numeric_limits<double>::infinity())
            std::cout << "double: -inf" << std::endl;
        else if (dataStruct.double_val == static_cast<int>(dataStruct.double_val))
            std::cout << "double: " << dataStruct.double_val << ".0" << std::endl;
        else
            std::cout << "double: " << dataStruct.double_val << std::endl;
    }
    else
    {
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void printData(DataType data, Data &dataStruct, const std::string &literal)
{
    // Check Char
    if (data == FLOAT_SPECIAL || data == DOUBLE_SPECIAL)
        std::cout << "char: impossible" << std::endl;
    else if (dataStruct.character < 32 || dataStruct.character > 126)
        std::cout << "char: not displayable" << std::endl;
    else
        std::cout << "char: '" << dataStruct.character << "'" << std::endl;
    printInt(data, dataStruct, literal);
    printFloatAndDouble(data, dataStruct);
}


void ScalarConverter::convert(const std::string &literal)
{
    DataType data = InputToType(literal);

    Data dataStruct;
    initializeData(dataStruct);
    TypeToData(data, literal, dataStruct);
    printData(data, dataStruct, literal);

    std::cout << "END CODE" << std::endl;
}

std::ostream & operator<<(std::ostream & os, const ScalarConverter & ScalarConverter)
{
	(void)ScalarConverter;
    os << "ScalarConverter: " << std::endl;
	return (os);
}