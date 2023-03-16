#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

int main(int argc, char* argv[]) {
    // Ensure the user provided the correct number of arguments
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " input_file" << std::endl;
        return 1;
    }

    // Open the exchange rate file and read it into an unordered_map
    std::ifstream file("data.csv");
    std::string line;
    std::map<std::string, double> csvMap;
    std::map<std::string, double>::iterator it;

    // Skip header line
    std::getline(file, line);

    std::string lookup_date = "2012-01-11";
    while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string date;
    double exchange_rate;

    // Read the date and exchange rate from the CSV line
    std::getline(ss, date, ',');
    ss >> exchange_rate;

    // Insert the date and exchange rate into the map
    csvMap.insert(std::make_pair(date, exchange_rate));
    }
    //0Open the input file and process each line
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
        // Lookup the exchange rate for the date and calculate the corresponding value
         // Find the exchange rate for the lookup date in the map
        it = csvMap.find(date_str);
        if (it == csvMap.end()) {//then it hasn't found the exact data string
            it = csvMap.upper_bound(date_str);
            if (it == csvMap.begin()) {
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

    return 0;
}
