/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:01:28 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/31 19:14:11 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
class Bureaucrat;
# include "Bureaucrat.hpp"

class AForm
{
private:
	std::string const	_name;
	bool _isSigned;
	int const	_gradeNeededToSign;
	int const	_gradeNeededToExecute;

public:
	AForm(void);
	AForm(std::string const &name, int gradeNeededToSign, int gradeNeededToExecute);
	AForm(AForm const &src);
	virtual ~AForm(void) = 0;

	AForm	&operator=(AForm const &rhs);

	std::string			getName(void) const;
	bool				getIsSigned(void) const;
	int					getGradeNeededToSign(void) const;
	int					getGradeNeededToExecute(void) const;

	void				beSigned(Bureaucrat const &bureaucrat);
	virtual void		execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException;
	class GradeTooLowException;
	class AFormNotSignedException;
};

std::ostream	&operator<<(std::ostream &o, AForm const &rhs);

#endif
