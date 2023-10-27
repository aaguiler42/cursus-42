/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:59:58 by aaguiler          #+#    #+#             */
/*   Updated: 2022/11/06 19:10:02 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool check_if_point_is_vertex(Point const a, Point const b, Point const c, Point const point)
{
	if (a.getX() == point.getX() && a.getY() == point.getY())
		return (true);
	if (b.getX() == point.getX() && b.getY() == point.getY())
		return (true);
	if (c.getX() == point.getX() && c.getY() == point.getY())
		return (true);
	return (false);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if(check_if_point_is_vertex(a, b, c, point))
		return (false);
	Fixed const	ab = (b.getY() - a.getY()) * (point.getX() - a.getX()) - (b.getX() - a.getX()) * (point.getY() - a.getY());
	Fixed const	bc = (c.getY() - b.getY()) * (point.getX() - b.getX()) - (c.getX() - b.getX()) * (point.getY() - b.getY());
	Fixed const	ca = (a.getY() - c.getY()) * (point.getX() - c.getX()) - (a.getX() - c.getX()) * (point.getY() - c.getY());

	return ((ab > 0 && bc > 0 && ca > 0) || (ab < 0 && bc < 0 && ca < 0));
}