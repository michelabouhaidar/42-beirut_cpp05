/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:33:49 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/23 20:39:41 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("Alice", 2);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
	} catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	try {
		Bureaucrat b("Bob", 151);
	} catch (std::exception& e)
	{
		std::cerr << "Construct error: " << e.what() << '\n';
	}
}
