/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:04:14 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/09 05:14:28 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                 Exceptions                                 */
/* -------------------------------------------------------------------------- */

const char  *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high exception");
}

const char  *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low exception");
}

const char  *AForm::FormNotSignedException::what() const throw()
{
    return ("Form not signed exception");
};

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */

AForm::AForm(const std::string &name, int signGrade, int execGrade, bool isSigned):   name(name),
                                                                                    signGrade(signGrade),
                                                                                    execGrade(execGrade),
                                                                                    isSigned(isSigned)
{
    if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
        throw (AForm::GradeTooHighException());
    if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
        throw (AForm::GradeTooLowException());    
}

AForm::AForm(const AForm &other):  name(other.name),
                                signGrade(other.signGrade),
                                execGrade(other.execGrade),
                                isSigned(other.isSigned)
{}

/* -------------------------------------------------------------------------- */
/*                                 Destructors                                */
/* -------------------------------------------------------------------------- */

AForm::~AForm(void) {}

/* -------------------------------------------------------------------------- */
/*                             Operators overload                             */
/* -------------------------------------------------------------------------- */

AForm    &AForm::operator=(const AForm &other)
{
    this->isSigned = other.isSigned;
    return (*this);
}

std::ostream    &operator<<(std::ostream &stream, const AForm &form)
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

void    AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->signGrade)
        throw AForm::GradeTooLowException();
    this->isSigned = true;
}

void    AForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > execGrade)
        throw GradeTooLowException();
    this->doAction();
}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

const std::string   &AForm::getName(void) const
{
    return (this->name);
}

bool                AForm::getSigned(void) const
{
    return (this->isSigned);
}

int                 AForm::getSignGrade(void) const
{
    return (this->signGrade);
}

int                 AForm::getExecGrade(void) const
{
    return (this->execGrade);
}