/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:08:17 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/03 11:08:17 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Bureaucrat.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	public:
			ShrubberyCreationForm(const std::string& target);
			ShrubberyCreationForm(const ShrubberyCreationForm& other);
			ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
			~ShrubberyCreationForm();
			virtual void	execute(const Bureaucrat& exec) const;

};

#endif