/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:12:16 by aaguiler          #+#    #+#             */
/*   Updated: 2023/02/04 13:31:52 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <limits>

Data::Data(void)
{
	_int = std::numeric_limits<int>::max();
}

Data::Data(Data const &obj)
{
	*this = obj;
}

Data::~Data(void)
{
}

Data &Data::operator=(Data const &obj)
{
	if (this != &obj)
		_int = obj._int;
	return *this;
}

int Data::getInt(void) const
{
	return _int;
}
