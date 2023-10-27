/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:17:53 by aaguiler          #+#    #+#             */
/*   Updated: 2023/02/04 14:00:38 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

// #include <stdlib.h>
// void ft_leaks(void)
// {
// 	system("leaks -q serialize");
// }

int main(void)
{
	// atexit(ft_leaks);
	Data *data = new Data;
	uintptr_t raw = serialize(data);
	Data *data2 = deserialize(raw);

	std::cout << "data: " << data << std::endl;
	std::cout << "dataInt: " << data->getInt() << std::endl;

	std::cout << "raw: " << raw << std::endl;

	std::cout << "data2: " << data2 << std::endl;
	std::cout << "data2Int: " << data2->getInt() << std::endl;
	
	delete data;
	return 0;	
}
