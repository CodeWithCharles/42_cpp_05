/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:04:14 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/07 13:21:50 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

/* -------------------------------------------------------------------------- */
/*                                 Exceptions                                 */
/* -------------------------------------------------------------------------- */

const char  *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high exception");
}

const char  *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low exception");
}

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */

Form::Form(const std::string &name, int signGrade, int execGrade, bool isSigned):   name(name),
                                                                                    signGrade(signGrade),
                                                                                    execGrade(execGrade),
                                                                                    isSigned(isSigned)
{
    if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
        throw (Form::GradeTooHighException());
    if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
        throw (Form::GradeTooLowException());    
}

Form::Form(const Form &other):  name(other.name),
                                signGrade(other.signGrade),
                                execGrade(other.execGrade),
                                isSigned(other.isSigned)
{}

/* -------------------------------------------------------------------------- */
/*                                 Destructors                                */
/* -------------------------------------------------------------------------- */

Form::~Form(void) {}

/* -------------------------------------------------------------------------- */
/*                             Operators overload                             */
/* -------------------------------------------------------------------------- */

Form    &Form::operator=(const Form &other)
{
    this->isSigned = other.isSigned;
    return (*this);
}

std::ostream    &operator<<(std::ostream &stream, const Form &form)
{
    stream << "form " << form.getName() << std::endl
    << "is signed : " << form.getSigned() << std::endl
    << "minimum grade to sign : " << form.getSignGrade() << std::endl
    << "minimum grade to execute : " << form.getExecGrade();
    return (stream);
}

/* -------------------------------------------------------------------------- */
/*                                   Methods                                  */
/* -------------------------------------------------------------------------- */

void    Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->signGrade)
        throw Form::GradeTooLowException();
    this->isSigned = true;
}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

const std::string   &Form::getName(void) const
{
    return (this->name);
}

bool                Form::getSigned(void) const
{
    return (this->isSigned);
}

int                 Form::getSignGrade(void) const
{
    return (this->signGrade);
}

int                 Form::getExecGrade(void) const
{
    return (this->execGrade);
}