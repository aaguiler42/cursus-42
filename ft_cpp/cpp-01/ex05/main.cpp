/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:56:12 by aaguiler          #+#    #+#             */
/*   Updated: 2022/10/30 17:56:47 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	std::cout << "DEBUG:" << std::endl;
	harl.complain("DEBUG");
	std::cout << "INFO:" << std::endl;
	harl.complain("INFO");
	std::cout << "WARNING:" << std::endl;
	harl.complain("WARNING");
	std::cout << "ERROR:" << std::endl;
	harl.complain("ERROR");
	return (0);
}