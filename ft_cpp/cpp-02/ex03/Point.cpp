/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:44:08 by aaguiler          #+#    #+#             */
/*   Updated: 2022/11/06 18:58:20 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(Point const &src) : _x(src.getX()), _y(src.getY())
{
}

Point::Point(Fixed const &x, Fixed const &y) : _x(x), _y(y)
{
}

Point::~Point(void)
{
}

Point	&Point::operator=(Point const &rhs)
{
	(void)rhs;
	return (*this);
}

Fixed const &Point::getX(void) const
{
	return (this->_x);
}

Fixed const &Point::getY(void) const
{
	return (this->_y);
}
