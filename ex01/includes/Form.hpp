/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:56:43 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/07 13:21:19 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Grades.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   name;
        const int           signGrade;
        const int           execGrade;
        bool                isSigned;

    public:
        /* ------------------------------- Exceptions ------------------------------- */
        class GradeTooHighException : public std::exception
        {
            public:
                const char  *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char  *what() const throw();
        };

        /* ------------------------------ Constructors ------------------------------ */
        Form(const std::string &name = "unnamed", int signGrade = MAX_GRADE, int execGrade = MAX_GRADE, bool isSigned = false);
        Form(const Form &other);

        /* ------------------------------- Destructors ------------------------------ */
        ~Form(void);

        /* --------------------------- Operators overload --------------------------- */
        Form    &operator=(const Form &other);

        /* --------------------------------- Methods -------------------------------- */
        void    beSigned(const Bureaucrat &bureaucrat);

        /* -------------------------------- Functions ------------------------------- */
        const std::string   &getName(void) const;
        int                 getSignGrade(void) const;
        int                 getExecGrade(void) const;
        bool                getSigned(void) const;
};

std::ostream    &operator<<(std::ostream &stream, const Form &form);