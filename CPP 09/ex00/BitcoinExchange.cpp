#include "BitcoinExchange.hpp"

static std::string trim(const std::string &s)
{
    std::size_t b = s.find_first_not_of(" \t\r\n");
    if (b == std::string::npos)
        return "";
    std::size_t e = s.find_last_not_of(" \t\r\n");
    return s.substr(b, e - b + 1);
}

BitcoinExchange::BitcoinExchange() : _inputFile(""), _data() {}

BitcoinExchange::BitcoinExchange(const std::string &inputFile)
    : _inputFile(inputFile), _data() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
    : _inputFile(obj._inputFile), _data(obj._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if (this != &obj)
    {
        _inputFile = obj._inputFile;
        _data = obj._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

const std::string &BitcoinExchange::getInputFile() const
{
    return _inputFile;
}

const std::map<std::string, double> &BitcoinExchange::getData() const
{
    return _data;
}

void BitcoinExchange::setInputFile(const std::string &inputFile)
{
    _inputFile = inputFile;
}

void BitcoinExchange::setData(const std::map<std::string, double> &data)
{
    _data = data;
}

int BitcoinExchange::parsingFileToMap(const std::string &file, std::map<std::string, double> &map, const std::string &header, char delimiter) const
{
    if (file.empty())
        return EmptyFile;

    std::ifstream readFile(file.c_str());
    if (!readFile.is_open())
        return FailedOpeningFile;

    std::string line;
    if (!std::getline(readFile, line))
        return EmptyFile;
    if (trim(line) != header)
        return InvalidStartLine;

    while (std::getline(readFile, line))
    {
        line = trim(line);
        if (line.empty())
            continue;

        std::size_t pos = line.find(delimiter);
        if (pos == std::string::npos)
            continue;

        std::string date = trim(line.substr(0, pos));
        std::string valStr = trim(line.substr(pos + 1));
        double value;

        if (!isValidDate(date) || !parseValue(valStr, value))
            continue;
        map[date] = value;
    }
    return SUCCESS;
}

int BitcoinExchange::loadDatabase(const std::string &file)
{
    std::map<std::string, double> tmp;
    int ret = parsingFileToMap(file, tmp, "date,exchange_rate", ',');

    if (ret != SUCCESS)
        return ret;
    if (tmp.empty())
        return EmptyDatabase;
    _data = tmp;
    return SUCCESS;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }
    int y = std::atoi(date.substr(0, 4).c_str());
    int m = std::atoi(date.substr(5, 2).c_str());
    int d = std::atoi(date.substr(8, 2).c_str());

    if (m < 1 || m > 12 || d < 1)
        return false;

    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    if (leap)
        days[1] = 29;
    return d <= days[m - 1];
}

bool BitcoinExchange::parseValue(const std::string &str, double &out) const
{
    if (str.empty())
        return false;

    std::size_t i = 0;
    if (str[0] == '-' || str[0] == '+')
        i = 1;

    bool digit = false;
    bool dot = false;
    for (; i < str.size(); ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
            digit = true;
        else if (str[i] == '.' && !dot)
            dot = true;
        else
            return false;
    }
    if (!digit)
        return false;
    out = std::strtod(str.c_str(), NULL);
    return true;
}

BitcoinExchange::States BitcoinExchange::validateLine(const std::string &line, std::string &date, double &value) const
{
    std::size_t pos = line.find('|');
    if (pos == std::string::npos)
        return BadInput;

    date = trim(line.substr(0, pos));
    std::string valStr = trim(line.substr(pos + 1));

    if (!isValidDate(date) || !parseValue(valStr, value))
        return BadInput;
    if (value < 0)
        return NotPositive;
    if (value > 1000)
        return TooLarge;
    return ValidLine;
}

bool BitcoinExchange::findRate(const std::string &date, double &rate) const
{
    std::map<std::string, double>::const_iterator it = _data.upper_bound(date);

    if (it == _data.begin())
        return false;
    --it;
    rate = it->second;
    return true;
}


int BitcoinExchange::processInput() const
{
    if (_inputFile.empty())
        return EmptyFile;

    std::ifstream readFile(_inputFile.c_str());
    if (!readFile.is_open())
        return FailedOpeningFile;

    std::string line;
    if (!std::getline(readFile, line))
        return EmptyFile;
    if (trim(line) != "date | value")
        return InvalidStartLine;

    while (std::getline(readFile, line))
    {
        line = trim(line);
        if (line.empty())
            continue;

        std::string date;
        double value = 0;
        double rate = 0;

        switch (validateLine(line, date, value))
        {
            case BadInput:
                std::cout << "Error: bad input => " << line << std::endl;
                break;
            case NotPositive:
                std::cout << "Error: not a positive number." << std::endl;
                break;
            case TooLarge:
                std::cout << "Error: too large a number." << std::endl;
                break;
            case ValidLine:
                if (!findRate(date, rate))
                    std::cout << "Error: no earlier date in database => " << date << std::endl;
                else
                    std::cout << date << " => " << value << " = " << value * rate << std::endl;
                break;
            default:
                break;
        }
    }
    return SUCCESS;
}

std::ostream &operator<<(std::ostream &os, const BitcoinExchange &btc)
{
    os << btc.getInputFile();
    return os;
}