#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>


std::string trim(std::string buffer)
{
    int start = 0;
    while (start < (int)buffer.length() && std::isspace(buffer[start]))
        start++;

    int end = buffer.length() - 1;
    while (end >= 0 && std::isspace(buffer[end])) 
        end--;
    return buffer.substr(start, end - start + 1);
}

int main ()
{
    std::string buffer;
    Contact contact;
    PhoneBook phonebook;
    std::cout << "Welcome to 80's phonebook(ADD ,SEARCH ,EXIT): " << std::endl;
    while (1)
    {
        phonebook.set_index(phonebook.get_index() % 8);
        if (std::cin.eof())
            exit(0);
        std::cout << "phonebook > ";
        std::getline(std::cin, buffer);
        if (trim(buffer) == "ADD")
        {
            phonebook.add_to_list(phonebook.get_index());
            phonebook.set_index(phonebook.get_index() + 1);
            if (phonebook.get_contactcount() < 8)
                phonebook.set_contactcount(phonebook.get_contactcount() + 1);
        }
        if (trim(buffer) == "SEARCH")
        {
            phonebook.get_contacts(phonebook.get_contactcount());
        }
        if (trim(buffer) == "EXIT")
            return 0;
    }
    return 0;
}