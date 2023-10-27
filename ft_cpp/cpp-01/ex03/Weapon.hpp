/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:45:48 by aaguiler          #+#    #+#             */
/*   Updated: 2022/10/30 16:56:58 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {

private:
	std::string _type;

public:
	Weapon(std::string type);
	~Weapon(void);
	const std::string& getType(void) const;
	void setType(std::string type);

};

#endif
