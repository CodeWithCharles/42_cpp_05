/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 05:23:27 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/09 05:27:35 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):    AForm(RR_FORM_NAME, 72, 45),
                                                                        target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other),
                                                                            target(other.target) {}

/* -------------------------------------------------------------------------- */
/*                                 Destructors                                */
/* -------------------------------------------------------------------------- */

RobotomyRequestForm::~RobotomyRequestForm(void) {}

/* -------------------------------------------------------------------------- */
/*                              Operator overload                             */
/* -------------------------------------------------------------------------- */

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    *static_cast<AForm *>(this) = other;
    this->target = other.target;
    return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                   Methods                                  */
/* -------------------------------------------------------------------------- */

void    RobotomyRequestForm::doAction(void) const
{
    if (std::rand() % 2)
        std::cout << this->target << " has been robotomized" << std::endl;
    else
        std::cout << "The robotomy has failed" << std::endl;
}

