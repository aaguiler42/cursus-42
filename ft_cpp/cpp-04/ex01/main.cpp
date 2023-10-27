/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:10:20 by aaguiler          #+#    #+#             */
/*   Updated: 2022/11/12 11:57:01 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// #include <stdlib.h>
// void	ft_leaks (void)
// {
// 	system("leaks -q a.out");
// }

int main()
{
	const Animal *animals[2];
	
	animals[0] = new Dog();
	animals[1] = new Cat();

	for (int i = 0; i < 2; i++)
		delete animals[i];
	
	// atexit(ft_leaks);
	return 0;
}