#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {

    public:

        PhoneBook(int nb,int old);
        ~PhoneBook ();
        void        newContact();
        void        DisplayFormattedField(std::string str);
        void        DisplayMenu();
        void        searchContact();

    private:

        int     nb_contact;
        int     oldest;
        Contact contact[8];
};

#endif