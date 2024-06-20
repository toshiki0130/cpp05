#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>

class AForm;

class Intern {
    private:
        static const AForm* _forms[3];
    public:
        // orthodox canonical form
        Intern();
        Intern(const Intern& ob);
        ~Intern();
        Intern& operator=(const Intern& ob);
        // member function
        AForm* makeForm(const std::string& formName, const std::string& target);
};
std::ostream& operator<<(std::ostream& os, const Intern& ob);
#endif