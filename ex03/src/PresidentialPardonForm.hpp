#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    // member functions
    void executeAction() const;
    AForm* makeCopy(const std::string& target) const;
public:
    // orthodox canonical form
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& ob);
    ~PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm& ob);

	// constructor
    PresidentialPardonForm(std::string const& target);
};

#endif