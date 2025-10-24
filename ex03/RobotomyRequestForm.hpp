/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:49:52 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/24 23:14:45 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target_;
	public:
		explicit RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
		~RobotomyRequestForm();
		void execute(Bureaucrat const& executor) const;
};

#endif