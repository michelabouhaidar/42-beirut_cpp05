/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:37:03 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/24 23:18:46 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
: name_(name), isSigned_(false), signGrade_(signGrade), executeGrade_(executeGrade)
{
	std::cout << "AForm " << name_ << " name constructor called" << std::endl;
	if (signGrade_ < 1 || executeGrade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	if (signGrade_ > 150 || executeGrade_ > 150)
		throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm& obj)
: name_(obj.name_), isSigned_(obj.isSigned_), signGrade_(obj.signGrade_), executeGrade_(obj.executeGrade_)
{
		std::cout << "Bureaucrat " << name_ << " copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& obj)
{
	if (this != &obj)
		this->isSigned_ = obj.isSigned_;
	std::cout << "AForm " << name_ << " copy assignent operator called" << std::endl;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm " << name_ << " destructor called" << std::endl;
}

const std::string AForm::getName() const
{
	return name_;
}
int AForm::getSignGrade() const
{
	return signGrade_;
}
int AForm::getExecuteGrade() const
{
	return executeGrade_;
}

bool AForm::isSigned() const
{
	return isSigned_;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > signGrade_)
		throw GradeTooLowException();
	isSigned_ = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "AForm is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm: " << f.getName()
		<< " | Signed: " << (f.isSigned() ? "Yes" : "No")
		<< " | Grade to sign: " << f.getSignGrade()
		<< " | Grade to execute: " << f.getExecuteGrade();
	return os;
}

void AForm::checkExecutable(Bureaucrat const& executor) const
{
	if (!isSigned_)
		throw FormNotSignedException();
	if (executor.getGrade() > executeGrade_)
		throw GradeTooLowException();
}