#include "BitcoinExchange.hpp"

void BitcoinExchange::read_exchange_rate_file(const std::string& file_path) {
    std::ifstream file(file_path);
    std::string line;
    std::map<std::string, double>::iterator it;

    // Skip header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        double exchange_rate;

        // Read the date and exchange rate from the CSV line
        std::getline(ss, date, ',');
        ss >> exchange_rate;

        // Insert the date and exchange rate into the map
        exchange_rate_map_.insert(std::make_pair(date, exchange_rate));
    }
}

void BitcoinExchange::calculate_value(const std::string& date_str, double value) {
    // Find the exchange rate for the lookup date in the map
    std::map<std::string, double>::iterator it = exchange_rate_map_.find(date_str);
    if (it == exchange_rate_map_.end()) {
        std::cerr << "Error: bad input => " << date_str << std::endl;
        return;
    }

    if (value < 0) {
        std::cout << "Error: not a positive number.\n";
        return;
    }
    if (value > 1000) {
        std::cout << "Error: too large a number.\n";
        return;
    }

    double exchange_rate = it->second;
    double calculated_value = value * exchange_rate;
    std::cout << date_str << " => " << value << " = " << calculated_value << std::endl;
}
