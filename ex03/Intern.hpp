/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:24:20 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/25 01:30:47 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);
		~Intern();
		AForm* makeForm(const std::string& form, const std::string& target) const;
		class UnknownFormException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif