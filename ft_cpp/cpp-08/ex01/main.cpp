/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler < aaguiler@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:14:33 by aaguiler          #+#    #+#             */
/*   Updated: 2023/02/11 21:22:22 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// void ft_leaks(void)
// {
//   system("leaks -q a.out");
// }

int main(void)
{
  Span sp = Span(5);
  sp.addNumber(5);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  try
  {
    sp.addNumber(11);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  try
  {
    Span sp2 = Span(1);
    sp2.addNumber(11);
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  Span sp3 = Span(1000000);
  sp3.addRange(0, 999999);
  std::cout << sp3.shortestSpan() << std::endl;
  std::cout << sp3.longestSpan() << std::endl;

    try
  {
    Span sp4 = Span(1000000);
    sp4.addRange(0, 1000000);
    std::cout << sp4.shortestSpan() << std::endl;
    std::cout << sp4.longestSpan() << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  return 0;
}