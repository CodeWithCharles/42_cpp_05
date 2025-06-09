/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:56:43 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/09 05:07:30 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Grades.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        const int           signGrade;
        const int           execGrade;
        bool                isSigned;

    protected:
        /* --------------------------------- Methods -------------------------------- */
        virtual void        doAction(void) const = 0;
        

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

        class FormNotSignedException : public std::exception
        {
            public:
                const char  *what() const throw();  
        };

        /* ------------------------------ Constructors ------------------------------ */
        AForm(const std::string &name = "unnamed", int signGrade = MAX_GRADE, int execGrade = MAX_GRADE, bool isSigned = false);
        AForm(const AForm &other);

        /* ------------------------------- Destructors ------------------------------ */
        virtual ~AForm(void);

        /* --------------------------- Operators overload --------------------------- */
        AForm               &operator=(const AForm &other);

        /* --------------------------------- Methods -------------------------------- */
        void                beSigned(const Bureaucrat &bureaucrat);
        void                execute(const Bureaucrat &executor) const;

        /* -------------------------------- Functions ------------------------------- */
        const std::string   &getName(void) const;
        int                 getSignGrade(void) const;
        int                 getExecGrade(void) const;
        bool                getSigned(void) const;
};

std::ostream    &operator<<(std::ostream &stream, const AForm &form);