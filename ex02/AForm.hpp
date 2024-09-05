/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:07:38 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/03 11:07:38 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
			AForm();
			AForm(std::string name, std::string target, int signedGrade, int execGrade);
			AForm(const AForm& other);
			AForm& operator=(const AForm& other);
			virtual ~AForm();
			std::string	getName() const;
			std::string getTarget() const;
			bool		getSigned() const;
			int			getSignedGrade() const;
			int			getExecGrade() const;
			void		beSigned(Bureaucrat &a);
			virtual void	execute(const Bureaucrat& exec) const = 0;

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

		class SignedException : public std::exception
		{
			public:
					virtual const char *what() const throw();
		};

		class ExecuteException : public std::exception
		{
			public:
					virtual const char* what() const throw();
		};

	private:
			const std::string	name_;
			const std::string	target_;
			bool				signed_;
			const int			signedGrade_;
			const int			execGrade_;
};

std::ostream	&operator<<(std::ostream &o, AForm &a);

#endif