/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:10:37 by aaguiler          #+#    #+#             */
/*   Updated: 2023/02/04 13:21:09 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <cmath>

class Convert
{
public:
	Convert(void);
	Convert(std::string const &str);
	Convert(Convert const &obj);
	~Convert(void);

	Convert &operator=(Convert const &obj);

	void    print(void);
	void	ft_convert();

private:
	std::string _str;

	char        _char;
	int         _int;
	float       _float;
	double      _double;

	void	setType();
};

#endif
