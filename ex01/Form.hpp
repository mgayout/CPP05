/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:54:02 by mgayout           #+#    #+#             */
/*   Updated: 2024/08/20 16:54:02 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
			Form();
			Form(std::string name);
			Form(std::string name, int signedGrade, int execGrade);
			Form(const Form& other);
			Form& operator=(const Form& other);
			~Form();
			std::string	getName() const;
			bool		getSigned() const;
			int			getSignedGrade() const;
			int			getExecGrade() const;
			void		beSigned(Bureaucrat &a);

		class GradeTooLowException : public std::exception
		{
			public:
					virtual const char *what() const throw();

		};

		class GradeTooHighException : public std::exception
		{
			public:
					virtual const char *what() const throw();

		};
	private:
			const std::string	name_;
			bool				signed_;
			const int			signedGrade_;
			const int			execGrade_;
};

std::ostream	&operator<<(std::ostream &o, Form *a);

#endif