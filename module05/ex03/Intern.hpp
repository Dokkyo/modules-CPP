#ifndef INTERN_HPP
# define INTERN_HPP

class Intern
{
    public:
    
        Intern();
        Intern(Intern & src);
        Intern& operator=(Intern & rhs);
        ~Intern();

        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Form not found.");
                }
        };

        AForm*  makeForm(std::string name, std::string target);
        AForm*  Shrubbery(std::string target) const;
        AForm*  Robotomy(std::string target) const;
        AForm*  Presidential(std::string target) const;
};


#endif
