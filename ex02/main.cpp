/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:33:49 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/24 23:31:10 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));

	try {
		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 50);
		Bureaucrat tom("Tom", 140);

		ShrubberyCreationForm f1("home");
		RobotomyRequestForm   f2("Bender");
		PresidentialPardonForm f3("Ford Prefect");

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;

		tom.signForm(f1);
		bob.signForm(f2);
		bob.signForm(f3);

		tom.executeForm(f1);
		bob.executeForm(f1);
		bob.executeForm(f2);
		alice.executeForm(f2);
		alice.executeForm(f3);
		alice.signForm(f3);
		alice.executeForm(f3); 

	} catch (std::exception& e) {
		std::cerr << "UNCAUGHT: " << e.what() << std::endl;
	}
	return 0;
}

