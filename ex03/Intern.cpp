/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:49:19 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/05 14:49:19 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{

}

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string	nameForm[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*form;

	try
	{
		int	i;

		for (i = 0; i < 2; i++)
			if (name == nameForm[i])
				break;
		switch (i)
		{
			case 0:
					form = new ShrubberyCreationForm(target);
					break;
			case 1:
					form = new RobotomyRequestForm(target);
					break;
			case 2:
					form = new PresidentialPardonForm(target);
					break;
			default:
					throw Intern::InternException();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return form;
}

const char*	Intern::InternException::what() const throw()
{
	return ("Form name is invalid.");
}
