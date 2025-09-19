/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:24:22 by yurolive          #+#    #+#             */
/*   Updated: 2025/09/19 17:29:39 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
    // ---- Constructores y destructor ----
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed& other);
    ~Fixed();

    // ---- Operador de asignación ----
    Fixed& operator=(const Fixed& other);

    // ---- Conversión ----
    float toFloat(void) const;
    int toInt(void) const;

    // ---- Comparación ----
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    // ---- Aritmética ----
    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

    // ---- Incremento / Decremento ----
    Fixed& operator++();    // pre-incremento
    Fixed operator++(int);  // post-incremento
    Fixed& operator--();    // pre-decremento
    Fixed operator--(int);  // post-decremento

    // ---- Métodos estáticos min/max ----
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    // ---- Sobrecarga de salida ----
    friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
};

#endif //FIXED_HPP