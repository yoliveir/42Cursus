/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:09:50 by yurolive          #+#    #+#             */
/*   Updated: 2026/02/06 18:11:41 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	protected:
	    const std::string _name;
	    bool _signed;
	    const int _gradeSign;
	    const int _gradeExec;

	public:
	    AForm(std::string const & name, int gradeSign, int gradeExec);
	    virtual ~AForm();

	    std::string getName() const;
	    bool isSigned() const;
	    int getGradeSign() const;
	    int getGradeExec() const;

	    void beSigned(Bureaucrat const & b);
	    void execute(Bureaucrat const & executor) const;

	    virtual void executeAction() const = 0;

	    class GradeTooHighException : public std::exception
		{
	        public: const char* what() const throw();
	    };

	    class GradeTooLowException : public std::exception
		{
	        public: const char* what() const throw();
	    };

	    class NotSignedException : public std::exception
		{
	        public: const char* what() const throw();
	    };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);