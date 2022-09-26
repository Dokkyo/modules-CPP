#include "PhoneBook.hpp"
#include "Contact.hpp"

int main( void )
{

    PhoneBook       book(0, 0);
    std::string     str;

    std::cout << "Bienvenue dans votre répertoire. Trois choix disponibles." << std::endl << std::endl;
    std::cout << "Tapez ADD pour ajouter un contact." << std::endl;
    std::cout << "Tapez SEARCH pour afficher la liste et choisir parmis vos contacts." << std::endl;
    std::cout << "Tapez EXIT pour quitter le programme." << std::endl;
    std::cout << "Que souhaitez vous faire ?" << std::endl;

    while (1)
    {
        std::cout << "ADD / SEARCH / EXIT" << std::endl;
        std::getline(std::cin, str);
        if (std::cin.eof()) {
            break;
        }
        if (str == "EXIT")
            break;
        else if (str == "ADD")
        {
            book.newContact();
        }
        else if (str == "SEARCH")
        {
            book.searchContact();
        }
        else
            std::cout << "Commande non reconnu." << std::endl;
    }

    return (0);
}
