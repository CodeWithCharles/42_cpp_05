/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:56:52 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/09 09:21:10 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */

Intern::Intern(void) {}

Intern::Intern(const Intern &other) {(void)other;}

/* -------------------------------------------------------------------------- */
/*                                 Destructors                                */
/* -------------------------------------------------------------------------- */

Intern::~Intern(void) {}

/* -------------------------------------------------------------------------- */
/*                              Operator overload                             */
/* -------------------------------------------------------------------------- */

Intern  &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

static AForm    *createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}


static AForm    *createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm    *createPardon(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm   *Intern::makeForm(const std::string &name, const std::string &target)
{
	const FormMap forms[] = {
		{SC_FORM_NAME, createShrubbery},
		{RR_FORM_NAME, createRobotomy},
		{PP_FORM_NAME, createPardon},
        {NULL, NULL}
	};

	for (size_t i = 0; forms[i].name != NULL; ++i)
	{
		if (forms[i].name == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return forms[i].create(target);
		}
	}
	std::cout << "Intern could not create " << name << ": form doesn't exist" << std::endl;
	return NULL;
};