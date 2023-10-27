/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:18:27 by aaguiler          #+#    #+#             */
/*   Updated: 2022/11/06 19:20:03 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a = ClapTrap("One");

	for (int i = 0; i < 5; i++)
		a.attack("Two");
	for (int i = 0; i < 5; i++)
		a.takeDamage(2);
	for (int i = 0; i < 5; i++)
		a.beRepaired(2);
	for (int i = 0; i < 5; i++)
		a.attack("Two");
	return (0);
}