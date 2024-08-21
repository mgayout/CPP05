/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:53:57 by mgayout           #+#    #+#             */
/*   Updated: 2024/08/20 16:53:57 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name_("none"), signed_(false), signedGrade_(150), execGrade_(150)
{

}

Form::Form(std::string name) : name_(name), signed_(false), signedGrade_(150), execGrade_(150)
{

}

Form::Form(std::string name, int signedGrade, int execGrade) : name_(name), signed_(false), signedGrade_(signedGrade), execGrade_(execGrade)
{
	if (this->getSignedGrade() > 150 || this->getExecGrade() > 150)
		throw(Form::GradeTooLowException());
	else if (this->getSignedGrade() < 1 || this->getExecGrade() < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(const Form& other) : name_(other.getName()), signed_(other.signed_), signedGrade_(other.signedGrade_), execGrade_(other.execGrade_)
{

}

Form& Form::operator=(const Form& other)
{
	*this = other;
	return *this;
}

Form::~Form()
{

}

std::string	Form::getName() const
{
	return this->name_;
}

bool	Form::getSigned() const
{
	return this->signed_;
}

int	Form::getSignedGrade() const
{
	return this->signedGrade_;
}

int	Form::getExecGrade() const
{
	return this->execGrade_;
}

void	Form::beSigned(Bureaucrat &a)
{
	if (a.getGrade() > this->getSignedGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (!this->getSigned())
	{
		this->signed_ = true;
		std::cout << a.getName() << " signed " << this->getName() << "." << std::endl;
	}
	else
		std::cout << this->getName() << " is already signed." << std::endl;
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low.");
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high.");
}

std::ostream	&operator<<(std::ostream &o, Form *a)
{
	if (a->getSigned())
		o << a->getName() << ", signed, signed grade " << a->getSignedGrade() << ", exec grade" << a->getExecGrade();
	else
		o << a->getName() << ", not signed, signed grade " << a->getSignedGrade() << ", exec grade " << a->getExecGrade();
	return o;
}
