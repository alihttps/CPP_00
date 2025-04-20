#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->index = 0;
    this->countact_cnt = 0;
}
int check_input(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if(!isdigit(str[i]))
            return (false);
    }
    return (true);
}
void PhoneBook::get_contacts(int index)
{
    std::string field;
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    std::cout << "|" << "Index     " << "|";
    std::cout << "First name" << "|";
    std::cout << "Last name " << "|";
    std::cout << "Nickname  " << "|" << std::endl;
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    for (int i = 0; i < index; i++)
    {
        std::cout << "|" << i << "         " << "|";
        field = PhoneBook::contact[i].get_firstname();
        (field.length() > 9) ? field = field.substr(0,9) + "." : field = field + std::string(10 - field.length(), ' ');
        std::cout << field << "|";
        field = PhoneBook::contact[i].get_lastname();
        (field.length() > 9) ? field = field.substr(0,9) + "." : field = field + std::string(10 - field.length(), ' ');
        std::cout << field << "|";
        field = PhoneBook::contact[i].get_nickname();
        (field.length() > 9) ? field = field.substr(0,9) + "." : field = field + std::string(10 - field.length(), ' ');
        std::cout << field << "|";
        std::cout << std::endl;
        std::cout << "+----------+----------+----------+----------+" << std::endl;
    }
    search:
    std::string input;
    std::cout << "index to search (0..7) : ";
    std::getline(std::cin, input);
    if (std::cin.eof())
        return;
    if (input.empty())
        return;
    int id = atoi(input.c_str());
    if (!check_input(input) || id < 0 || id > PhoneBook::get_contactcount())
    {
        std::cout << "Contact not found" << std::endl;
        goto search;
    }
    std::cout << "First name : " << PhoneBook::contact[id].get_firstname() << std::endl;
    std::cout << "last name : " << PhoneBook::contact[id].get_lastname() << std::endl;
    std::cout << "nickname : " << PhoneBook::contact[id].get_nickname() << std::endl;
    std::cout << "Phone number : " << PhoneBook::contact[id].get_phonenumber() << std::endl;
    std::cout << "Darkest secret : " << PhoneBook::contact[id].get_darkestsecter() << std::endl;
    
}
const bool validate_input(const std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if(!isprint(str[i]))
            return (true);
    }
    return (false);
}

void PhoneBook::add_to_list(int index)
{
    std::string input;
    fname :
    std::cout << "First name : ";
    std::getline(std::cin, input);
    if(std::cin.eof())
        return ;
    if (input.empty() || validate_input(input))
        goto fname;
    PhoneBook::contact[index].set_firstname(input);
    lname :
    std::cout << "Last name : ";
    std::getline(std::cin, input);
    if(std::cin.eof())
        return ;
    if (input.empty() || validate_input(input))
        goto lname;
    PhoneBook::contact[index].set_lastname(input);
    nname :
    std::cout << "Nickname : ";
    std::getline(std::cin, input);
    if(std::cin.eof())
        return ;
    if (input.empty() || validate_input(input))
        goto nname;
    PhoneBook::contact[index].set_nickname(input);
    number :
    std::cout << "Phone number : ";
    std::getline(std::cin, input);
    if(std::cin.eof())
        return ;
    if (input.empty() || validate_input(input))
        goto number;
    PhoneBook::contact[index].set_phonenumber(input);
    secret :
    std::cout << "Darkest secret : ";
    std::getline(std::cin, input);
    if(std::cin.eof())
        return ;
    if (input.empty() || validate_input(input))
        goto secret;
    PhoneBook::contact[index].set_darkestsecter(input);
}
void PhoneBook::set_index(int index)
{
    this->index = index;
}
void PhoneBook::set_contactcount(int contact_count)
{
    this->countact_cnt = contact_count;
}

int PhoneBook::get_index()
{
    return this->index;
}
int PhoneBook::get_contactcount()
{
    return this->countact_cnt;
}

PhoneBook::~PhoneBook()
{
}