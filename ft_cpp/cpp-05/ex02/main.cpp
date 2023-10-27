/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:21:10 by aaguiler          #+#    #+#             */
/*   Updated: 2022/11/20 12:35:46 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "TREEES" << std::endl;
	try
	{
		Bureaucrat b("Grade 5", 5);
		std::cout << b;
		ShrubberyCreationForm f("Form 1");
		std::cout << f;
		b.signForm(f);
		std::cout << f;
		f.execute(b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("Grade 5", 5);
		std::cout << b;
		ShrubberyCreationForm f("Form 1");
		std::cout << f;
		b.signForm(f);
		std::cout << f;
		b.executeForm(f);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "ROBOOT" << std::endl;
	try
	{
		Bureaucrat b("Grade 5", 5);
		std::cout << b;
		RobotomyRequestForm f("Form 1");
		std::cout << f;
		b.signForm(f);
		std::cout << f;
		b.executeForm(f);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "PRESIDEENT" << std::endl;
	try
	{
		Bureaucrat b("Grade 4", 20);
		std::cout << b;
		PresidentialPardonForm f("Form 1");
		std::cout << f;
		b.signForm(f);
		std::cout << f;
		b.executeForm(f);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}