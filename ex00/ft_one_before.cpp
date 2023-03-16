#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string date = "2011-11-04";

    // Extract the last two characters from the string
    std::string day_str = date.substr(date.length() - 2);

    // Convert the day to an integer and add 1
    std::stringstream ss(day_str);
    int day;
    ss >> day;
    day++;

    // Convert the day back to a string and pad with a leading zero if necessary
    std::string new_day_str;
    if (day < 10) {
        std::stringstream ss;
        ss << "0" << day;
        new_day_str = ss.str();
    }
    else {
        std::stringstream ss;
        ss << day;
        new_day_str = ss.str();
    }

    // Replace the old day in the string with the new day
    std::string new_date = date.substr(0, date.length() - 2) + new_day_str;

    std::cout << "Original date: " << date << std::endl;
    std::cout << "New date: " << new_date << std::endl;

    return 0;
}
