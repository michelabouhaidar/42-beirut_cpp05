/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:24:18 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/25 01:30:54 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

static AForm* makeShrub(const std::string& t)
{
	return new ShrubberyCreationForm(t);
}

static AForm* makeRobo (const std::string& t) 
{
	return new RobotomyRequestForm(t);
}

static AForm* makePardon(const std::string& t)
{
	return new PresidentialPardonForm(t);
}

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern&)
{
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern&)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
	const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*creators[3])(const std::string&) = {&makeShrub,&makeRobo,&makePardon };

	for (int i = 0; i < 3; ++i)
	{
		if (name == names[i])
		{
			AForm* f = creators[i](target);
			std::cout << "Intern creates " << f->getName() << " targeting \"" << target << "\"\n";
			return f;
		}
	}
	throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw()
{
	return "Intern: unknown form name";
}
