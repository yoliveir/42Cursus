/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:01:25 by yurolive          #+#    #+#             */
/*   Updated: 2026/02/06 18:06:06 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once // it includes this HEADER only 1 time
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
	private:
	    const std::string _name;
	    int _grade;

	public:
	    Bureaucrat(std::string const & name, int grade);
	    Bureaucrat(const Bureaucrat& other);
	    ~Bureaucrat();

	    Bureaucrat& operator=(const Bureaucrat& other);

	    std::string getName() const;
	    int getGrade() const;

	    void incrementGrade();
	    void decrementGrade();

	    void signForm(AForm & form) const;
	    void executeForm(AForm const & form) const;

	    class GradeTooHighException : public std::exception
		{
	        public: const char* what() const throw();
	    };

	    class GradeTooLowException : public std::exception
		{
	        public: const char* what() const throw();
	    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);