#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
  (void)argv;
  if (argc != 2)
  {
    std::cout << "Usage: ./btc filename" << std::endl;
    return (1);
  }

  BitcoinExchange btc;

  btc.readFile(argv[1]);

  return (0);
}