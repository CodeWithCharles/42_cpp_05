/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 05:19:37 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/09 05:22:43 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include "AForm.hpp"

#define RR_FORM_NAME    "Robotomy Request"

class RobotomyRequestForm: public AForm
{
    protected:
        std::string target;

        /* --------------------------------- Methods -------------------------------- */
        void    doAction(void) const;

    public:
        /* ------------------------------ Constructors ------------------------------ */
        RobotomyRequestForm(const std::string &target = "nobody");
        RobotomyRequestForm(const RobotomyRequestForm &other);

        /* ------------------------------- Destructors ------------------------------ */
        ~RobotomyRequestForm(void);

        /* ---------------------------- Operator Overload --------------------------- */
        RobotomyRequestForm  &operator=(const RobotomyRequestForm &other);
};