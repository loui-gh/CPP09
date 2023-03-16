#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    // Ensure the user provided the correct number of arguments
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " input_file" << std::endl;
        return 1;
    }

    BitcoinExchange instance(argv[1]);

    return 0;
}
