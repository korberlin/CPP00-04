/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:51:23 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/01 10:51:24 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor and Destructors
Fixed::Fixed(void): _value(0) {

}

Fixed::Fixed(const int value) {
	this->_value = value << this->_frac;
}

Fixed::Fixed(const float value) {
	this->_value = roundf(value * (1 << this->_frac));
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::~Fixed(void){

}

// Copy Assignment Function

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

// Getter and Setter Functions
int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(const int bits) {
	this->_value = bits;
}

// Conversion Functions
float Fixed::toFloat(void) const {
	return (float)this->_value / (1 << this->_frac);
}

int Fixed::toInt(void) const {
	return this->_value >> this->_frac;
}

// Comparison Functions

bool Fixed::operator>(Fixed const& other) const {
	return (this->toInt() > other.toInt());
}

bool Fixed::operator<(Fixed const& other) const {
	return (this->toInt() < other.toInt());
}

bool Fixed::operator>=(Fixed const& other) const {
	return (this->toInt() >= other.toInt());
}

bool Fixed::operator<=(Fixed const& other) const {
	return (this->toInt() <= other.toInt());
}

bool Fixed::operator==(Fixed const& other) const {
	return (this->toInt() == other.toInt());
}

bool Fixed::operator!=(Fixed const& other) const {
	return (this->toInt() != other.toInt());
}

// Arithmetic Functions

Fixed Fixed::operator+(Fixed const& other) const {
	Fixed result;
	result._value = this->_value + other._value;
	return result;
}

Fixed Fixed::operator-(Fixed const& other) const {
	Fixed result;
	result._value = this->_value - other._value;
	return result;
}

Fixed Fixed::operator*(Fixed const& other) const {
	Fixed result;
	long long temp = static_cast<long long>(this->_value) * other._value;
	result._value = static_cast<int>(temp >> _frac);
	return result;
}

Fixed Fixed::operator/(Fixed const& other) const {
	Fixed result;
	if (other._value == 0)
		std::cout << "Dividing by 0 is not allowed for this class" << std::endl;
	else
		result._value = this->_value / other._value;
	return result;
}

// Increment & Decrement Functions

Fixed& Fixed::operator++(void) {
	++(this->_value);
	return *this;
}

Fixed& Fixed::operator--(void) {
	--(this->_value);
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	++(this->_value);
	return temp;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	--(this->_value);
	return temp;
}

// Max-Min functions

Fixed& Fixed::min(Fixed& a, Fixed& b){
	if (a._value < b._value)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a._value > b._value)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(Fixed const& a, Fixed const& b) {
	if (a._value < b._value)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(Fixed const& a, Fixed const& b) {
	if (a._value > b._value)
		return a;
	else
		return b;
}

// Stream operators
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
