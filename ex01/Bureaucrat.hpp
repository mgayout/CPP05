/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:06:13 by mgayout           #+#    #+#             */
/*   Updated: 2024/08/20 12:06:13 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Form.hpp"
# include <iostream>

class	Form;

class	Bureaucrat
{
	public:
			Bureaucrat();
			Bureaucrat(std::string name, int grade);
			Bureaucrat(const Bureaucrat& other);
			Bureaucrat& operator=(const Bureaucrat& other);
			~Bureaucrat();
			std::string	getName() const;
			int			getGrade() const;
			void		setGrade(int grade);
			void		gradeIncr();
			void		gradeDecr();
			void		signForm(Form &a);

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
			int					grade_;

};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

#endif