/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:37:03 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/11/03 23:05:38 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form(const std::string& name, int signGrade, int executeGrade)
: name_(name), isSigned_(false), signGrade_(signGrade), executeGrade_(executeGrade)
{
	std::cout << "Form " << name_ << " name constructor called" << std::endl;
	if (signGrade_ < 1 || executeGrade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	if (signGrade_ > 150 || executeGrade_ > 150)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form& obj)
: name_(obj.name_), isSigned_(obj.isSigned_), signGrade_(obj.signGrade_), executeGrade_(obj.executeGrade_)
{
		std::cout << "Bureaucrat " << name_ << " copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& obj)
{
	if (this != &obj)
		this->isSigned_ = obj.isSigned_;
	std::cout << "Form " << name_ << " copy assignent operator called" << std::endl;
	return *this;
}

Form::~Form()
{
	std::cout << "Form " << name_ << " destructor called" << std::endl;
}

const std::string& Form::getName() const
{
	return name_;
}
int Form::getSignGrade() const
{
	return signGrade_;
}
int Form::getExecuteGrade() const
{
	return executeGrade_;
}

bool Form::isSigned() const
{
	return isSigned_;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > signGrade_)
		throw GradeTooLowException();
	isSigned_ = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form: " << f.getName()
		<< " | Signed: " << (f.isSigned() ? "Yes" : "No")
		<< " | Grade to sign: " << f.getSignGrade()
		<< " | Grade to execute: " << f.getExecuteGrade();
	return os;
}