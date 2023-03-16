#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>


typedef std::map<std::string, double> my_map;

class BitcoinExchange {
    public:
        BitcoinExchange(char const *input_text_file);
		BitcoinExchange(BitcoinExchange const & input);
		BitcoinExchange const & operator=(BitcoinExchange const & input);
		~BitcoinExchange(void);

        void                            CalculateValue(char const *input_text_file);
        void                            CreateMap();
        std::map<std::string, double>&  RefMap();

    private:
        std::map<std::string, double> _csvMap;

};

#endif
