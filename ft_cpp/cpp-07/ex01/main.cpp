/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:05:44 by aaguiler          #+#    #+#             */
/*   Updated: 2023/02/04 16:21:55 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int func(int x){
	return x + 1;
}

std::string func(std::string x){
	return x + "!";
}

int	main(void){
	int arr[2] = {1, 2};

	iter(arr, 2, func);

	std::cout << arr[0] << " . " << arr[1] << "\n";

	std::string arr2[2] = {"hola", "adios"};

	iter(arr2, 2, func);

	std::cout << arr2[0] << " . " << arr2[1] << "\n";
}
