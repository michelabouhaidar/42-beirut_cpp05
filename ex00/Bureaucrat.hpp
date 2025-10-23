/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:17:29 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/01 13:17:29 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Bureaucrat
{
	private:
		std::string name_;
		int grade_;
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);
		~Bureaucrat();
		const std::string getName() const;
		const int getGrade();
		void setName(const std::string& name);
		void setGrade(const int grade);

}