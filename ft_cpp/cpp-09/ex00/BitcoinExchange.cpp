#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
  if (readData())
    exit(1);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
  *this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
  if (this != &rhs)
  {
  }
  return (*this);
}

int BitcoinExchange::readData()
{
  std::ifstream file("data.csv");

  if (!file.is_open())
  {
    std::cout << "Unable to open data.csv" << std::endl;
    return (1);
  }

  std::string line;
  while (getline(file, line)) {
    if (line.empty())
      continue;
    size_t commaPos = line.find(',');
    if (commaPos != std::string::npos) {
      std::string date = line.substr(0, commaPos);
      float rate = std::atof(line.substr(commaPos + 1).c_str());
      if (date != "" && rate > 0)
        this->exchange_rates[date] = rate;
    }
  }
  file.close();

  // for(std::map<std::string, float>::iterator it = this->exchange_rates.begin(); it != this->exchange_rates.end(); ++it) {
  //   std::cout << it->first << " => " << it->second << '\n';
  // }
  return (0);
}

int BitcoinExchange::checkDate(std::string date)
{
  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());

  if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
    return (1);
  
  int firstYearStored = atoi(this->exchange_rates.begin()->first.substr(0, 4).c_str());
  int lastYearStored = atoi(this->exchange_rates.rbegin()->first.substr(0, 4).c_str());
  if (year < firstYearStored || year > lastYearStored)
    return (1);

  int firstMonthStored = atoi(this->exchange_rates.begin()->first.substr(5, 2).c_str());
  int lastMonthStored = atoi(this->exchange_rates.rbegin()->first.substr(5, 2).c_str());
  if (year == firstYearStored && month < firstMonthStored)
    return (1);
  if (year == lastYearStored && month > lastMonthStored)
    return (1);

  int firstDayStored = atoi(this->exchange_rates.begin()->first.substr(8, 2).c_str());
  int lastDayStored = atoi(this->exchange_rates.rbegin()->first.substr(8, 2).c_str());
  if (year == firstYearStored && month == firstMonthStored && day < firstDayStored)
    return (1);
  if (year == lastYearStored && month == lastMonthStored && day > lastDayStored)
    return (1);

  return (0);
}

int BitcoinExchange::readFile(char *filename)
{
  std::ifstream file(filename);

  if (!file.is_open())
  {
    std::cout << "Unable to open file" << std::endl;
    return (1);
  }
  if (this->exchange_rates.empty())
  {
    std::cout << "Error: no data." << std::endl;
    return (1);
  }

  std::string line;
  getline(file, line); //first line is not a date, val
  while (getline(file, line)) {
    if (line.empty())
      continue ;
    size_t barPos = line.find('|');
    std::string date = line.substr(0, barPos);
    if (barPos == std::string::npos || checkDate(date))
      std::cout << "Error: bad input => " << date << std::endl;
    else {
      float amount = std::atof(line.substr(barPos + 1).c_str());
      if (amount < 0)
        std::cout << "Error: not a positive number." << std::endl;
      else if (amount > 1000)
        std::cout << "Error: too large a number." << std::endl;
      else
      {
        std::map<std::string, float>::iterator it;
        it = this->exchange_rates.find(date);
        if (it == this->exchange_rates.end())
        {
          it = this->exchange_rates.begin();
          while (date > it->first && it != this->exchange_rates.end())
            ++it;
          it--;
        }
        std::cout << date << " => " << amount << " = " << amount * (it->second) << std::endl;
      }
    }
  }
  file.close();
  return (0);
}