/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:56:36 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/11/03 23:07:43 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name), grade_(grade)
{
	std::cout << "Bureaucrat " << name_ << " name constructor called" << std::endl;
	if (grade_ < 1)
		throw GradeTooHighException();
	if (grade_ > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name_(obj.name_), grade_(obj.grade_)
{
	std::cout << "Bureaucrat " << name_ << " copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
		this->grade_ = obj.grade_;
	std::cout << "Bureaucrat " << name_ << " copy assignent operator called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << name_ << " destructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const
{
	return name_;
}
	
int Bureaucrat::getGrade() const
{
	return grade_;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is too low";
}

void Bureaucrat::incrementGrade()
{
	if (grade_ <= 1)
		throw GradeTooHighException();
	--grade_;
}

void Bureaucrat::decrementGrade()
{
	if (grade_ >= 150)
		throw GradeTooLowException();
	++grade_;
}

void Bureaucrat::signForm(AForm& form) const
{
	try {
		form.beSigned(*this);
		std::cout << name_ << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << name_ << " couldn’t sign " << form.getName()
				<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form) const
{
	try
	{
		form.execute(*this);
		std::cout << name_ << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << name_ << " couldn't execute " << form.getName()
					<< " because " << e.what() <<std::endl;
	}
	
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	return os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
}