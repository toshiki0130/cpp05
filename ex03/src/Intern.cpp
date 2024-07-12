#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const AForm* Intern::_forms[3] = {
    new ShrubberyCreationForm(),
    new RobotomyRequestForm(),
    new PresidentialPardonForm()
};

/* ===================================
 * The orthodox canonical class form
 * ===================================*/
// default constructor  
Intern::Intern()
{
#if DEBUG
    std::cout << "[Intern default constructor is called]" << std::endl;
#endif
}
// copy constructor
Intern::Intern(const Intern &ob)
{
#if DEBUG
    std::cout << "[Intern copy constructor is called]" << std::endl;
#endif
    (void)ob;
}
// destructor
Intern::~Intern()
{
#if DEBUG
    std::cout << "[Intern destructor is called]" << std::endl;
#endif
}
// assignment operator
Intern& Intern::operator=(const Intern &ob)
{
#if DEBUG
    std::cout << "[Intern assignment operator is called]" << std::endl;
#endif
    (void)ob;
    return *this;
}

/* ===================================
 *           member functions 
 * ===================================*/
// makeForm
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    for (size_t i = 0; i < sizeof(_forms) / sizeof(*_forms); i++) {
        if (formName == _forms[i]->getName()) {
            std::cout <<  "Intern creates " << formName << std::endl;
            return _forms[i]->makeCopy(target);
        }
    }
    std::cout << "Intern can't make form" << std::endl;
    return NULL;
}

/* ===================================
 *           ostream
 * ===================================*/
std::ostream& operator<<(std::ostream& os, const Intern& x)
{
    (void)x;
    os << "I am Intern"; 
    return os;
}