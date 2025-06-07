/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:28:46 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/07 13:03:55 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

/* -------------------------------------------------------------------------- */
/*                                 Exceptions                                 */
/* -------------------------------------------------------------------------- */

const char  *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high exception");
}

const char  *Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade too low exception");
}

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */

Bureaucrat::Bureaucrat(std::string name, int grade):    name(name),
                                                        grade(grade)
{
    if (grade < MAX_GRADE)
        throw (Bureaucrat::GradeTooHighException());
    if (grade > MIN_GRADE)
        throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):    name(other.name),
                                                    grade(other.grade)
{}

/* -------------------------------------------------------------------------- */
/*                                 Destructors                                */
/* -------------------------------------------------------------------------- */

Bureaucrat::~Bureaucrat(void) {}

/* -------------------------------------------------------------------------- */
/*                             Operators overload                             */
/* -------------------------------------------------------------------------- */

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &other)
{
    this->grade = other.grade;
    return (*this);
}

std::ostream    &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
    stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return stream;
}

/* -------------------------------------------------------------------------- */
/*                                   Methods                                  */
/* -------------------------------------------------------------------------- */

void    Bureaucrat::incrementGrade(void)
{
    if (this->grade <= MAX_GRADE)
        throw (Bureaucrat::GradeTooHighException());
    this->grade--;
}

void    Bureaucrat::decrementGrade(void)
{
    if (this->grade >= MIN_GRADE)
        throw (Bureaucrat::GradeTooLowException());
    this->grade++;
}

void    Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << "." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->name << " couldn't sign " << form.getName() << " because his grade is too low." << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

const std::string   &Bureaucrat::getName(void) const
{
    return (this->name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->grade);
}