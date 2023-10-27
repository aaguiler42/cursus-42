#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <stack>

class RPN {
  public:
    RPN(void);
    RPN(RPN const &src);
    ~RPN(void);

    void	calculate(char *formula);

    RPN &operator=(RPN const &rhs);
  private:
    std::stack<float>  _stack;
};

#endif