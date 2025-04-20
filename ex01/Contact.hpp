#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <cstdlib>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        void set_firstname(std::string fname);
        void set_lastname(std::string lname);
        void set_nickname(std::string nname);
        void set_phonenumber(std::string number);
        void set_darkestsecter(std::string secret);

        std::string get_firstname();
        std::string get_lastname();
        std::string get_nickname();
        std::string get_phonenumber();
        std::string get_darkestsecter();

        Contact();
        ~Contact();
};

#endif
