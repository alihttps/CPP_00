#include "Contact.hpp"

Contact::Contact()
{
}
void Contact::set_firstname(std::string fname)
{
    this->first_name = fname;
}
void Contact::set_lastname(std::string lname)
{
    this->last_name = lname;
}
void Contact::set_nickname(std::string nname)
{
    this->nickname = nname;
}

void Contact::set_phonenumber(std::string number)
{
    this->phone_number = number;
}

void Contact::set_darkestsecter(std::string secret)
{
    this->darkest_secret = secret;
}

std::string Contact::get_firstname()
{
    return this->first_name;
}
std::string Contact::get_lastname()
{
    return this->last_name;
}
std::string Contact::get_nickname()
{
    return this->nickname;
}

std::string Contact::get_phonenumber()
{
    return this->phone_number;
}

std::string Contact::get_darkestsecter()
{
    return this->darkest_secret;
}

Contact::~Contact()
{
}