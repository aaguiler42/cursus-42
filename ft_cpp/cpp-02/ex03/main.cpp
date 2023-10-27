/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:56:52 by aaguiler          #+#    #+#             */
/*   Updated: 2022/11/06 19:07:27 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point a = Point(3, 6);
	Point b = Point(5, 2);
	Point c = Point(7, 5);

	Point p1 = Point(4, 5); // inside
	Point p2 = Point(4, 4); // edge
	Point p3 = Point(6, 3); // outside
	Point p4 = Point(3, 6); // vertex

	std::cout << "p1: " << bsp(a, b, c, p1) << std::endl;
	std::cout << "p2: " << bsp(a, b, c, p2) << std::endl;
	std::cout << "p3: " << bsp(a, b, c, p3) << std::endl;
	std::cout << "p4: " << bsp(a, b, c, p4) << std::endl;

	return 0;
}
