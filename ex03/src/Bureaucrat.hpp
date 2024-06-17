#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <sstream>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class AForm;

class Bureaucrat {
private:
    std::string const _name;
    int _grade;
public:
    // The orthodox canonical class form
    Bureaucrat();
    Bureaucrat(const Bureaucrat &ob);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat &ob);
    
    // member functions
    Bureaucrat(std::string const &name, int grade);
    void incrementGrade();
    void decrementGrade();

    // Lastly, add a signForm() member function to the Bureaucrat. If the form got signed,
    // it will print something like:
    // <bureaucrat> signed <form>
    // Otherwise, it will print something like:
    // <bureaucrat> couldn’t sign <form> because <reason>.
    void signForm(AForm &f) const;
    void executeForm(AForm const& form) const;
    
    // getters
    std::string getName() const;
    int getGrade() const;

    // exceptions
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& x);

#endif