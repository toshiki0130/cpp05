#include "PresidentialPardonForm.hpp"
#include <fstream>
#define FORM_NAME "Presidential Pardon Form"
#define GRADE_TO_SIGN 25
#define GRADE_TO_EXEC 5

/* ===================================
 * The orthodox canonical class form
 * ===================================*/
// default constructor  
PresidentialPardonForm::PresidentialPardonForm()
    : AForm(FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXEC, "default")
{
#if DEBUG
    std::cout << "[PresidentParon default constructor is called]" << std::endl;
#endif
}

// copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ob)
    : AForm(ob)
{
#if DEBUG
    std::cout << "[PresidentPardon copy constructor is called]" << std::endl;
#endif
}

// destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
#if DEBUG
    std::cout << "[PresidentPardon destructor is called]" << std::endl;
#endif
}

// assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ob)
{
#if DEBUG
    std::cout << "[PresidentPardon assignment operator is called]" << std::endl;
#endif
    AForm::operator=(ob);
    return *this;
}

/* ===================================
 *           member functions 
 * ===================================*/
// constructor
PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
    : AForm(FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXEC, target)
{
    std::cout << "[PresidentPardon constructor is called] " << std::endl;
}

void PresidentialPardonForm::executeAction() const
{
#if DEBUG
    std::cout << "[PresidentPardon executeAction() is called]" << std::endl;
#endif
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

AForm* PresidentialPardonForm::makeCopy(const std::string& target) const
{
    return new PresidentialPardonForm(target);
}