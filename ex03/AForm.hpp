/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:37:06 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/11/03 23:06:40 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string name_;
		bool isSigned_;
		const int signGrade_;
		const int executeGrade_;
	public:
		AForm(const std::string& name, int signGrade, int executeGrade);
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		virtual ~AForm();
		const std::string& getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool isSigned() const;
		void beSigned(const Bureaucrat& b);
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		virtual void execute(Bureaucrat const& b) const = 0;
	protected:
		void checkExecutable(Bureaucrat const& executor) const;

};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif