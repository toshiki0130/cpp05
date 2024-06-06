#include "Bureaucrat.hpp"

/* ===================================
 * The orthodox canonical class form
 * ===================================*/
// default constructor  
Bureaucrat::Bureaucrat(): _name(""), _grade(LOWEST_GRADE)
{
#if DEBUG
    std::cout << "[Bureaucrat default constructor is called]" << std::endl;
#endif
}
// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &ob): _name(ob._name), _grade(ob._grade)
{
#if DEBUG
    std::cout << "[Bureaucrat copy constructor is called]" << std::endl;
#endif
}
// destructor
Bureaucrat::~Bureaucrat()
{
#if DEBUG
    std::cout << "[Bureaucrat destructor is called]" << std::endl;
#endif
}
// assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ob)
{
#if DEBUG
    std::cout << "[Bureaucrat assignment operator is called]" << std::endl;
#endif
    if (this == &ob) return *this;
    //_name = ob._name;
    _grade = ob._grade;
    return *this;
}

/* ===================================
 *           member functions 
 * ===================================*/
// constructor
Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name), _grade(grade)
{
#if DEBUG
    std::cout << "[Bureaucrat constructor is called] " << std::endl;
    std::cout << "name-> " << _name << ", "
              << "grade-> "<< _grade << std::endl;
#endif    
    if (_grade < HIGHEST_GRADE) {
        throw Bureaucrat::GradeTooHighException(_grade);
    }
    else if (_grade > LOWEST_GRADE) {
        throw Bureaucrat::GradeTooLowException(_grade);
    } 

}
// incrementGrade
void Bureaucrat::incrementGrade()
{
#if DEBUG
    std::cout << "[Bureaucrat incrementGrade() is called]" ;
#endif
    if (_grade == HIGHEST_GRADE) {
        throw Bureaucrat::GradeTooHighException(_grade);
    }
    _grade--;
}

// decrementGrade
void Bureaucrat::decrementGrade()
{
#if DEBUG
    std::cout << "[Bureaucrat decrementGrade() is called]" ;
#endif
    if (_grade == LOWEST_GRADE) {
        throw Bureaucrat::GradeTooLowException(_grade);
    }
    _grade++;
}

/* ===================================
 *           getters 
 * ===================================*/
// getName
std::string Bureaucrat::getName() const
{
#if DEBUG
    std::cout << "[Bureaucrat getName() is called]" ;
#endif
    return _name;
}
// getGrade
int Bureaucrat::getGrade() const
{
#if DEBUG
    std::cout << "[Bureaucrat getGrade() is called]";
#endif
    return _grade;
}

/* ===================================
 *           ostream
 * ===================================*/
std::ostream& operator<<(std::ostream& os, const Bureaucrat& x)
{
    os << x.getName() << ", bureaucrat grade " << x.getGrade() << ".";
    return os;
}

/* ===================================
 *       GradeTooHighException 
 * ===================================*/

Bureaucrat::GradeTooHighException::GradeTooHighException()
    : _reason("The Grade is too high")
{
#if DEBUG
    std::cout << "[Bureaucrat::GradeTooHighException default constructor is called]" << std::endl;
#endif
}

Bureaucrat::GradeTooHighException::~GradeTooHighException()
{
#if DEBUG
    std::cout << "[Bureaucrat::GradeTooHighException destructor is called]" << std::endl;
#endif
}

Bureaucrat::GradeTooHighException::GradeTooHighException(int grade)
{
    std::ostringstream oss;
    oss << "The Grade is too high: " << grade;
    _reason = oss.str(); 
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return _reason.c_str();
}

/* ===================================
 *       GradeTooLowException 
 * ===================================*/

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : _reason("The Grade is too low")
{
#if DEBUG
    std::cout << "[Bureaucrat::GradeTooLowException default constructor is called]" << std::endl;
#endif
}

Bureaucrat::GradeTooLowException::~GradeTooLowException()
{
#if DEBUG
    std::cout << "[Bureaucrat::GradeTooLowException destructor is called]" << std::endl;
#endif
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int grade)
{
    std::ostringstream oss;
    oss << "The Grade is too low: " << grade;
    _reason = oss.str(); 

}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return _reason.c_str();
}