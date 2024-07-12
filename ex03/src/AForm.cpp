#include "AForm.hpp"

/* ===================================
 * The orthodox canonical class form
 * ===================================*/
// default constructor  
AForm::AForm()
    : _name("[Default]"),
      _isSigned(false),
      _gradeToSign(HIGHEST_GRADE),
      _gradeToExecute(HIGHEST_GRADE),
      _target("[Default]")
{
#if DEBUG
    std::cout << "[AForm default constructor is called]" << std::endl;
#endif
}

// copy constructor
AForm::AForm(const AForm &f)
    : _name(f._name),
      _isSigned(f._isSigned),
      _gradeToSign(f._gradeToSign),
      _gradeToExecute(f._gradeToExecute),
      _target(f._target)
{
#if DEBUG
    std::cout << "[AForm copy constructor is called]" << std::endl;
#endif
}

// destructor
AForm::~AForm()
{
#if DEBUG
    std::cout << "[AForm destructor is called]" << std::endl;
#endif
}

// assignment operator
AForm& AForm::operator=(const AForm& f)
{
#if DEBUG
    std::cout << "[AForm assignment operator is called]" << std::endl;
#endif
    if (this != &f) {
        _isSigned = f._isSigned;
    }
    return *this;
}

/* ===================================
 *           member functions 
 * ===================================*/
// constructor
AForm::AForm(std::string const& name, int gradeToSign, int gradeToExecute, std::string const& target)
    : _name(name),
      _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute),
      _target(target)
{
#if DEBUG
    std::cout << "[AForm constructor is called] " << std::endl;
    std::cout << "name-> " << _name << ", "
              << "isSigned->" << _isSigned << ", "
              << "gradeToSign->" << _gradeToSign << ", "
              << "gradeToExecute-> "<< _gradeToExecute << std::endl;
#endif    
    if (_gradeToSign < HIGHEST_GRADE) {
        throw AForm::GradeTooHighException(_gradeToSign);
    }
    else if (_gradeToSign > LOWEST_GRADE) {
        throw AForm::GradeTooLowException(_gradeToSign);
    } 
    if (_gradeToExecute < HIGHEST_GRADE) {
        throw AForm::GradeTooHighException(_gradeToExecute);
    }
    else if (_gradeToExecute > LOWEST_GRADE) {
        throw AForm::GradeTooLowException(_gradeToExecute);
    } 
}

// beSigned
void AForm::beSigned(const Bureaucrat &ob)
{
#if DEBUG
    std::cout << "[AForm beSigned() is called]" << std::endl;
#endif
    if (ob.getGrade() <= _gradeToSign) {
        std::cout << "Now, this form is signed!" << std::endl;
        _isSigned = true;
    }
    else {
        throw AForm::GradeTooLowException(ob.getGrade());
    }
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (_isSigned == false)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException(executor.getGrade());
    executeAction();
}

/* ===================================
 *               Getters 
 * ===================================*/
// getName
std::string AForm::getName() const
{
#if DEBUG
    std::cout << "[AForm getName() is called]" << std::endl;
#endif
    return _name;
}

// getIsSigned
bool AForm::getIsSigned() const
{
#if DEBUG
    std::cout << "[AForm getIsSigned() is called]" << std::endl;
#endif
    return _isSigned;
}

// getGradeToSign
int AForm::getGradeToSign() const
{
#if DEBUG
    std::cout << "[AForm getGradeToSign() is called]" << std::endl;
#endif
    return _gradeToSign;
}

// getGradeToExecute
int AForm::getGradeToExecute() const
{
#if DEBUG
    std::cout << "[AForm getGradeToExecute() is called]" << std::endl;
#endif
    return _gradeToExecute;
}

// getTarget
std::string AForm::getTarget() const
{
#if DEBUG
    std::cout << "[AForm getTarget() is called]" << std::endl;
#endif
    return _target;
}

/* ===================================
 *       GradeTooHighException 
 * ===================================*/

AForm::GradeTooHighException::GradeTooHighException()
    : _reason("The Grade is too high")
{
#if DEBUG
    std::cout << "[AForm::GradeTooHighException default constructor is called]" << std::endl;
#endif
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
#if DEBUG
    std::cout << "[AForm::GradeTooHighException destructor is called]" << std::endl;
#endif
}

AForm::GradeTooHighException::GradeTooHighException(int grade)
{
    std::ostringstream oss;
    oss << "The Grade is too high: " << grade;
    _reason = oss.str(); 
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return _reason.c_str();
}

/* ===================================
 *       GradeTooLowException 
 * ===================================*/

AForm::GradeTooLowException::GradeTooLowException()
    : _reason("The Grade is too low")
{
#if DEBUG
    std::cout << "[AForm::GradeTooLowException default constructor is called]" << std::endl;
#endif
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
#if DEBUG
    std::cout << "[AForm::GradeTooLowException destructor is called]" << std::endl;
#endif
}

AForm::GradeTooLowException::GradeTooLowException(int grade)
{
    std::ostringstream oss;
    oss << "The Grade is too low: " << grade;
    _reason = oss.str(); 

}

const char *AForm::GradeTooLowException::what() const throw()
{
    return _reason.c_str();
}

/* ===================================
 *       FormNotSignedException 
 * ===================================*/
AForm::FormNotSignedException::FormNotSignedException()
{
#if DEBUG
    std::cout << "[AForm::FormNotSignedException default constructor is called]" << std::endl;
#endif
}

AForm::FormNotSignedException::~FormNotSignedException() throw()
{
#if DEBUG
    std::cout << "[AForm::FormNotSignedException destructor is called]" << std::endl;
#endif
}

const char* AForm::FormNotSignedException::what() const throw()
{
#if DEBUG
    std::cout << "[AForm::FormNotSignedException dwhat() is called]" << std::endl;
#endif
    return "This form is not signed!";
}

/* ===================================
 *           ostream
 * ===================================*/
std::ostream& operator<<(std::ostream& os, const AForm& x)
{
    os << "Form name: " << x.getName() << ", "
       << "Is Signed?: " << (x.getIsSigned() ? "signed" : "unsigned") << ", "
       << "grade to sign: " << x.getGradeToSign() << ", "
       << "grade to execute: " << x.getGradeToExecute() << ", " 
       << "target: " << x.getTarget() << ".";
    return os;
}