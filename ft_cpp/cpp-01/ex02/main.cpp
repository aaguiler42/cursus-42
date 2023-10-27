/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:52:31 by aaguiler          #+#    #+#             */
/*   Updated: 2022/10/30 16:00:36 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void){
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR= &string;
	std::string &stringREF = string;

	std::cout << "Memory address of string: " << &string << std::endl;
	std::cout << "Memory address ofstringPTR: " << &stringPTR<< std::endl;
	std::cout << "Memory address of stringREF: " << &stringREF << std::endl;

	std::cout << "Value of string: " << string << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;
}