/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:21:10 by aaguiler          #+#    #+#             */
/*   Updated: 2022/11/20 11:29:55 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b("Grade 0", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("Grade 151", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("Grade 1", 1);
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
		b.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("Grade 149", 149);
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
		b.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------FORMS-----" << std::endl;
	try {
		Form f("Form 1", 0, 150);
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		Form f1("Form 2", 151, 150);
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		Form f2("Form 3", 150, 100);
		std::cout << f2;
		Bureaucrat b("Grade 150", 150);
		std::cout << b;
		b.signForm(f2);
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		Form f3("Form 4", 150, 100);
		std::cout << f3;
		Bureaucrat b1("Grade 10", 10);
		std::cout << b1;
		b1.signForm(f3);
		std::cout << f3;
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		Form f3("Form 4", 150, 100);
		std::cout << f3;
		Bureaucrat b1("Grade 10", 10);
		std::cout << b1;
		f3.beSigned(b1);
		std::cout << f3;
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}