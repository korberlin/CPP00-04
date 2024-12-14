/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:52:01 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/01 10:52:02 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors and Destructor

Point::Point(): _x(0), _y(0) {

}

Point::Point(float const x, float const y): _x(x), _y(y) {

}

Point::Point(const Fixed& x, const Fixed& y): _x(x), _y(y) {

}

Point::Point(const Point& other): _x(other._x), _y(other._y) {

}

Point::~Point() {

}

Point& Point::operator=(const Point& other) {
	if (this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
	}
	return *this;
}

Point Point::operator-(const Point& other) const{
	Point result(_x - other._x, _y - other._y);
	return result;
}


const Fixed Point::getX(void) const {
	return _x;
}

const Fixed Point::getY(void) const {
	return _y;
}
