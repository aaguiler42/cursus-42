/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:14:08 by aaguiler          #+#    #+#             */
/*   Updated: 2022/10/18 19:43:07 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
}

Zombie::Zombie(std::string name){
	this->_name = name;
	this->announce();
}

Zombie::~Zombie(){
	std::cout << this->getName() << " has been destroyed\n";
}

std::string	Zombie::getName(void){
	return this->_name;
}

void	Zombie::announce(void){
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ...\n";
}
