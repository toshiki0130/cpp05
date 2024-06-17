#include "Form.hpp"

/* ===================================
 * The orthodox canonical class form
 * ===================================*/
// default constructor  
Form::Form()
    : _name("[Default]"),
      _isSigned(false),
      _gradeToSign(HIGHEST_GRADE),
      _gradeToExecute(HIGHEST_GRADE)
{
#if DEBUG
    std::cout << "[Form default constructor is called]" << std::endl;
#endif
}

// copy constructor
Form::Form(const Form &f)
    : _name(f._name),
      _isSigned(f._isSigned),
      _gradeToSign(f._gradeToSign),
      _gradeToExecute(f._gradeToExecute)
{
#if DEBUG
    std::cout << "[Form copy constructor is called]" << std::endl;
#endif
}

// destructor
Form::~Form()
{
#if DEBUG
    std::cout << "[Form destructor is called]" << std::endl;
#endif
}

// assignment operator
Form& Form::operator=(const Form& f)
{
#if DEBUG
    std::cout << "[Form assignment operator is called]" << std::endl;
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
Form::Form(std::string const& name, int gradeToSign, int gradeToExecute)
    : _name(name),
      _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute)
{
#if DEBUG
    std::cout << "[Form constructor is called] " << std::endl;
    std::cout << "name-> " << _name << ", "
              << "isSigned->" << _isSigned << ", "
              << "gradeToSign->" << _gradeToSign << ", "
              << "gradeToExecute-> "<< _gradeToExecute << std::endl;
#endif    
    if (_gradeToSign < HIGHEST_GRADE) {
        throw Form::GradeTooHighException(_gradeToSign);
    }
    else if (_gradeToSign > LOWEST_GRADE) {
        throw Form::GradeTooLowException(_gradeToSign);
    } 
    if (_gradeToExecute < HIGHEST_GRADE) {
        throw Form::GradeTooHighException(_gradeToExecute);
    }
    else if (_gradeToExecute > LOWEST_GRADE) {
        throw Form::GradeTooLowException(_gradeToExecute);
    } 
}

// beSigned
void Form::beSigned(const Bureaucrat &ob)
{
#if DEBUG
    std::cout << "[Form beSigned() is called]" << std::endl;
#endif
    if (ob.getGrade() <= _gradeToSign) {
        std::cout << "Now, this form is signed!" << std::endl;
        _isSigned = true;
    }
    else {
        throw Form::GradeTooLowException(ob.getGrade());
    }
}

/* ===================================
 *               Getters 
 * ===================================*/
// getName
std::string Form::getName() const
{
#if DEBUG
    std::cout << "[Form getName() is called]" << std::endl;
#endif
    return _name;
}

// getIsSigned
bool Form::getIsSigned() const
{
#if DEBUG
    std::cout << "[Form getIsSigned() is called]" << std::endl;
#endif
    return _isSigned;
}

// getGradeToSign
int Form::getGradeToSign() const
{
#if DEBUG
    std::cout << "[Form getGradeToSign() is called]" << std::endl;
#endif
    return _gradeToSign;
}

// getGradeToExecute
int Form::getGradeToExecute() const
{
#if DEBUG
    std::cout << "[Form getGradeToExecute() is called]" << std::endl;
#endif
    return _gradeToExecute;
}

/* ===================================
 *       GradeTooHighException 
 * ===================================*/

Form::GradeTooHighException::GradeTooHighException()
    : _reason("The Grade is too high")
{
#if DEBUG
    std::cout << "[Form::GradeTooHighException default constructor is called]" << std::endl;
#endif
}

Form::GradeTooHighException::~GradeTooHighException()
{
#if DEBUG
    std::cout << "[Form::GradeTooHighException destructor is called]" << std::endl;
#endif
}

Form::GradeTooHighException::GradeTooHighException(int grade)
{
    std::ostringstream oss;
    oss << "The Grade is too high: " << grade;
    _reason = oss.str(); 
}

const char *Form::GradeTooHighException::what() const throw()
{
    return _reason.c_str();
}

/* ===================================
 *       GradeTooLowException 
 * ===================================*/

Form::GradeTooLowException::GradeTooLowException()
    : _reason("The Grade is too low")
{
#if DEBUG
    std::cout << "[Form::GradeTooLowException default constructor is called]" << std::endl;
#endif
}

Form::GradeTooLowException::~GradeTooLowException()
{
#if DEBUG
    std::cout << "[Form::GradeTooLowException destructor is called]" << std::endl;
#endif
}

Form::GradeTooLowException::GradeTooLowException(int grade)
{
    std::ostringstream oss;
    oss << "The Grade is too low: " << grade;
    _reason = oss.str(); 
}

const char *Form::GradeTooLowException::what() const throw()
{
    return _reason.c_str();
}

/* ===================================
 *           ostream
 * ===================================*/
std::ostream& operator<<(std::ostream& os, const Form& x)
{
    os << "Form name: " << x.getName() << ", "
       << "Is Signed: " << (x.getIsSigned() ? "signed" : "unsigned") << ", "
       << "grade to sign: " << x.getGradeToSign() << ", "
       << "grade to execute: " << x.getGradeToExecute() << ".";
    return os;
}