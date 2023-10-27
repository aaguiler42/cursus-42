/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:18:27 by aaguiler          #+#    #+#             */
/*   Updated: 2022/11/12 09:48:56 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap a = FragTrap("One");

	for (int i = 0; i < 5; i++)
		a.attack("Two");
	for (int i = 0; i < 5; i++)
		a.takeDamage(2);
	for (int i = 0; i < 5; i++)
		a.beRepaired(2);
	for (int i = 0; i < 5; i++)
		a.attack("Two");
	a.highFivesGuys();
	return (0);
}