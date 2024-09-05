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
#include "Form.hpp"

int	main()
{
	try
	{
		Form	f1("James", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat	b1("Bill", 100);
		Form		f1("James", 99, 150);

		std::cout << b1 << std::endl << f1 << std::endl << std::endl;
		b1.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat	b1("Bill", 100);
		Form		f1("James", 80, 150);

		std::cout << b1 << std::endl << f1 << std::endl << std::endl;
		for (int i = 0; b1.getGrade() >= f1.getSignedGrade(); i++)
			b1.gradeIncr();
		b1.signForm(f1);
		std::cout << std::endl;
		f1.beSigned(b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------" << std::endl;
	return 0;
}
