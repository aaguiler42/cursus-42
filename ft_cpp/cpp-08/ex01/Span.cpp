/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler < aaguiler@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:13:44 by aaguiler          #+#    #+#             */
/*   Updated: 2023/02/11 21:20:13 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(Span const &obj)
{
  *this = obj;
}

Span::~Span(void)
{
}

Span &Span::operator=(Span const &obj)
{
  if (this != &obj)
  {
    this->_n = obj._n;
    this->_vec = obj._vec;
  }
  return *this;
}

void Span::addNumber(int n)
{
  if (this->_vec.size() >= this->_n)
    throw Span::SpanFullException();
  this->_vec.push_back(n);
}

void Span::addRange(int start, int end)
{
  if (start > end)
    std::swap(start, end);
  for (int i = start; i <= end; i++)
    this->addNumber(i);
}

int Span::shortestSpan(void)
{
  if (this->_vec.size() <= 1)
    throw Span::SpanNoSpanException();
  std::vector<int> vec = this->_vec;
  std::sort(vec.begin(), vec.end());
  int min = vec[1] - vec[0];
  for (unsigned int i = 1; i < vec.size() - 1; i++)
  {
    if (vec[i + 1] - vec[i] < min)
      min = vec[i + 1] - vec[i];
  }
  return min;
}

int Span::longestSpan(void)
{
  if (this->_vec.size() <= 1)
    throw Span::SpanNoSpanException();
  std::vector<int> vec = this->_vec;
  std::sort(vec.begin(), vec.end());
  return vec[vec.size() - 1] - vec[0];
}

const char* Span::SpanFullException::what() const throw()
{
  return "Span is full";
}

const char* Span::SpanNoSpanException::what() const throw()
{
  return "Span has no span";
}
