/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:53:00 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/09 09:11:33 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    protected:
        typedef AForm*  (*FormFactory)(const std::string &target);

        struct FormMap {
            const char *name;
            FormFactory create;
        };
        
    public:
        /* ------------------------------ Constructors ------------------------------ */
        Intern(void);
        Intern(const Intern &other);

        /* ------------------------------- Destructors ------------------------------ */
        ~Intern(void);

        /* ---------------------------- Operator overload --------------------------- */
        Intern  &operator=(const Intern &other);

        /* -------------------------------- Functions ------------------------------- */
        static AForm    *makeForm(const std::string &name, const std::string &target);
};