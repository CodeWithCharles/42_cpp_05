/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 04:58:18 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/09 05:06:02 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):  AForm(PP_FORM_NAME, 25, 5),
                                                                            target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):    AForm(other),  
                                                                                        target(other.target) {}

/* -------------------------------------------------------------------------- */
/*                                 Destructors                                */
/* -------------------------------------------------------------------------- */

PresidentialPardonForm::~PresidentialPardonForm(void) {}

/* -------------------------------------------------------------------------- */
/*                              Operator overload                             */
/* -------------------------------------------------------------------------- */

PresidentialPardonForm  &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    *static_cast<AForm *>(this) = other;
    this->target = other.target;
    return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                   Methods                                  */
/* -------------------------------------------------------------------------- */

void    PresidentialPardonForm::doAction(void) const
{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}