/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:01:30 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/31 19:11:17 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

class Form::GradeTooHighException : public std::exception
{
	virtual const char *what() const throw()
	{
		return ("Grade too high");
	}
};

class Form::GradeTooLowException : public std::exception
{
	virtual const char *what() const throw()
	{
		return ("Grade too low");
	}
};

Form::Form(void) : _name("Default"), _isSigned(false), _gradeNeededToSign(140), _gradeNeededToExecute(140)
{
}

Form::Form(std::string const &name, const int gradeNeededToExecute, const int gradeNeededToSign) :
	_name(name), _isSigned(false), _gradeNeededToSign(gradeNeededToSign), _gradeNeededToExecute(gradeNeededToExecute)
{
	if(gradeNeededToExecute < 1 || gradeNeededToSign < 1)
		throw Form::GradeTooHighException();
	else if(gradeNeededToExecute > 150 || gradeNeededToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src) :
	_name(src.getName()), _isSigned(src.getIsSigned()), _gradeNeededToSign(src.getGradeNeededToSign()), _gradeNeededToExecute(src.getGradeNeededToExecute())
{
}

Form::~Form(void)
{
}

Form	&Form::operator=(Form const &rhs)
{
	this->_isSigned = rhs.getIsSigned();
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	Form::getGradeNeededToExecute(void) const
{
	return (this->_gradeNeededToExecute);
}

int	Form::getGradeNeededToSign(void) const
{
	return (this->_gradeNeededToSign);
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs)
{
	o << rhs.getName() << ", Form grade to be signed: " << rhs.getGradeNeededToSign();
	o << ", Form grade to be executed: " << rhs.getGradeNeededToExecute();
	o << ", is signed? " << rhs.getIsSigned() << std::endl;
	return (o);
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if(bureaucrat.getGrade() > this->_gradeNeededToSign)
		throw Form::GradeTooLowException();
	else {
		std::cout << bureaucrat.getName() << " signs " << this->_name << std::endl;
		this->_isSigned = true;
	}
}
