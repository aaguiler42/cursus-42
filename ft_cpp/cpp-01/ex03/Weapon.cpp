/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:45:51 by aaguiler          #+#    #+#             */
/*   Updated: 2022/10/30 16:51:06 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->_type = type;
}

Weapon::~Weapon(void) {
}

const std::string& Weapon::getType(void) const {
	const std::string& type = this->_type;
	return type;
}

void Weapon::setType(std::string type) {
	this->_type = type;
}