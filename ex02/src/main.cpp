/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 05:57:47 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/09 05:58:49 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
	std::cout << "\n--- Testing ShrubberyCreationForm ---" << std::endl;
	try {
		Bureaucrat gardener("Gardener", 130); // can sign & execute
		ShrubberyCreationForm shrub("home");

		gardener.signForm(shrub);
		gardener.executeForm(shrub);
	} catch (const std::exception &e) {
		std::cerr << "❌ Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
	try {
		Bureaucrat technician("Technician", 45); // just enough to sign and execute
		RobotomyRequestForm robot("Bender");

		technician.signForm(robot);
		for (int i = 0; i < 3; ++i)
			technician.executeForm(robot);
	} catch (const std::exception &e) {
		std::cerr << "❌ Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
	try {
		Bureaucrat president("President", 1); // very high grade
		PresidentialPardonForm pardon("Ford Prefect");

		president.signForm(pardon);
		president.executeForm(pardon);
	} catch (const std::exception &e) {
		std::cerr << "❌ Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing form not signed ---" << std::endl;
	try {
		Bureaucrat junior("Junior", 1);
		PresidentialPardonForm unsignedForm("Nobody");
		junior.executeForm(unsignedForm); // not signed!
	} catch (const std::exception &e) {
		std::cerr << "❌ Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing insufficient execution grade ---" << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		ShrubberyCreationForm shrub("office");

		intern.signForm(shrub);       // allowed
		intern.executeForm(shrub);    // should fail
	} catch (const std::exception &e) {
		std::cerr << "❌ Error: " << e.what() << std::endl;
	}

	return 0;
}
