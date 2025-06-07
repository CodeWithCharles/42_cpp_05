/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:20:20 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/07 12:45:46 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
    class GradeTooHighException : public std::exception
    {
        public:
            char const  *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            char const  *what() const throw();
    };

    protected:
        const std::string   name;
        int                 grade;

    public:

        /* ------------------------------ Constructors ------------------------------ */
        Bureaucrat(std::string name = "unnamed", int grade = MIN_GRADE);
        Bureaucrat(const Bureaucrat &other);

        /* ------------------------------- Destructors ------------------------------ */
        ~Bureaucrat(void);

        /* ---------------------------- Operator overload --------------------------- */
        Bureaucrat          &operator=(const Bureaucrat &other);

        /* --------------------------------- Methods -------------------------------- */
        void                incrementGrade(void);
        void                decrementGrade(void);

        /* -------------------------------- Functions ------------------------------- */
        const std::string   &getName(void) const;
        int                 getGrade(void) const;
        
};

std::ostream    &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);