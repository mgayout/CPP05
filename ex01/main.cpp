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

/*int	main()
{
	Bureaucrat	*a = new Bureaucrat();
	Bureaucrat	*b = new Bureaucrat("Bill", 1);
	
	std::cout << "Start :\n" << a << " and " << b << std::endl << std::endl;
	try
	{
		b->gradeIncr();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << b << ", failed : " << e.what() << std::endl;
	}
	std::cout << "Middle :\n" << a << " and " << b << std::endl << std::endl;
	try
	{
		a->gradeDecr();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << a << ", failed : " << e.what() << std::endl;
	}
	std::cout << "End :\n" << a << " and " << b << std::endl << std::endl;
	return 0;
}*/

int	main()
{
	Bureaucrat	*a = new Bureaucrat("Bill", 1);
	Bureaucrat	*b = new Bureaucrat("James", 100);
	Form		*c = new Form("Henry", 99, 150);

	std::cout << "Start :\n" << a << ", " << b << " and " << c << std::endl << std::endl;
	try
	{
		c->beSigned(*b);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << b << ", failed : " << e.what() << std::endl;
	}
	std::cout << "Middle :\n" << a << ", " << b << " and " << c << std::endl << std::endl;
	try
	{
		c->beSigned(*a);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << a << ", failed : " << e.what() << std::endl;
	}
	std::cout << "End :\n" << a << ", " << b << " and " << c << std::endl << std::endl;
	delete a;
	delete b;
	delete c;
	return 0;
}
