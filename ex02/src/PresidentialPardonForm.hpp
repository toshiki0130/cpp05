#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
    // orthodox canonical form
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& ob);
    ~PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm& ob);

	// constructor
    PresidentialPardonForm(std::string const& target);

    // member functions
    void executeAction() const;
};

#endif