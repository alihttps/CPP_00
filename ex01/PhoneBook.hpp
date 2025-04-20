#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <cstring>
#include "Contact.hpp"

class PhoneBook
{
    private:
        int countact_cnt;
        int index;
        Contact contact[8];
    public:
        void set_index(int index);
        void set_contactcount(int count);
        void set_contact(Contact contact, int i);     
        int get_index();
        int get_contactcount();
        void get_contacts(int index);
        void add_to_list(int id);

        PhoneBook();
        ~PhoneBook();
};


#endif