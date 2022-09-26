#include "Contact.hpp"

std::string    Contact::getName( void ) {return _Name;}
std::string    Contact::getLastName( void ) {return _LastName;}
std::string    Contact::getNickName( void ) {return _NickName;}
std::string    Contact::getPhoneNumber( void ) {return _PhoneNumber;}
std::string    Contact::getDarkestSecret( void ) {return _DarkestSecret;}


void    Contact::setInfo(std::string *data, std::string str)
{
    const char    *cstr;

    std::cout << "Entrez " << str << ": ";
    std::getline(std::cin, *data);
    int     i = 0;

    cstr = data->c_str();
    if (str == "PhoneNumber"){
        while(cstr[i])
        {
            if(cstr[i] >= '0' && cstr[i] <= '9')
            {
                ++i;
            }
            else
            {
                std::cout << "Chiffres entre 0 et 9." << std::endl;
                setInfo(data, str);
            }
        }
    }
    if (data->empty())
        setInfo(data, str);
}

void    Contact::askInfo( void )
{
    setInfo(&_Name, "Name");
    setInfo(&_LastName, "LastName");
    setInfo(&_NickName, "NickName");
    setInfo(&_PhoneNumber, "PhoneNumber");
    setInfo(&_DarkestSecret, "DarkestSecret");
}