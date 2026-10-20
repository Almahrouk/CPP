#include "BitcoinExchange.hpp"

static void printError(int err)
{
    switch (err)
    {
        case BitcoinExchange::EmptyFile:
            std::cerr << "Error: file is empty." << std::endl;
            break;
        case BitcoinExchange::FailedOpeningFile:
            std::cerr << "Error: could not open file." << std::endl;
            break;
        case BitcoinExchange::InvalidStartLine:
            std::cerr << "Error: invalid first line." << std::endl;
            break;
        case BitcoinExchange::EmptyDatabase:
            std::cerr << "Error: database has no valid entries." << std::endl;
            break;
        default:
            break;
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return EXIT_FAILURE;
    }

    BitcoinExchange btc(av[1]);
    int ret = btc.loadDatabase("data.csv");
    if (ret != BitcoinExchange::SUCCESS)
    {
        printError(ret);
        return EXIT_FAILURE;
    }

    ret = btc.processInput();
    if (ret != BitcoinExchange::SUCCESS)
    {
        printError(ret);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}