#include "ShrubberyCreationForm.hpp"
#include <fstream>
#define FORM_NAME "Shrubbery Creation Form"
#define GRADE_TO_SIGN 145
#define GRADE_TO_EXEC 137

/* ===================================
 * The orthodox canonical class form
 * ===================================*/
// default constructor  
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm(FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXEC, "default")
{
#if DEBUG
    std::cout << "[Shrubberry default constructor is called]" << std::endl;
#endif
}

// copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ob)
    : AForm(ob)
{
#if DEBUG
    std::cout << "[Shrubberry copy constructor is called]" << std::endl;
#endif
}

// destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
#if DEBUG
    std::cout << "[Shrubbery destructor is called]" << std::endl;
#endif
}

// assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ob)
{
#if DEBUG
    std::cout << "[Shrubberry assignment operator is called]" << std::endl;
#endif
    AForm::operator=(ob);
    return *this;
}

/* ===================================
 *           member functions 
 * ===================================*/
// constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
    : AForm(FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXEC, target)
{
    std::cout << "[Shrubbery constructor is called] " << std::endl;
}

void ShrubberyCreationForm::executeAction() const
{
    const std::string filename = getTarget() + "_shrubbery";
    //std::ofstream file((getTarget() + "_shrubbery").c_str()); 
    std::ofstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: Could not open file" << std::endl;
        return ;
    }
    
/*                    v .   ._, |_  .,
            `-._\/  .  \ /    |/_
                \\  _\, y | \//
          _\_.___\\, \\/ -.\||
            `7-,--.`._||  / / ,
            /'     `-. `./ / |/_.'
                      |    |//
                      |_    /
                      |-   |
                      |   =|
                      |    |
 --------------------/ ,  . \--------._



        _-_
     /~~   ~~\\
  /~~         ~~\\
 {               }
  \  _-     -_  /
    ~  \\ //  ~
 _- -   | | _- _
   _ -  | |   -_
       // \\)
*/

    file << "                       v .   ._, |_  .,    " << std::endl;
    file << "            `-._\\/  .  \\ /    |/_    " << std::endl;
    file << "                \\  _\\, y | \\//    " << std::endl;
    file << "          _\\_.___\\, \\/ -.\\||    " << std::endl;
    file << "            `7-,--.`._||  / / ,    " << std::endl;
    file << "            /'     `-. `./ / |/_.'    " << std::endl;
    file << "                      |    |//    " << std::endl;
    file << "                      |_    /    " << std::endl;
    file << "                      |-   |    " << std::endl;
    file << "                      |   =|    " << std::endl;
    file << "                      |    |    " << std::endl;
    file << " --------------------/ ,  . \\--------.      " << std::endl;
    file << std::endl;
    file << "        _-_    " << std::endl;
    file << "     /~~   ~~\\    " << std::endl;
    file << "  /~~         ~~\\    " << std::endl;
    file << " {               }    " << std::endl;
    file << "  \\  _-     -_  /    " << std::endl;
    file << "    ~  \\ //  ~    " << std::endl;
    file << " _- -   | | _- _    " << std::endl;
    file << "   _ -  | |   -_    " << std::endl;
    file << "       // \\    " << std::endl;
    
    file.close();
}