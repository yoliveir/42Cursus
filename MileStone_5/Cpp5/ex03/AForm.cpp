/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:12:21 by yurolive          #+#    #+#             */
/*   Updated: 2026/02/06 18:14:31 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string const & name, int s, int e)
    : _name(name), _signed(false), _gradeSign(s), _gradeExec(e)
{
    if (s < 1 || e < 1) throw GradeTooHighException();
    if (s > 150 || e > 150) throw GradeTooLowException();
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _signed; }
int AForm::getGradeSign() const { return _gradeSign; }
int AForm::getGradeExec() const { return _gradeExec; }

void AForm::beSigned(Bureaucrat const & b)
{
    if (b.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_signed) throw NotSignedException();
    if (executor.getGrade() > _gradeExec)
        throw GradeTooLowException();
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "grade too low";
}

const char* AForm::NotSignedException::what() const throw() {
    return "form not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << f.getName()
       << " [sign grade: " << f.getGradeSign()
       << ", exec grade: " << f.getGradeExec()
       << ", signed: " << f.isSigned() << "]";
    return os;
}