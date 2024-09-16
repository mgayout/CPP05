/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:06:22 by mgayout           #+#    #+#             */
/*   Updated: 2024/08/20 12:06:22 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("default"), grade_(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade)
{
	if (this->getGrade() > 150)
		throw(GradeTooLowException());
	else if (this->getGrade() < 1)
		throw(GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name_(other.getName()), grade_(other.getGrade())
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	this->grade_ = other.grade_;
	return *this;
}

Bureaucrat::~Bureaucrat()
{

}

std::string	Bureaucrat::getName() const
{
	return this->name_;
}

int	Bureaucrat::getGrade() const
{
	return this->grade_;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw (GradeTooLowException());
	else if (grade < 1)
		throw (GradeTooHighException());
	else
		this->grade_ = grade;
}

void	Bureaucrat::gradeIncr()
{
	this->setGrade(this->grade_ - 1);
}

void	Bureaucrat::gradeDecr()
{
	this->setGrade(this->grade_ + 1);
}

void	Bureaucrat::signForm(Form &a)
{
	a.beSigned(*this);
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low.");
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high.");
}

const char	*Bureaucrat::SignedException::what(void) const throw()
{
	return ("Couldn't sign form because is already signed or Bureacrate's grade is lower than Form's grade.");
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat &a)
{
	o << a.getName() << ", bureaucrat grade " << a.getGrade();
	return o;
}
