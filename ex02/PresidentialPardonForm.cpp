/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P			esidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:08:48 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/03 11:08:48 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential", target, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	(void)other;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void	PresidentialPardonForm::execute(const Bureaucrat& exec) const
{
	if (!this->getSigned() || (this->getExecGrade() < exec.getGrade()))
		throw (ExecuteException());
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}