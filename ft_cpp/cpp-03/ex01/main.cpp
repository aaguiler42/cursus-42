/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:18:27 by aaguiler          #+#    #+#             */
/*   Updated: 2022/11/12 09:44:21 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a = ScavTrap("One");

	for (int i = 0; i < 5; i++)
		a.attack("Two");
	for (int i = 0; i < 5; i++)
		a.takeDamage(2);
	for (int i = 0; i < 5; i++)
		a.beRepaired(2);
	for (int i = 0; i < 5; i++)
		a.attack("Two");
	a.guardGate();
	return (0);
}