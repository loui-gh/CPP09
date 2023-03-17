#include "RPN.hpp"

/*default constructor*/
RPN::RPN(char *expression) {

    this->_expression = expression;
    evaluateRPN(_expression);
}

/*copy constructor*/
RPN::RPN(RPN const & input) {

    *this = input;
}

/*Assigment operator*/
RPN const & RPN::operator=(RPN const & input){

    this->~RPN();
    new (this) RPN(input);
    return(*this);
}

RPN::~RPN( void ) {}

void    RPN::evaluateRPN(const std::string &expression) {

    std::stack<int> st;
    std::istringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (st.size() < 2) {
                throw std::runtime_error("Invalid RPN expression.");
            }

            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            int result;

            if (token == "+") {
                result = a + b;
            } else if (token == "-") {
                result = a - b;
            } else if (token == "*") {
                result = a * b;
            } else if (token == "/") {
                if (b == 0) {
                    throw std::runtime_error("Division by zero.");
                }
                result = a / b;
            }

            st.push(result);
        } else {
            st.push(std::strtod(token.c_str(), NULL));
        }
    }

    if (st.size() != 1) {
        throw std::runtime_error("Error");
    }

    std::cout << st.top() << std::endl;
}