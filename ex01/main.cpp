/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:33:49 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/24 00:11:24 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 50);
		Form tax("Tax Form", 45, 20);

		std::cout << bob << std::endl;
		std::cout << tax << std::endl;

		bob.signForm(tax);
		
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try {
		Bureaucrat jim("Jim", 10);
		Form contract("Contract", 20, 15);

		std::cout << jim << std::endl;
		std::cout << contract << std::endl;

		jim.signForm(contract);
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

