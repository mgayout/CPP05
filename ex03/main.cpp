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
#include "Intern.hpp"

int	main()
{
	try
	{
		Bureaucrat				b1("Bill", 10);
		Intern					i1;
		AForm					*a1;
		
		a1 = i1.makeForm("robotomy request", b1.getName());

		std::cout << b1 << std::endl << *a1 << std::endl << std::endl;

		a1->beSigned(b1);
		std::cout << std::endl;
		a1->execute(b1);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}