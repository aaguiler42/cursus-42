/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:10:37 by aaguiler          #+#    #+#             */
/*   Updated: 2023/02/04 13:57:43 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
# include <sstream>

class Data
{
public:
	Data(void);
	Data(Data const &obj);
	~Data(void);

	Data &operator=(Data const &obj);
	int getInt(void) const;

private:
	int         _int;
};

#endif
