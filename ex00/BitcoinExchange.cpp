#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char const *input_text_file) {

   CreateMap();
    CalculateValue(input_text_file);
}

/*copy constructor*/
BitcoinExchange::BitcoinExchange(BitcoinExchange const & input) {

    this->_csvMap = input._csvMap;
}

/*Assigment operator*/
BitcoinExchange const & BitcoinExchange::operator=(BitcoinExchange const & input) {
    
    this->~BitcoinExchange();
	new (this) BitcoinExchange(input);
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {

}

void        BitcoinExchange::CreateMap() {

    std::ifstream file("data.csv");
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: data.csv");
    }

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
        _csvMap.insert(std::make_pair(date, exchange_rate));
    }
}

/*to avoid making copies of the map, just create a reference to it
This is my map 'getter' */
std::map<std::string, double>&    BitcoinExchange::RefMap() {

    std::map<std::string, double>& refmap = _csvMap;
    return refmap;
}

void     BitcoinExchange::CalculateValue(char const *input) {

    std::ifstream input_file(input);
    if (!input_file.is_open()) {
        std::string msg0 = "Error: Failed to open ";
        std::string msg1 = input;
        throw std::runtime_error(msg0 + msg1);
    }
    std::string input_line;
    std::getline(input_file, input_line);  // skip the header line
    std::map<std::string, double>::iterator it;
    std::map<std::string, double>& MapRef = RefMap();
    while (std::getline(input_file, input_line)) {
        std::istringstream ss(input_line);
        std::string date_str;
        double value;
        std::getline(ss, date_str, '|');
        //trim the date_str taken from the input.txt file
        date_str.erase(0, date_str.find_first_not_of(" \n\r\t"));
        date_str.erase(date_str.find_last_not_of(" \n\r\t") + 1);
        ss >> value;
        // Lookup the exchange rate for the date and calculate the corresponding value
         // Find the exchange rate for the lookup date in the map
        it = MapRef.find(date_str);
        if (it == MapRef.end()) {//then it hasn't found the exact data string
            it = MapRef.upper_bound(date_str);
            if (it == MapRef.begin()) {
                std::cerr << "Error: bad input => " << date_str << std::endl;
                continue;
            } else {
                --it;
            }
        }
        if (value < 0) {
            std::cout << "Error: not a positive number.\n";
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number.\n";
            continue;
        }
        double exchange_rate = it->second;
        double calculated_value = value * exchange_rate;
        std::cout << date_str << " => " << value << " = " << calculated_value << std::endl;
    }
}