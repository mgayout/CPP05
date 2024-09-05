/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:06:59 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/03 11:06:59 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	try
	{
		Bureaucrat				b1("Bill", 150);
		ShrubberyCreationForm	s1(b1.getName());

		std::cout << b1 << std::endl << s1 << std::endl << std::endl;
		b1.signForm(s1);
	}
	catch(std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat				b1("Bill", 10);
		RobotomyRequestForm		r1(b1.getName());
		PresidentialPardonForm	p1(b1.getName());

		std::cout << b1 << std::endl << r1 << std::endl << p1 << std::endl << std::endl;
		
		b1.signForm(r1);

		std::cout << std::endl;
		std::cout << r1 << std::endl << p1 << std::endl << std::endl;

		b1.executeForm(r1);
		std::cout << std::endl;
		b1.executeForm(p1);
	}
	catch(std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat				b1("Bill", 10);
		Bureaucrat				b2("James", 150);
		RobotomyRequestForm		r1(b1.getName());
		PresidentialPardonForm	p1(b1.getName());

		std::cout << b1 << std::endl << b2 << std::endl << r1 << std::endl << p1 << std::endl << std::endl;
		
		b1.signForm(r1);
		b1.signForm(p1);

		std::cout << std::endl;
		std::cout << r1 << std::endl << p1 << std::endl << std::endl;

		b1.executeForm(r1);
		std::cout << std::endl;
		b2.executeForm(p1);
	}
	catch(std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------" << std::endl;
	return 0;
}