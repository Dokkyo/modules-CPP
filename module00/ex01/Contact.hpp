#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {

    public:

        void    setInfo(std::string *data, std::string str);
        void    askInfo( void );
        std::string    getName( void );
        std::string    getLastName( void );
        std::string    getNickName( void );
        std::string    getPhoneNumber( void );
        std::string    getDarkestSecret( void );

    private:
        std::string    _Name;
        std::string    _LastName;
        std::string    _NickName;
        std::string    _PhoneNumber;
        std::string    _DarkestSecret;
};

#endif