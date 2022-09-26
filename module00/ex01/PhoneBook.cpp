#include "PhoneBook.hpp"

PhoneBook::PhoneBook(int nb, int old) : nb_contact(nb), oldest(old) {}

PhoneBook::~PhoneBook() {}

void    PhoneBook::newContact()
{
    if (nb_contact == 8)
    {
        this->contact[oldest].askInfo();
        this->oldest++;
        if (this->oldest == 8)
            this->oldest = 0;
    }
    else
    {
        this->contact[nb_contact].askInfo();
        ++this->nb_contact;
    }
}

void    PhoneBook::DisplayFormattedField(std::string str)
{
    std::cout << " ";
    if (str.size() < 10)
    {
        std::cout << std::setfill(' ') << std::setw(10);
        std::cout << str;
    }
    else if (str.size() > 10)
    {
        str = str.substr(0, 10);
        str.replace(9, 1, 1,'.');
        std::cout << str;
    }
    else
        std::cout << str;
}

void    PhoneBook::DisplayMenu()
{
    int         idx = -1;
    std::string str;

    std::cout   << std::setfill(' ') << std::setw(10) << "Index";
    std::cout   << "|";
    std::cout   << std::setfill(' ') << std::setw(10) << "First Name";
    std::cout   << "|";
    std::cout   << std::setfill(' ') << std::setw(10) << "Last Name";
    std::cout   << "|";
    std::cout   << std::setfill(' ') << std::setw(10) << "Nickname" << std::endl;
    while (++idx < this->nb_contact)
    {
        std::cout << std::setfill(' ') << std::setw(10);
        std::cout << idx + 1;
        str = contact[idx].getName();
        DisplayFormattedField(str);
        str = contact[idx].getLastName();
        DisplayFormattedField(str);
        str = contact[idx].getNickName();
        DisplayFormattedField(str);
        std::cout << std::endl;
    }
}

void    PhoneBook::searchContact()
{
    std::string     str;
    int             idx;

    DisplayMenu();
    while (str.empty())
    {
        std::cout << "Index du contact : ";
        std::getline(std::cin, str);
        if (std::cin.eof()) {
            break;
        }
    }
    idx = std::atoi(str.c_str());
    if (idx >= 1 && idx <= this->nb_contact)
    {
        std::cout << this->contact[idx - 1].getName() << std::endl;
        std::cout << this->contact[idx - 1].getLastName() << std::endl;
        std::cout << this->contact[idx - 1].getNickName() << std::endl;
        std::cout << this->contact[idx - 1].getPhoneNumber() << std::endl;
        std::cout << this->contact[idx - 1].getDarkestSecret() << std::endl;
    }
    else if (idx >= 1 && idx <= 8)
        std::cout << "Aucun contact enregistré." << std::endl;
    else
        std::cout << "Indiquer une valeur entre 1 et 8." << std::endl;
}