/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:01:18 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/24 23:23:28 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", 147, 137), target_(target)
{
	std::cout << "ShrubberyCreationForm " << target_ << " target constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
:AForm(obj), target_(obj.target_)
{
	std::cout << "ShrubberyCreationForm " << target_ << " target copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this != &obj)
		this->target_ = obj.target_;
	std::cout << "ShrubberyCreationForm " << target_ << " target copy assignent operator called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << target_ << " target destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	checkExecutable(executor);
	std::ofstream ofs((target_ + "shrubbery").c_str());
	if (!ofs)
		throw std::runtime_error("ShrubberyCreationForm: cannot open output file");
	ofs << "       _-_\n"
			"    /~~   ~~\\\n"
			" /~~         ~~\\\n"
			"{               }\n"
			" \\  _-     -_  /\n"
			"   ~  \\\\ //  ~\n"
			"_- -   | | _- _\n"
			"  _ -  | |   -_\n"
			"      // \\\\\n";
	ofs.close();
}