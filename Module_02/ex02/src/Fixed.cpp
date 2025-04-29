/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:00:42 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/29 15:49:56 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0) {
}

Fixed::Fixed(const int value) {
	_fixedValue = value << _fractBit;
}

Fixed::Fixed(const float value) {
	_fixedValue = roundf(value * (1 << _fractBit));
}

Fixed::Fixed(const Fixed& other) {
	_fixedValue = other._fixedValue;
}

Fixed::~Fixed() {
}
//Assignement operator
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		_fixedValue = other._fixedValue;
	}
	return (*this);
}
//Conversion
int Fixed::toInt( void ) const {
	return (_fixedValue >> _fractBit);
}

float Fixed::toFloat( void ) const {
	return ((float)_fixedValue / (1 << _fractBit));
}
//Comparaison
bool Fixed::operator>(const Fixed& other) const {
	return (_fixedValue > other._fixedValue);
}

bool Fixed::operator<(const Fixed& other) const {
	return (_fixedValue < other._fixedValue);
}

bool Fixed::operator>=(const Fixed& other) const {
	return (_fixedValue >= other._fixedValue);
}

bool Fixed::operator<=(const Fixed& other) const {
	return (_fixedValue <= other._fixedValue);
}

bool Fixed::operator==(const Fixed& other) const {
	return (_fixedValue == other._fixedValue);
}

bool Fixed::operator!=(const Fixed& other) const {
	return (_fixedValue != other._fixedValue);
}
//Arithmetic
Fixed Fixed::operator+(const Fixed& other) const {
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const {
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const {
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const {
	return (Fixed(this->toFloat() / other.toFloat()));
}
//Incrementation / Decrementation
Fixed& Fixed::operator++() {
	++_fixedValue;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	++_fixedValue;
	return (temp);
}

Fixed& Fixed::operator--() {
	--_fixedValue;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	--_fixedValue;
	return (temp);
}
//Min / Max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return (a);
	return (b);
}
//Surcharge <<
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}
