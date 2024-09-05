/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:08:53 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/03 11:08:53 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Bureaucrat.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	public:
			PresidentialPardonForm(const std::string& target);
			PresidentialPardonForm(const PresidentialPardonForm& other);
			PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
			~PresidentialPardonForm();
			virtual void	execute(const Bureaucrat& exec) const;

};

#endif