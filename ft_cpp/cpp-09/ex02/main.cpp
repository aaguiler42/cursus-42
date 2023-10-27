#include "PmergeMe.hpp"

int ft_control_errors(char **argv)
{
  for (int i = 1; argv[i] != NULL; i++)
  {
    if (argv[i][0] == '\0')
    {
      std::cout << "Error\n";
      return (1);
    }
    int j = 0;
    while (argv[i][j] != '\0')
    {
      if (argv[i][j] < '0' || '9' < argv[i][j])
      {
        std::cout << "Error\n";
        return (1);
      }
      j++;
    }
    j = std::atoi(argv[i]);
    if (j < 0 && 2147483647 > j)
    {
      std::cout << "Error\n";
      return (1);
    }
  }
  return(0);
}

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << "usage : ./PmergeMe ...ints\n";
    return (1);
  }

  if (ft_control_errors(argv + 1) == 1)
    return (1);

  PmergeMe swapPush;
  swapPush.insertIntergers(argv + 1);

  std::cout << "Before: ";
  for (int i = 1; argv[i] != NULL; i++)
  {
    std::cout << argv[i] << " ";
  }
  std::cout << std::endl;

  clock_t start;
  clock_t end;
  float time;

  start = clock();
  swapPush.sortVector(0, argc - 2);
  end = clock();
  time = (float)(end - start) / CLOCKS_PER_SEC;
  swapPush.setTimer(time, "vector");

  start = clock();
  swapPush.sortDeque(0, argc - 2);
  end = clock();
  time = (float)(end - start) / CLOCKS_PER_SEC;
  swapPush.setTimer(time, "deque");

  swapPush.displayEnd();
  return (0);
}
