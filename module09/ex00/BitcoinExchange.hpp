#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <iomanip>
#include <cstdlib>

class BitcoinExchange
{
    private:
        BitcoinExchange();
        std::string     _filename;
        std::fstream    _file;
        std::fstream   _csv;
        std::map<std::string, float> _input;
        std::string     _year;
        std::string     _month;
        std::string     _day;
    public:
        BitcoinExchange(char * filename);
        BitcoinExchange(const BitcoinExchange & rhs);
        BitcoinExchange & operator=(const BitcoinExchange & rhs);
        ~BitcoinExchange();

        int     open();
        int     fill();
        int     findAndPrint();
};

#endif