/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 05:49:45 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/09 05:54:20 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):    AForm(SC_FORM_NAME, 145, 137),
                                                                            target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):   AForm(other),
                                                                                    target(other.target) {}

/* -------------------------------------------------------------------------- */
/*                                 Destructors                                */
/* -------------------------------------------------------------------------- */

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

/* -------------------------------------------------------------------------- */
/*                              Operator overload                             */
/* -------------------------------------------------------------------------- */

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    *static_cast<AForm *>(this) = other;
    this->target = other.target;
    return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                   Methods                                  */
/* -------------------------------------------------------------------------- */

void    ShrubberyCreationForm::doAction(void) const
{
    std::string     filename(this->target + "_shrubbery");
    std::ofstream   file;

    file.open(filename.c_str());
    if (!file.is_open())
        std::cerr << "shrubbery: " << filename << ": " << std::strerror(errno) << std::endl;
    else
        file << ASCII_TREE;
}