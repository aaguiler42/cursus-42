/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:12:16 by aaguiler          #+#    #+#             */
/*   Updated: 2023/02/04 13:31:52 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <limits>

Convert::Convert(void)
{
}

Convert::Convert(std::string const &str)
{
	_str = str;
	this->setType();
}

Convert::Convert(Convert const &obj)
{
	*this = obj;
}

Convert::~Convert(void)
{
}

Convert &Convert::operator=(Convert const &obj)
{
	if (this != &obj)
	{
		_str = obj._str;
		_int = obj._int;
		_float = obj._float;
		_double = obj._double;
		_char = obj._char;
	}
	return *this;
}

void Convert::setType()
{
	if (_str.length() == 1 && !isdigit(_str[0]))
		_double = static_cast<double>(_str[0]);
	else
		_double = stod(_str); 
}

void Convert::ft_convert()
{
	_char = static_cast<char>(_double);
	_int = static_cast<int>(_double);
	_float = static_cast<float>(_double);
}

void Convert::print()
{
	std::cout << "char: ";
	if (this->_double > std::numeric_limits<char>::max() || this->_double < std::numeric_limits<char>::min() || isnan(this->_double))
		std::cout << "imposible";
	else if (this->_double > 126 || this->_double < 32)
		std::cout << "Non displayable";	
	else
		std::cout << "\'" << this->_char << "\'";
	std::cout << std::endl;
	std::cout << "int: ";
	if (this->_double > std::numeric_limits<int>::max() || this->_double < -std::numeric_limits<int>::min() || isnan(this->_double))
		std::cout << "imposible";
	else
		std::cout << this->_int;
	std::cout << std::endl;
	std::cout << "float: ";
	if (this->_double > std::numeric_limits<float>::max() || this->_double < -std::numeric_limits<float>::min())
		std::cout << "imposible";
	else
		std::cout << std::fixed << std::setprecision(1) << this->_float << "f";
	std::cout << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << this->_double << std::endl;
}
