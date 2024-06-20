#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    // member functions
    void executeAction() const;
    AForm* makeCopy(const std::string& target) const;
public:
    // orthodox canonical form
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& ob);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& ob);

	// constructor
    RobotomyRequestForm(std::string const& target);
};

#endif