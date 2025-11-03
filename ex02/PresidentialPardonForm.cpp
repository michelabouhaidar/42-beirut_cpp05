/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:05:44 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/11/03 23:10:35 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardonForm", 25, 5), target_(target)
{
	std::cout << "PresidentialPardonForm " << target_ << " target constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
:AForm(obj), target_(obj.target_)
{
	std::cout << "PresidentialPardonForm " << target_ << " target copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this != &obj)
	{
		AForm::operator=(obj);
		this->target_ = obj.target_;
	}
	std::cout << "PresidentialPardonForm " << target_ << " target copy assignent operator called" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << target_ << " target destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	checkExecutable(executor);
	std::cout << target_ << " has been pardoned by the President." << std::endl;
}