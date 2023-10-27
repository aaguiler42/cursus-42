/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler < aaguiler@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:12:13 by aaguiler          #+#    #+#             */
/*   Updated: 2023/02/11 21:20:02 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
private:
  std::vector<int> _vec;
  unsigned int _n;
  Span(void);

public:
  Span(unsigned int n);
  Span(Span const &obj);
  ~Span(void);
  Span &operator=(Span const &obj);

  void addNumber(int n);
  int shortestSpan(void);
  int longestSpan(void);
  void addRange(int start, int end);

  class SpanFullException : public std::exception
  {
    public:
      virtual const char* what() const throw();
  };
  class SpanNoSpanException : public std::exception
  {
    public:
      virtual const char* what() const throw();
  };
};

#endif
