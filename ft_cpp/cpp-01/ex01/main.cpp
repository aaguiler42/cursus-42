/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:18:51 by aaguiler          #+#    #+#             */
/*   Updated: 2022/10/30 15:48:26 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void){
	int nZombies = 5;
	Zombie* horde = zombieHorde(nZombies, "Juan");
	for (int i = 0; i < nZombies; i++){
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
