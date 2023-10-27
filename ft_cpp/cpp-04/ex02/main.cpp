/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:10:20 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/31 18:35:27 by aaguiler         ###   ########.fr       */
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
	const Animal *animals[3];

	animals[0] = new Dog();
	animals[1] = new Cat();
	// animals[2] = new Animal();

	for (int i = 0; i < 2; i++)
		delete animals[i];

	// atexit(ft_leaks);
	return 0;
}