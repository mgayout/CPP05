/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:07:28 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/03 11:07:28 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name_("default"), target_("default"), signed_(false), signedGrade_(150), execGrade_(150)
{

}

AForm::AForm(std::string name, std::string target, int signedGrade, int execGrade) : name_(name), target_(target), signed_(false), signedGrade_(signedGrade), execGrade_(execGrade)
{
	if (this->getSignedGrade() > 150 || this->getExecGrade() > 150)
		throw(AForm::GradeTooLowException());
	else if (this->getSignedGrade() < 1 || this->getExecGrade() < 1)
		throw(AForm::GradeTooHighException());
}

AForm::AForm(const AForm& other) : name_(other.getName()), target_(other.getTarget()), signed_(other.signed_), signedGrade_(other.signedGrade_), execGrade_(other.execGrade_)
{

}

AForm& AForm::operator=(const AForm& other)
{
	(void)other;
	return *this;
}

AForm::~AForm()
{

}

std::string	AForm::getName() const
{
	return this->name_;
}

std::string AForm::getTarget() const
{
	return this->target_;
}

bool	AForm::getSigned() const
{
	return this->signed_;
}

int	AForm::getSignedGrade() const
{
	return this->signedGrade_;
}

int	AForm::getExecGrade() const
{
	return this->execGrade_;
}

void	AForm::beSigned(Bureaucrat &a)
{
	if (a.getGrade() > this->getSignedGrade() || this->getSigned())
		throw(SignedException());
	else
	{
		this->signed_ = true;
		std::cout << a.getName() << " signed " << this->getName() << "." << std::endl;
	}
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low.");
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high.");
}

const char	*AForm::SignedException::what(void) const throw()
{
	return ("Couldn't sign form because is already signed or Bureacrate's grade is lower than Form's grade.");
}

const char	*AForm::ExecuteException::what(void) const throw()
{
	return ("Couldn't execute Form because Form isn't signed or Bureacrate's grade is lower than Form's grade.");
}

std::ostream	&operator<<(std::ostream &o, AForm &a)
{
	if (a.getSigned())
		o << a.getName() << ", signed, signed grade " << a.getSignedGrade() << ", exec grade " << a.getExecGrade();
	else
		o << a.getName() << ", not signed, signed grade " << a.getSignedGrade() << ", exec grade " << a.getExecGrade();
	return o;
}
