#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
    void executeAction() const;
public:
    // orthodox canonical form
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& ob);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ob);

	// constructor
    ShrubberyCreationForm(std::string const& target);

    // member functions
    AForm* makeCopy(const std::string& target) const;
};

#endif