#include "RPN.hpp"

static bool isValidExpression(const std::string &expression) {
    for (size_t i = 0; i < expression.length(); ++i) {
        if (!(isdigit(expression[i]) || expression[i] == ' ' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    
    const std::string expression = argv[1];
    if (!isValidExpression(expression)) {
        std::cerr << "Invalid character input" << std::endl;
        return 1;
    }
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " \"RPN_EXPRESSION\"" << std::endl;
        return 1;
    }

    try {
        RPN instance(argv[1]);
    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
