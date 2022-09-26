#include "Winner.hpp"

Winner::Winner()
{
    std::cout << "Constructor called" << std::endl;
}

Winner::~Winner()
{
    std::cout << "Destructor called" << std::endl;
}

void    Winner::setValues(std::string file, std::string str1, std::string str2)
{
    this->_filename = file; 
    this->_s1 = str1;
    this->_s2 = str2;
}

void    Winner::newFile()
{
    std::ifstream           ifs(this->_filename.c_str());

    this->_newfile = this->_filename + ".replace";
    std::ofstream           ofs(this->_newfile.c_str());
    std::string             line;
    std::size_t             pos_found;

    if (ifs.is_open())
    {
        if (this->_s1.compare(this->_s2) != 0)
        {
            while (!ifs.eof())
            {
                std::getline(ifs, line);
                pos_found = line.find(this->_s1);
                while (pos_found <= line.size())
                {
                    line.erase(pos_found, this->_s1.size());
                    line.insert(pos_found, this->_s2);
                    pos_found = line.find(this->_s1, pos_found + this->_s2.size());
                }
                ofs << line;
                ofs << '\n';
            }
        }
        else
        {
            while (!ifs.eof())
            {
                std::getline(ifs, line);
                ofs << line;
                ofs << '\n';
            }
        }
        ifs.close();
    }
}
