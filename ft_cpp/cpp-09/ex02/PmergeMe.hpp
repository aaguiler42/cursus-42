#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <stdexcept>
# include <ctime>
# include <vector>
# include <deque>
# include <algorithm>

class PmergeMe
{
  public:
    PmergeMe(void);
    PmergeMe(PmergeMe const &src);
    ~PmergeMe(void);

    PmergeMe  &operator=(PmergeMe const &rhs);

    void insertIntergers(char **argv);
    void displayEnd(void);
    void setTimer(float time, std::string type);

    void sortDeque(unsigned int p, unsigned int r);
    void sortVector(unsigned int p, unsigned int r);

    void insertDeque(unsigned int p, unsigned int r);
    void insertVector(unsigned int p, unsigned int r);


  private:
    std::vector<unsigned int>  _vector;
    std::deque<unsigned int>   _deque;

    float  _timeVector;
    float  _timeDeque;
};

#endif
