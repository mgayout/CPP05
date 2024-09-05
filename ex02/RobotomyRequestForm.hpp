/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:08:36 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/03 11:08:36 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	public:
			RobotomyRequestForm(const std::string& target);
			RobotomyRequestForm(const RobotomyRequestForm& other);
			RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
			~RobotomyRequestForm();
			virtual void	execute(const Bureaucrat& exec) const;

};

#endif