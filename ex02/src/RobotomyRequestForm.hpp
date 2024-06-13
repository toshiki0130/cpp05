#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
    // orthodox canonical form
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& ob);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& ob);

	// constructor
    RobotomyRequestForm(std::string const& target);

    // member functions
    void executeAction() const;
};

#endif