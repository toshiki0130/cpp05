#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class AForm {
private:
    std::string const	_name;
    bool				_isSigned;
    int const			_gradeToSign;
	int const			_gradeToExecute;
	std::string const	_target;
protected:
	virtual void executeAction() const = 0;
public:
	// orthodox canonical form
	AForm();
	AForm(const AForm &ob);
	virtual ~AForm();
	AForm& operator=(const AForm &ob);

	// constructor
	AForm(std::string const& name, int gradeToSign, int gradeToExecute, std::string const& target);

	// member functions
	// 	Add also a beSigned() member function to the Form that takes a Bureaucrat as
	// parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
	// (higher or egal to the required one).
	void beSigned(const Bureaucrat& ob);
	void execute(const Bureaucrat& executor) const;
	// getters: Same as before, write getters for all attributes
	std::string getName() const;
	bool		getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
    std::string getTarget() const; 
	
	virtual AForm* makeCopy(const std::string& target) const = 0;
	// exceptions
	// The grades of the Form follow the same rules that apply to the Bureaucrat. Thus,
	// the following exceptions will be thrown if a form grade is out of bounds:
	// Form::GradeTooHighException and Form::GradeTooLowException.
    class GradeTooHighException : public std::exception {
        private:
            std::string _reason;
        public:
            GradeTooHighException();
            ~GradeTooHighException() throw();
            explicit GradeTooHighException(int grade);
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        private:
            std::string _reason;
        public:
            GradeTooLowException();
            ~GradeTooLowException() throw();
            explicit GradeTooLowException(int grade);
            const char* what() const throw();
    };
	class FormNotSignedException : public std::exception {
		public:
			FormNotSignedException();
			~FormNotSignedException() throw();
			const char* what() const throw();
	};
};

// an overload of the insertion («)
// operator that prints all the form’s informations.
std::ostream& operator<<(std::ostream& os, const AForm& f);


#endif