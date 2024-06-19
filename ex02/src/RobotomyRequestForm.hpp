#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    // member functions
    void executeAction() const;
public:
    // orthodox canonical form
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& ob);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& ob);

	// constructor
    explicit RobotomyRequestForm(std::string const& target);
};

#endif