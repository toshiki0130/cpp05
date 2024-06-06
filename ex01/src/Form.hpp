#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Form {
private:
    std::string const	_name;
    bool				_isSigned;
    int const			_gradeToSign;
	int const			_gradeToExecute;
public:
	// orthodox canonical form
	Form();
	Form(const Form &ob);
	~Form();
	Form& operator=(const Form &ob);

	// constructor
	Form(std::string const& name, int gradeToSign, int gradeToExecute);

	// member functions
	// 	Add also a beSigned() member function to the Form that takes a Bureaucrat as
	// parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
	// (higher or egal to the required one).
	void beSigned(const Bureaucrat& ob);
	
	// getters: Same as before, write getters for all attributes
	std::string getName() const;
	bool	getIsSigned() const;
	int		getGradeToSign() const;
	int		getGradeToExecute() const;
    
	// exceptions
	// The grades of the Form follow the same rules that apply to the Bureaucrat. Thus,
	// the following exceptions will be thrown if a form grade is out of bounds:
	// Form::GradeTooHighException and Form::GradeTooLowException.
    class GradeTooHighException : public std::exception {
        private:
            std::string _reason;
        public:
            GradeTooHighException();
            ~GradeTooHighException();
            explicit GradeTooHighException(int grade);
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        private:
            std::string _reason;
        public:
            GradeTooLowException();
            ~GradeTooLowException();
            explicit GradeTooLowException(int grade);
            const char* what() const throw();
    };
};

// an overload of the insertion («)
// operator that prints all the form’s informations.
std::ostream& operator<<(std::ostream& os, const Form& f);


#endif