/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:48:34 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/05 14:48:34 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	public:
			Intern();
			Intern(const Intern& other);
			Intern& operator=(const Intern& other);
			~Intern();
			AForm*	makeForm(const std::string& name, const std::string& target);

			class	InternException : public std::exception
			{
				public:
						virtual const char*	what() const throw();
			};

	private:


};

#endif