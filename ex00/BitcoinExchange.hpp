#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange {
    public:
        BitcoinExchange(char const *);
		BitcoinExchange(BitcoinExchange const & input);
		BitcoinExchange const & operator=(BitcoinExchange const & input);
		~BitcoinExchange(void);

    private:
        std::map<std::string, double> _exchange_rate_map;
};

#endif
