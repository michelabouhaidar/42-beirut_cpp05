/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:33:49 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/25 01:30:17 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {
		Intern	  someRandomIntern;
		Bureaucrat  boss("Boss", 1);
		Bureaucrat  mid("Mid", 50);
		Bureaucrat  junior("Junior", 140);

		AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "home");
		AForm* robo  = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm* pardon= someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

		try {
			AForm* nope = someRandomIntern.makeForm("tax evasion", "Nobody");
			delete nope;
		} catch (std::exception& e) {
			std::cout << "[Invalid] " << e.what() << "\n";
		}

		junior.signForm(*shrub);
		mid.signForm(*robo);
		mid.signForm(*pardon);
		boss.signForm(*pardon);

		junior.executeForm(*shrub);
		mid.executeForm(*shrub);
		mid.executeForm(*robo);
		boss.executeForm(*robo);
		boss.executeForm(*pardon);

		delete shrub;
		delete robo;
		delete pardon;

	} catch (std::exception& e) {
		std::cerr << "UNCAUGHT: " << e.what() << "\n";
	}
	return 0;
}
