/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:44:05 by aaguiler          #+#    #+#             */
/*   Updated: 2022/11/06 19:07:39 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point {
private:
	Fixed const _x;
	Fixed const _y;

public:
	Point(void);
	Point(Point const &src);
	Point(Fixed const &x, Fixed const &y);
	~Point(void);

	Point	&operator=(Point const &rhs);

	Fixed const &getX(void) const;
	Fixed const &getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
