#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <sstream>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

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
    // getters
    std::string getName() const;
    int getGrade() const;

    // exceptions
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
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& x);

#endif