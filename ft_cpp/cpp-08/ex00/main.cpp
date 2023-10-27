/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler < aaguiler@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:07:16 by aaguiler          #+#    #+#             */
/*   Updated: 2023/02/11 21:07:24 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
  std::vector<int> v;
  std::list<int> l;

  for (int i = 0; i < 10; i++)
  {
    v.push_back(i);
    l.push_back(i);
  }

  try
  {
    std::cout << "Vector: " << *easyfind(v, 5) << std::endl;
    std::cout << "List: " << *easyfind(l, 5) << std::endl;
    std::cout << "Vector: " << *easyfind(v, 10) << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "Exception: " << e.what() << std::endl;
  }
  return 0;
}