#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class   RPN {

    private:
        std::string _expression;

    public:
        RPN(char *expression);
		RPN(RPN const & input);
		RPN const & operator=(RPN const & input);
		~RPN(void);

        std::string getexpression();
        void         evaluateRPN(const std::string &expression);

};

#endif