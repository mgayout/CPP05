/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:08:08 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/03 11:08:08 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery", target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void)other;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void	ShrubberyCreationForm::execute(const Bureaucrat& exec) const
{
	std::ofstream	file;

	if (!this->getSigned() || (this->getExecGrade() < exec.getGrade()))
		throw (ExecuteException());
	file.open((this->getTarget() + "_shrubbery").c_str());
	if (!file.is_open())
		std::cout << "Error: creating file." << std::endl;
	else
	{
		std::cout << "You should open " << this->getTarget() << "_shrubbery file." << std::endl;
		file << "       /\\       " << std::endl;
		file << "      /  \\      " << std::endl;
		file << "     /    \\     " << std::endl;
		file << "    /      \\    " << std::endl;
		file << "   /        \\   " << std::endl;
		file << "  /          \\  " << std::endl;
		file << " /            \\ " << std::endl;
		file << "/______  ______\\" << std::endl;
		file << "       ||        " << std::endl;
	}
}

