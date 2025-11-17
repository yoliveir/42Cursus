/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:47:21 by yurolive          #+#    #+#             */
/*   Updated: 2025/09/18 16:49:16 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		Fixed(const int n);
		Fixed(const float f);

		int  getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int   toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif //FIXED_HPP