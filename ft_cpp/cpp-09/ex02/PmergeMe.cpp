#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const &src) {*this = src;}

PmergeMe::~PmergeMe(void) {}

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs) {
  if(this != &rhs)
  {
    this->_deque = rhs._deque;
    this->_vector = rhs._vector;
  }
  return (*this);
}

void PmergeMe::insertIntergers(char **argv) {
  for (int i = 0; argv[i] != NULL; i++) {
    this->_vector.push_back(std::atoi(argv[i]));
    this->_deque.push_back(std::atoi(argv[i]));
  }
}

void PmergeMe::setTimer(float time, std::string type) {
  if (type == "vector") {
    this->_timeVector = time;
  } else if (type == "deque") {
    this->_timeDeque = time;
  }
}

void PmergeMe::insertDeque(unsigned int p, unsigned int r) {
  for (unsigned int i = p; i < r; i++) {
    unsigned int tmp = this->_deque[i + 1];
    unsigned int j = i + 1;
    while (j > p && this->_deque[j - 1] > tmp) {
      this->_deque[j] = this->_deque[j - 1];
      j--;
    }
    this->_deque[j] = tmp;
  }
}

void PmergeMe::sortDeque(unsigned int p, unsigned int r) {
  if (p < r) {
    unsigned int q = (p + r) / 2;
    sortDeque(p, q);
    sortDeque(q + 1, r);
    std::inplace_merge(this->_deque.begin() + p, this->_deque.begin() + q + 1, this->_deque.begin() + r + 1);
  } else {
    insertDeque(p, r);
  }
}

void PmergeMe::insertVector(unsigned int p, unsigned int r) {
  for (unsigned int i = p; i < r; i++) {
    unsigned int tmp = this->_vector[i + 1];
    unsigned int j = i + 1;
    while (j > p && this->_vector[j - 1] > tmp) {
      this->_vector[j] = this->_vector[j - 1];
      j--;
    }
    this->_vector[j] = tmp;
  }
}

void PmergeMe::sortVector(unsigned int p, unsigned int r) {
  if (p < r) {
    unsigned int q = (p + r) / 2;
    sortVector(p, q);
    sortVector(q + 1, r);
    std::inplace_merge(this->_vector.begin() + p, this->_vector.begin() + q + 1, this->_vector.begin() + r + 1);
  } else {
    insertVector(p, r);
  }
}

void PmergeMe::displayEnd(void) {
  std::cout << "After: ";

	for (std::vector<unsigned int>::iterator it = this->_vector.begin(); it != this->_vector.end(); ++it)
	{
    std::cout << *it << " ";
	}
  std::cout << std::endl;

  std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector: " << std::fixed << _timeVector * 1000 << " ms" << std::endl;
  std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque: " << std::fixed << _timeDeque * 1000 << " ms" << std::endl;
}
