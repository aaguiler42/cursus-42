/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:01:30 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/31 19:11:42 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class AForm::GradeTooHighException : public std::exception
{
	virtual const char *what() const throw()
	{
		return ("Grade too high");
	}
};

class AForm::GradeTooLowException : public std::exception
{
	virtual const char *what() const throw()
	{
		return ("Grade too low");
	}
};

class AForm::AFormNotSignedException : public std::exception
{
	virtual const char *what() const throw()
	{
		return ("Form not signed");
	}
};

AForm::AForm(void) : _name("Default"), _isSigned(false), _gradeNeededToSign(140), _gradeNeededToExecute(140)
{
}

AForm::AForm(std::string const &name, const int gradeNeededToSign, const int gradeNeededToExecute) :
	_name(name), _isSigned(false), _gradeNeededToSign(gradeNeededToSign), _gradeNeededToExecute(gradeNeededToExecute)
{
	if(gradeNeededToExecute < 1 || gradeNeededToSign < 1)
		throw AForm::GradeTooHighException();
	else if(gradeNeededToExecute > 150 || gradeNeededToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src) :
	_name(src.getName()), _isSigned(src.getIsSigned()), _gradeNeededToSign(src.getGradeNeededToSign()), _gradeNeededToExecute(src.getGradeNeededToExecute())
{
}

AForm::~AForm(void)
{
}

AForm	&AForm::operator=(AForm const &rhs)
{
	this->_isSigned = rhs.getIsSigned();
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	AForm::getGradeNeededToExecute(void) const
{
	return (this->_gradeNeededToExecute);
}

int	AForm::getGradeNeededToSign(void) const
{
	return (this->_gradeNeededToSign);
}

std::ostream	&operator<<(std::ostream &o, AForm const &rhs)
{
	o << rhs.getName() << ", Form grade to be signed: " << rhs.getGradeNeededToSign();
	o << ", Form grade to be executed: " << rhs.getGradeNeededToExecute();
	o << ", is signed? " << rhs.getIsSigned() << std::endl;
	return (o);
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if(bureaucrat.getGrade() > this->_gradeNeededToSign)
		throw AForm::GradeTooLowException();
	else{
		std::cout << bureaucrat.getName() << " signs " << this->_name << std::endl;
		this->_isSigned = true;
	}
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if(executor.getGrade() > this->_gradeNeededToExecute)
		throw AForm::GradeTooLowException();
	else if(!this->_isSigned)
		throw AForm::GradeTooLowException();
}
