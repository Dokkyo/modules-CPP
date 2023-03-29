#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *filename) : _filename(filename) 
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & rhs)
{
    *this = rhs;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & rhs)
{
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    if (_file.is_open())
        _file.close();
    if (_csv.is_open())
        _csv.close();
}

int     BitcoinExchange::open()
{
    this->_file.open(_filename);
    if (!_file.good())
    {
        std::cout << "#1. Opening file " << _filename <<  "failed.\n";
        return EXIT_FAILURE;
    }
    this->_csv.open("data.csv");
    if (!_csv.good())
    {
        std::cout << "#2. Opening csv file failed.\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int     BitcoinExchange::fill()
{
    std::string str;
    std::string date;
    float       price;
    std::string delimiter = ",";

    std::getline(_csv, str);
    while (!_csv.eof())
    {
        std::getline(_csv, str);
        size_t pos = 0;
        if ((pos = str.find(delimiter)) != std::string::npos)
        {
            date = str.substr(0, pos);
            str.erase(0, pos + delimiter.length());
            price = strtof(str.substr(0, str.length()).c_str(), NULL);
        }
        _input.insert(std::make_pair(date, price));
    }

    return EXIT_SUCCESS;
}

const std::string WHITESPACE = " \n\r\t\f\v";
 
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

int     BitcoinExchange::findAndPrint()
{
    std::string str;
    std::string date;
    float       nb_bitcoin;
    std::string delimiter = "|";
    std::string delimiter_date = "-";
    std::map<std::string, float>::iterator  it;
    std::map<std::string, float>::iterator  it2;
    std::map<std::string, float>::iterator  it3;

    while (!_file.eof())
    {
        std::getline(_file, str);
        size_t pos = 0;
        if ((pos = str.find(delimiter)) != std::string::npos)
        {
            date = str.substr(0, pos);
            date = trim(date);
            size_t _pos = 0;
            if ((_pos = str.find(delimiter_date)) != std::string::npos)
            {
                _year = date.substr(0, 4);
                _month = date.substr(5, 2);
                _day = date.substr(8,2);
                if (atoi(_year.c_str()) >= 2009 && atoi(_month.c_str()) >= 1 && atoi(_month.c_str()) <= 12 && atoi(_day.c_str()) >= 1 && atoi(_day.c_str()) <= 31)
                    ;
                else
                    std::cout << "Error: Date\n";
            }

            str.erase(0, pos + delimiter.length());
            nb_bitcoin = strtof(str.substr(0, str.length()).c_str(), NULL);
            if (nb_bitcoin < 0)
                std::cout << "Error: Not a positive number" << std::endl;
            else if (nb_bitcoin > 1000)
                std::cout << "Error: too large a number." << std::endl;
            else
            {
                it = _input.begin();
                it2 = _input.begin();
                it2++;
                while (it2 != _input.end())
                {
                    if (date == it->first)
                    {
                        std::cout << date << "==>" << nb_bitcoin << " = ";
                        std::cout << it->second * nb_bitcoin << std::endl;
                        break;
                    }
                    if (date == it2->first)
                    {
                        std::cout << date << "==>" << nb_bitcoin << " = ";
                        std::cout << it2->second * nb_bitcoin << std::endl;
                        break; 
                    }
                    if (atoi(_year.c_str()) == atoi(it->first.substr(0,4).c_str()) && atoi(_year.c_str()) == atoi(it2->first.substr(0,4).c_str()))
                    {
                        if (atoi(_month.c_str()) == atoi(it->first.substr(5,2).c_str()) && atoi(_month.c_str()) == atoi(it2->first.substr(5,2).c_str()))
                        {
                            if (atoi(_day.c_str()) > atoi(it->first.substr(8,2).c_str()) && atoi(_day.c_str()) < atoi(it2->first.substr(8,2).c_str()))
                            {
                                std::cout << date << "==>" << nb_bitcoin << " = ";
                                std::cout << it->second * nb_bitcoin << std::endl;
                                break;
                            }
                        }
                        if (atoi(_month.c_str()) > atoi(it->first.substr(5,2).c_str()) && atoi(_month.c_str()) == atoi(it2->first.substr(5,2).c_str()))
                        {
                            if (atoi(_day.c_str()) < atoi(it2->first.substr(8,2).c_str()))
                            {
                                std::cout << date << "==>" << nb_bitcoin << " = ";
                                std::cout << it->second * nb_bitcoin << std::endl;
                                break;
                            }
                        }
                    }
                    if (atoi(_year.c_str()) > atoi(it->first.substr(0,4).c_str()) && atoi(_year.c_str()) == atoi(it2->first.substr(0,4).c_str()))
                    {
                        if (atoi(_month.c_str()) == atoi(it2->first.substr(5,2).c_str()))
                        {
                            if (atoi(_day.c_str()) < atoi(it2->first.substr(8,2).c_str()))
                            {
                                std::cout << date << "==>" << nb_bitcoin << " = ";
                                std::cout << it->second * nb_bitcoin << std::endl;
                                break;
                            }
                        }
                    }
                    it++;
                    it2++;
                }
            }
        }
        else
            std::cout << "Error: Bad input ==> "  << str << std::endl;
    }
    std::cout << "\n";

    return EXIT_SUCCESS;
}