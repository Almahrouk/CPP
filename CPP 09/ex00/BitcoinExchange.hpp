#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
    public:
        enum Errors
        {
            SUCCESS,
            EmptyFile,
            FailedOpeningFile,
            InvalidStartLine,
            EmptyDatabase
        };
        enum States
        {
            EndReadingFile,
            ValidLine,
            BadInput,
            NotPositive,
            TooLarge,
            NoEarlierDate
        };

    private:
        std::string                     _inputFile;
        std::map<std::string, double>   _data;

        
        public:
        BitcoinExchange();
        BitcoinExchange(const std::string &inputFile);
        BitcoinExchange(const BitcoinExchange &obj);
        BitcoinExchange &operator=(const BitcoinExchange &obj);
        ~BitcoinExchange();
        
        bool    isValidDate(const std::string &date) const;
        bool    parseValue(const std::string &str, double &out) const;
        States  validateLine(const std::string &line, std::string &date, double &value) const;
        bool    findRate(const std::string &date, double &rate) const;

        const std::string                           &getInputFile() const;
        const std::map<std::string, double>         &getData() const;
        void    setInputFile(const std::string &inputFile);
        void    setData(const std::map<std::string, double> &data);

        int     parsingFileToMap(const std::string &file, std::map<std::string, double> &map, const std::string &header, char delimiter) const;
        int     loadDatabase(const std::string &file);
        int     processInput() const;
};

std::ostream &operator<<(std::ostream &os, const BitcoinExchange &btc);

#endif