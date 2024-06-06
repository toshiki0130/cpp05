#include "Bureaucrat.hpp"
#include "Form.hpp"
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

/* ===================================
 *           test for Form 
 * ===================================*/
void test_form_orthodox_canonical_form()
{
    std::cout << "wwwww test_form_orthodox_canonical_form wwwwww" << std::endl;
    std::cout << "=== orthodox canonical form ===" << std::endl;
    Form a;
    Form b(a);
    Form c;
    c = a;
}

void test_form_normal_constructor()
{
    std::cout << "wwwwwwwwwwwww test_form_normal_constructor wwwwwwwwwwwww" << std::endl;
    std::cout << "=== default constructor ===" << std::endl;
    try
    {
        Form a;
        std::cout << a << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "=== normal constructor, grdes are between 1 to 150 ===" << std::endl;
    try
    {
        /* do some stuff with bureaucrats */
        Form a("highest", 1, 1);
        std::cout << a << std::endl;
        Form b("middle", 75, 75);
        std::cout << b << std::endl;
        Form c("lowest", 150, 150);
        std::cout << c << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test_form_too_high_constructor()
{
    std::cout << "wwwwww test_form_too_high_constructor wwwwww" << std::endl;
    std::cout << "=== too high gradeToSign ===" << std::endl;
    try
    {
        Form a("too_high_gradeToSign", 0, 1);
        std::cout << a << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "=== too high gradeToExecute ===" << std::endl;
    try
    {
        Form a("too_high_gradeToExecute", 1, 0);
        std::cout << a << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test_form_too_low_constructor()
{
    std::cout << "wwwwww test_form_too_low_constructor wwwwww" << std::endl;
    std::cout << "=== too low gradeToSign ===" << std::endl;
    try
    {
        Form a("too_low_gradeToSign", 151, 150);
        std::cout << a << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "=== too low gradeToExecute ===" << std::endl;
    try
    {
        Form a("too_low_gradeToExecute", 150, 151);
        std::cout << a << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test_form_getters()
{
    std::cout << "wwwwww test_form_getters wwwwww" << std::endl;
    std::cout << "=== getName() ===" << std::endl;
    {
        Form a("Toshiki", 1, 1);
        assert((a.getName() == "Toshiki"));
    }
    std::cout << "=== getIsSigned() ===" << std::endl;
    {
        Form a("Toshiki", 1, 1);
        assert((a.getIsSigned() == false));
    }
    std::cout << "=== getGradeToSign() ===" << std::endl;
    {
        Form a("Toshiki", 1, 1);
        assert((a.getGradeToSign() == 1));
    }
    std::cout << "=== getGradeToExecute()) ===" << std::endl;
    {
        Form a("Toshiki", 1, 1);
        assert((a.getGradeToExecute() == 1));
    }
}

void test_form_besigned()
{
    std::cout << "wwwwww test_form_besigned wwwwww" << std::endl;
    std::cout << "=== case of success ===" << std::endl;
    {
        try
        {
            Bureaucrat b("Joh", 1);
            Form a("Toshiki", 1, 150);
            a.beSigned(b);
            assert((a.getIsSigned() == true));
        }
        catch( std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            Bureaucrat b("Joh", 150);
            Form a("Toshiki", 150, 150);
            a.beSigned(b);
            assert((a.getIsSigned() == true));
        }
        catch( std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "=== case of fail ===" << std::endl;
        try
        {
            Bureaucrat b("Joh", 2);
            Form a("Toshiki", 1, 150);
            a.beSigned(b);
            assert((a.getIsSigned() == true));
        }
        catch( std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            Bureaucrat b("Joh", 150);
            Form a("Toshiki", 149, 150);
            a.beSigned(b);
            assert((a.getIsSigned() == true));
        }
        catch( std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void test_bureaucrat_signform()
{
    std::cout << "wwwwww test_bureaucrat_sign_form wwwwww" << std::endl;
    {
        std::cout << "=== get form, which was already signed ===" << std::endl;
        Bureaucrat b("Toshiki", 1);
        Form a("signed", 150, 150);
        a.beSigned(b);
        b.signForm(a);
    }
    {
        std::cout << "=== get form, which is not still signed ===" << std::endl;
        Bureaucrat b("Toshiki", 1);
        Form a("signed", 150, 150);
        b.signForm(a);
        assert((a.getIsSigned() == true));
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

    // test for form
    test_form_orthodox_canonical_form();
    test_form_normal_constructor();
    test_form_too_high_constructor();
    test_form_too_low_constructor();
    test_form_getters();
    test_form_besigned();

    // test for Bureaucrat
    test_bureaucrat_signform();


}