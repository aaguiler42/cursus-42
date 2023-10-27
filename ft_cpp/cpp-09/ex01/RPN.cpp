#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(RPN const &src)
{
  *this = src;
}

RPN::~RPN(void)
{
}

RPN	&RPN::operator=(RPN const &rhs)
{
  if (this != &rhs)
    this->_stack = rhs._stack;
  return (*this);
}

void RPN::calculate(char* formula)
{
  int i = 0;
  while (formula[i])
  {
    if (formula[i] == ' ')
    {
      i++;
      continue ;
    }
    if (formula[i] == '(' || formula[i] == ')' || formula[i] == '.' || formula[i] == ',')
    {
      std::cout << "Error" << std::endl;
      return ;
    }
    if (formula[i] >= '0' && formula[i] <= '9')
    {
      this->_stack.push(formula[i] - '0');
      i++;
      continue ;
    }
    if (this->_stack.empty())
    {
      std::cout << "Error" << std::endl;
      return ;
    }

    float tmp = this->_stack.top();
    float result;

    switch (formula[i])
    {
      case '*':
        this->_stack.pop();
        if (this->_stack.empty())
        {
          std::cout << "Error" << std::endl;
          return ;
        }
        result = this->_stack.top() * tmp;
        this->_stack.pop();
        this->_stack.push(result);
        i++;
        continue ;
      case '+':
        this->_stack.pop();
        if (this->_stack.empty())
        {
          std::cout << "Error" << std::endl;
          return ;
        }
        tmp += this->_stack.top();
        this->_stack.pop();
        this->_stack.push(tmp);
        i++;
        continue ;
      case '-':
        this->_stack.pop();
        if (this->_stack.empty())
        {
          std::cout << "Error" << std::endl;
          return ;
        }
        result = this->_stack.top() - tmp;
        this->_stack.pop();
        this->_stack.push(result);
        i++;
        continue ;
      case '/':
        this->_stack.pop();
        if (this->_stack.empty())
        {
          std::cout << "Error" << std::endl;
          return ;
        }
        if (tmp == 0)
        {
          std::cout << "Error: could not divide by 0" << std::endl;
          return ;
        }
        result = this->_stack.top() / tmp;
        this->_stack.pop();
        this->_stack.push(result);
        i++;
        continue ;
    }
  }
  float finalResult = this->_stack.top();
  this->_stack.pop();
  if (!this->_stack.empty())
  {
    std::cout << "Error" << std::endl;
    return ;
  }
  std::cout << finalResult << std::endl;
}