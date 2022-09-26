#ifndef WINNER_H
# define WINNER_H

#include <iostream>
#include <fstream>
#include <string>

class Winner
{

    private:

        std::string     _s1; 
        std::string     _s2;
        std::string     _filename;
        std::string     _newfile;

    public:

        Winner();
        ~Winner();

        void    setValues(std::string file, std::string str1, std::string str2);
        void    newFile();
};

#endif