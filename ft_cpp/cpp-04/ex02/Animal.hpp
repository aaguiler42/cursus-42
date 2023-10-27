/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:10:33 by aaguiler          #+#    #+#             */
/*   Updated: 2022/11/12 12:04:21 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
	public:
		Animal(void);
		Animal(Animal const &src);
		virtual ~Animal(void) = 0;

		Animal	&operator=(Animal const &rhs);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;

	protected:
		std::string		_type;
		Brain*			_brain;
};

#endif
