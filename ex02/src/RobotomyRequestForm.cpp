#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <ctime>
#include <cstdlib>
#define FORM_NAME "Robotomy Request Form"
#define GRADE_TO_SIGN 72 
#define GRADE_TO_EXEC 45

/* ===================================
 * The orthodox canonical class form
 * ===================================*/
// default constructor  
RobotomyRequestForm::RobotomyRequestForm()
    : AForm(FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXEC, "default")
{
#if DEBUG
    std::cout << "[Robotomy default constructor is called]" << std::endl;
#endif
}

// copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ob)
    : AForm(ob)
{
#if DEBUG
    std::cout << "[Robotomy copy constructor is called]" << std::endl;
#endif
}

// destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
#if DEBUG
    std::cout << "[Robotomy destructor is called]" << std::endl;
#endif
}

// assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ob)
{
#if DEBUG
    std::cout << "[Robotomy assignment operator is called]" << std::endl;
#endif
    AForm::operator=(ob);
    return *this;
}

/* ===================================
 *           member functions 
 * ===================================*/
// constructor
RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
    : AForm(FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXEC, target)
{
    std::cout << "[Robotomy constructor is called] " << std::endl;
}

void RobotomyRequestForm::executeAction() const
{
#if DEBUG
    std::cout << "[Robotomy executeAction() is called] " << std::endl;
#endif
    std::cout << "gogogogogogogogogo dodododododododododododo....." << std::endl;
    int randomNumber = std::rand();
    if (randomNumber % 2 == 0) {
        // 偶数の場合の処理
        std::cout <<  getTarget() <<" was robotomized successfully." << std::endl;
    } else {
        // 奇数の場合の処理
        std::cout <<  "Woops...! " << getTarget() <<" was failed to robotomize... sorry" << std::endl;
    }
}