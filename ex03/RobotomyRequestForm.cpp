/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:46:49 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/24 23:50:37 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 75), target_(target)
{
	std::cout << "RobotomyRequestForm " << target_ << " target constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
:AForm(obj), target_(obj.target_)
{
	std::cout << "RobotomyRequestForm " << target_ << " target copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this != &obj)
		this->target_ = obj.target_;
	std::cout << "RobotomyRequestForm " << target_ << " target copy assignent operator called" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << target_ << " target destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	checkExecutable(executor);
	std::cout << "Bzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" << std::endl;
	if (std::rand() % 2)
		std::cout << target_ << " has been robotimized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << target_ << "." << std::endl;
}