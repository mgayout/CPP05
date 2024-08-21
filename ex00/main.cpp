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
}