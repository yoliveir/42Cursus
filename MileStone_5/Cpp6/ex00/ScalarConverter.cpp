/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:39:31 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/02 18:39:32 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>

static bool isChar(const std::string& s)
{
	return (s.length() == 1 && !std::isdigit(s[0]));
}

static bool isInt(const std::string& s)
{
	char* end;
	std::strtol(s.c_str(), &end, 10);
	return (*end == '\0');
}

static bool isFloat(const std::string& s)
{
	if (s == "-inff" || s == "+inff" || s == "nanf")
		return true;

	if (s.back() != 'f')
		return false;

	char* end;
	std::strtof(s.c_str(), &end);
	return (*end == 'f' && *(end + 1) == '\0');
}

static bool isDouble(const std::string& s)
{
	if (s == "-inf" || s == "+inf" || s == "nan")
		return true;

	char* end;
	std::strtod(s.c_str(), &end);
	return (*end == '\0');
}

void ScalarConverter::convert(const std::string& literal)
{
	double value;

	if (isChar(literal))
		value = static_cast<double>(literal[0]);
	else if (isInt(literal))
		value = static_cast<double>(std::atoi(literal.c_str()));
	else if (isFloat(literal))
		value = static_cast<double>(std::strtof(literal.c_str(), NULL));
	else if (isDouble(literal))
		value = std::strtod(literal.c_str(), NULL);
	else
	{
		std::cout << "Invalid literal\n";
		return;
	}

	/* CHAR */
	std::cout << "char: ";
	if (std::isnan(value) || value < 0 || value > 127)
		std::cout << "impossible\n";
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(value) << "'\n";

	/* INT */
	std::cout << "int: ";
	if (std::isnan(value) || value > std::numeric_limits<int>::max() ||
		value < std::numeric_limits<int>::min())
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(value) << "\n";

	/* FLOAT */
	std::cout << "float: ";
	float f = static_cast<float>(value);
	if (std::isnan(f))
		std::cout << "nanf\n";
	else if (std::isinf(f))
		std::cout << (f > 0 ? "+inff\n" : "-inff\n");
	else
	{
		std::cout << std::fixed << std::setprecision(1) << f << "f\n";
	}

	/* DOUBLE */
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan\n";
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf\n" : "-inf\n");
	else
		std::cout << std::fixed << std::setprecision(1) << value << "\n";
}