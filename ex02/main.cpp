#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [integer_sequence]" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        std::string str = argv[i];
        for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
            if (!isdigit(*it)) {
                std::cerr << "Error\n";
                return 1;
            }
        }
    }
    char* endptr;
    for (int i = 1; i < argc; ++i) {
        long value = std::strtol(argv[i], &endptr, 10);
        if (*endptr != '\0' || value <= 0 || value > std::numeric_limits<int>::max()) {
            std::cerr << "Error\n";
            return 1;
        }
    }

    try {
        PmergeMe instance(argc, argv);
    } catch (const std::runtime_error &e) {
        std::cerr << e.what();
        return 1;
    }

    return 0;
}
