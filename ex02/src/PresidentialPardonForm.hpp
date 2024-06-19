#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    // member functions
    void executeAction() const;
public:
    // orthodox canonical form
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& ob);
    ~PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm& ob);

	// constructor
    explicit PresidentialPardonForm(std::string const& target);
};

#endif