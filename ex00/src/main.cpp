#include "Bureaucrat.hpp"

void test_bureaucrat_orthodox_canonical_form()
{
    std::cout << "wwwwwwwwwwwww test_Bureaucrat wwwwwwwwwwwww" << std::endl;
    std::cout << "=== orthodox canonical form ===" << std::endl;
    Bureaucrat a;
    Bureaucrat b(a);
    Bureaucrat c;
    c = a;
}

void test_normal_constructor()
{
    std::cout << "wwwwwwwwwwwww test_normal_constructor wwwwwwwwwwwww" << std::endl;
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

void test_too_high_constructor()
{
    std::cout << "wwwwwwwwwwwww test_too_high_constructor wwwwwwwwwwwww" << std::endl;
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

void test_increment()
{
    std::cout << "wwwwwwwwwwwww test_increment wwwwwwwwwwwww" << std::endl;
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

void test_decrement()
{
    std::cout << "wwwwwwwwwwwww test_decrement wwwwwwwwwwwww" << std::endl;
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
void test_too_low_constructor()
{
    std::cout << "wwwwwwwwwwwww test_too_low_constructor wwwwwwwwwwwww" << std::endl;
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
int main()
{
    test_bureaucrat_orthodox_canonical_form();
    test_normal_constructor();
    test_too_high_constructor();
    test_too_low_constructor();
    test_increment();
    test_decrement();
}