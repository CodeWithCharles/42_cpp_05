/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 04:53:37 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/09 05:21:40 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#define PP_FORM_NAME    "Presidential Pardon"

class PresidentialPardonForm : public AForm
{
    protected:
        std::string target;
        
        /* --------------------------------- Methods -------------------------------- */
        void    doAction(void) const;

    public:
        /* ------------------------------ Constructors ------------------------------ */
        PresidentialPardonForm(const std::string &target = "nobody");
        PresidentialPardonForm(const PresidentialPardonForm &other);

        /* ------------------------------- Destructors ------------------------------ */
        ~PresidentialPardonForm(void);

        /* ---------------------------- Operator Overload --------------------------- */
        PresidentialPardonForm  &operator=(const PresidentialPardonForm &other);

};