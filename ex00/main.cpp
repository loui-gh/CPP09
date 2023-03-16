#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    // Ensure the user provided the correct number of arguments
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " input_file" << std::endl;
        return 1;
    }

    BitcoinExchange bitcoin_exchange;
    bitcoin_exchange.read_exchange_rate_file("data.csv");

    //Open the input file and process each line
    std::ifstream input_file(argv[1]);
    std::string input_line;
    std::getline(input_file, input_line);  // skip the header line
    while (std::getline(input_file, input_line)) {
        std::istringstream ss(input_line);
        std::string date_str;
        double value;
        std::getline(ss, date_str, '|');
        //trim the date_str taken from the input.txt file
        date_str.erase(0, date_str.find_first_not_of(" \n\r\t"));
        date_str.erase(date_str.find_last_not_of(" \n\r\t") + 1);
        ss >> value;

        bitcoin_exchange.calculate_value(date_str, value);
    }

    return 0;
}
