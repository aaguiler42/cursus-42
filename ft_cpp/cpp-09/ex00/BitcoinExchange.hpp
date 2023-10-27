#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <stdexcept>
# include <fstream>
# include <map>

class BitcoinExchange
{
  public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &src);
    ~BitcoinExchange();

    BitcoinExchange &operator=(BitcoinExchange const &rhs);

    int readFile(char *filename);

  private:
    std::map<std::string, float> exchange_rates;
    int readData();
    int checkDate(std::string date);

};

#endif
