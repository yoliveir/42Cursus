/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:26:54 by yurolive          #+#    #+#             */
/*   Updated: 2025/09/19 17:30:02 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// ---- Constructores y destructor ----
Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int n) : _value(n << _fractionalBits) {}

Fixed::Fixed(const float f) : _value(roundf(f * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed& other) { *this = other; }

Fixed::~Fixed() {}

// ---- Operador de asignación ----
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _value = other._value;
    return *this;
}

// ---- Conversión ----
float Fixed::toFloat(void) const {
    return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

// ---- Comparación ----
bool Fixed::operator>(const Fixed& rhs) const { return _value > rhs._value; }
bool Fixed::operator<(const Fixed& rhs) const { return _value < rhs._value; }
bool Fixed::operator>=(const Fixed& rhs) const { return _value >= rhs._value; }
bool Fixed::operator<=(const Fixed& rhs) const { return _value <= rhs._value; }
bool Fixed::operator==(const Fixed& rhs) const { return _value == rhs._value; }
bool Fixed::operator!=(const Fixed& rhs) const { return _value != rhs._value; }

// ---- Aritmética ----
Fixed Fixed::operator+(const Fixed& rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}
Fixed Fixed::operator-(const Fixed& rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}
Fixed Fixed::operator*(const Fixed& rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}
Fixed Fixed::operator/(const Fixed& rhs) const {
    return Fixed(this->toFloat() / rhs.toFloat());
}

// ---- Incremento / Decremento ----
Fixed& Fixed::operator++() { // pre
    _value++;
    return *this;
}
Fixed Fixed::operator++(int) { // post
    Fixed tmp(*this);
    _value++;
    return tmp;
}
Fixed& Fixed::operator--() { // pre
    _value--;
    return *this;
}
Fixed Fixed::operator--(int) { // post
    Fixed tmp(*this);
    _value--;
    return tmp;
}

// ---- Métodos estáticos min/max ----
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// ---- Sobrecarga de salida ----
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}