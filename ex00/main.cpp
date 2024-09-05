/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:05:59 by mgayout           #+#    #+#             */
/*   Updated: 2024/08/20 12:05:59 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	b1("Bill", 99);

		std::cout << b1 << std::endl;
		Bureaucrat	b2;

		std::cout << b2 << std::endl << std::endl;
		Bureaucrat	b3("James", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat	b1("Bill", 99);

		std::cout << b1 << std::endl << std::endl;
		b1.setGrade(151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat	b1("Bill", 50);

		std::cout << b1 << std::endl << std::endl;
		for (int i = 0; i >= 0; i++)
		{
			if (b1.getGrade() % 10 == 0)
				std::cout << b1.getName() << "'s grade is " << b1.getGrade() << "." << std::endl;
			b1.gradeIncr();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat	b1("Bill", 100);

		std::cout << b1 << std::endl << std::endl;
		for (int i = 0; i >= 0; i++)
		{
			if (b1.getGrade() % 10 == 0)
				std::cout << b1.getName() << "'s grade is " << b1.getGrade() << "." << std::endl;
			b1.gradeDecr();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}