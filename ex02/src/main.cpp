#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cassert>
/* ===================================
 *        test for Bureaucrat 
 * ===================================*/
void test_bureaucrat_orthodox_canonical_form()
{
    std::cout << "wwwwww test_bureaucrat_orthodox_canonical_form() wwwwww" << std::endl;
    std::cout << "=== orthodox canonical form ===" << std::endl;
    Bureaucrat a;
    Bureaucrat b(a);
    Bureaucrat c;
    c = a;
}

void test_bureaucrat_normal_constructor()
{
    std::cout << "wwwwww test_bureaucrat_normal_constructor() wwwwww" << std::endl;
    std::cout << "=== default constructor ===" << std::endl;
    try
    {
        /* do some stuff with bureaucrats */
        Bureaucrat a;
        std::cout << a << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "=== normal constructor between 1 to 150 ===" << std::endl;
    try
    {
        /* do some stuff with bureaucrats */
        Bureaucrat a("highest", 1);
        std::cout << a << std::endl;
        Bureaucrat b("middle", 75);
        std::cout << b << std::endl;
        Bureaucrat c("lowest", 150);
        std::cout << c << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test_bureaucrat_too_high_constructor()
{
    std::cout << "wwwwww test_bureaucrat_too_high_constructor wwwwww" << std::endl;
    std::cout << "=== too high constructor ===" << std::endl;
    try
    {
        Bureaucrat a("too_high", 0);
        std::cout << a << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test_bureaucrat_too_low_constructor()
{
    std::cout << "wwwwww test_bureaucrat_too_low_constructor wwwwww" << std::endl;
    std::cout << "=== too low constructor ===" << std::endl;
    try
    {
        Bureaucrat a("too_low", 151);
        std::cout << a << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test_bureaucrat_increment()
{
    std::cout << "wwwwww test_bureaucrat_increment wwwwww" << std::endl;
    std::cout << "=== test increment ===" << std::endl;
    try
    {
        Bureaucrat a("increment", 3);
        std::cout << a << std::endl; // 3
        a.incrementGrade();
        std::cout << a << std::endl; // 2
        a.incrementGrade();
        std::cout << a << std::endl; // 1
        a.incrementGrade();
        std::cout << a << std::endl; // 0
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test_bureaucrat_decrement()
{
    std::cout << "wwwwww test_bureaucrat_decrement wwwwww" << std::endl;
    std::cout << "=== test decrement ===" << std::endl;
    try
    {
        Bureaucrat a("decrement", 148);
        std::cout << a << std::endl; // 148
        a.decrementGrade();
        std::cout << a << std::endl; // 149
        a.decrementGrade();
        std::cout << a << std::endl; // 150
        a.decrementGrade();
        std::cout << a << std::endl; // 151
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}

# include "ShrubberyCreationForm.hpp"

void test_shrubbery_creation_form_orthodox_canonical_form()
{
    std::cout << "wwwwww test_shrubbery_creation_form_orthodox_canonical_form wwwwww" << std::endl;
    std::cout << "=== orthodox canonical form ===" << std::endl;
    ShrubberyCreationForm a;
    ShrubberyCreationForm b(a);
    ShrubberyCreationForm c;
    c = a;
}

void test_shrubbery_creation_form_constructor()
{
    std::cout << "wwwwww test_shrubbery_creation_form_constructor wwwwww" << std::endl;
    std::cout << "=== constructor: case of normal ===" << std::endl;
    try {
        ShrubberyCreationForm a("normal");
        std::cout << a << std::endl;
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void test_shrubbery_creation_form_beSigned()
{
    std::cout << "wwwwww test_shrubbery_creation_form_beSigned wwwwww" << std::endl;
    std::cout << "=== success case ===" << std::endl;
    try {
        Bureaucrat b("Toshiki", 144);
        ShrubberyCreationForm a("normal"); // higher than 145; grade to sign
        a.beSigned(b);
        std::cout << a << std::endl;
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "=== success case2 ===" << std::endl;
    try {
        Bureaucrat b("Toshiki", 145);
        ShrubberyCreationForm a("normal"); // higher than 145; grade to sign
        a.beSigned(b);
        std::cout << a << std::endl;
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "=== fail case ===" << std::endl;
    try {
        Bureaucrat b("Toshiki", 146);
        ShrubberyCreationForm a("normal"); // higher than 145; grade to sign
        a.beSigned(b);
        std::cout << a << std::endl;
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void test_shrubbery_creation_form_execute()
{
    std::cout << "wwwwww test_shrubbery_creation_form_execute wwwwww" << std::endl;
    std::cout << "=== success case ===" << std::endl;
    try {
        Bureaucrat b("Toshiki", 144);
        Bureaucrat c("Takefusa", 136);
        ShrubberyCreationForm a("success1"); // higher than 145, 137; grade to sign, grade to execute 
        a.beSigned(b);
        a.execute(c);
        std::cout << a << std::endl;
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "=== success case2 ===" << std::endl;
    try {
        Bureaucrat b("Toshiki", 144);
        Bureaucrat c("Takefusa", 137);
        ShrubberyCreationForm a("success2"); // higher than 145, 137; grade to sign, grade to execute 
        a.beSigned(b);
        a.execute(c);
        std::cout << a << std::endl;
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "=== success case3 ===" << std::endl;
    try {
        Bureaucrat b("Toshiki", 144);
        Bureaucrat c("Takefusa", 137);
        ShrubberyCreationForm a("success3"); // higher than 145, 137; grade to sign, grade to execute 
        a.beSigned(b);
        c.executeForm(a);
        std::cout << a << std::endl;
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "=== fail case: low grade to execute ===" << std::endl;
    try {
        Bureaucrat b("Toshiki", 144);
        Bureaucrat c("Takefusa", 138);
        ShrubberyCreationForm a("fail1"); // higher than 145, 137; grade to sign, grade to execute 
        a.beSigned(b);
        a.execute(c);
        std::cout << a << std::endl;
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "=== fail case: execute not signed ===" << std::endl;
    try {
        Bureaucrat b("Toshiki", 144);
        Bureaucrat c("Takefusa", 137);
        ShrubberyCreationForm a("fail1"); // higher than 145, 137; grade to sign, grade to execute 
        // a.beSigned(b);
        a.execute(c);
        std::cout << a << std::endl;
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}


int main()
{
    // test for Bureaucrat
    test_bureaucrat_orthodox_canonical_form();
    test_bureaucrat_normal_constructor();
    test_bureaucrat_too_high_constructor();
    test_bureaucrat_too_low_constructor();
    test_bureaucrat_increment();
    test_bureaucrat_decrement();

    // test for ShrubberyCreationForm
    test_shrubbery_creation_form_orthodox_canonical_form();
    test_shrubbery_creation_form_constructor();
    test_shrubbery_creation_form_beSigned();
    test_shrubbery_creation_form_execute();
}