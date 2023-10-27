/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:56:52 by aaguiler          #+#    #+#             */
/*   Updated: 2022/11/06 18:37:51 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed x;
	Fixed const z( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << x << std::endl;
	std::cout << ++x << std::endl;
	std::cout << x << std::endl;
	std::cout << x++ << std::endl;
	std::cout << x << std::endl;
	std::cout << z << std::endl;

	std::cout << "Max " << Fixed::max( x, z ) << std::endl;

	Fixed const a( 2.0f );
	Fixed const b( 3.0f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	if ( a == b )
		std::cout << "a and b are equal" << std::endl;
	if ( a <= b )
		std::cout << "a is less than or equal to b" << std::endl;
	if ( a >= b )
		std::cout << "a is greater than or equal to b" << std::endl;
	if ( a != b )
		std::cout << "a and b are not equal" << std::endl;
	if ( a < b )	
		std::cout << "a is less than b" << std::endl;
	if ( a > b )
		std::cout << "a is greater than b" << std::endl;
	
	Fixed c = a + b;
	std::cout << "a + b = " << c << std::endl;
	Fixed d = a - b;
	std::cout << "a - b = " << d << std::endl;
	Fixed e = a * b;
	std::cout << "a * b = " << e << std::endl;
	Fixed f = a / b;
	std::cout << "a / b = " << f << std::endl;

	Fixed g( 2.0f );
	Fixed h( 2.0f );
	std::cout << "g is " << g << std::endl;
	std::cout << "h is " << h << std::endl;
	std::cout << "g++ is " << g++ << std::endl;
	std::cout << "g is " << g << std::endl;
	std::cout << "++h is " << ++h << std::endl;
	std::cout << "h is " << h << std::endl;
	std::cout << "g-- is " << g-- << std::endl;
	std::cout << "g is " << g << std::endl;
	std::cout << "--h is " << --h << std::endl;
	std::cout << "h is " << h << std::endl;
	return 0;
}
