/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:51:41 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/01 10:51:42 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed getCrossProduct(const Point& a, const Point& b){
	Fixed result(a.getX() * b.getY() - a.getY() * b.getX());
	return result;
}

bool checkSigns(const Fixed& cross1, const Fixed& cross2, const Fixed& cross3) {
	if (cross1 > 0 && cross2 > 0 && cross3 > 0)
		return true;
	else if (cross1 < 0 && cross2 < 0 && cross3 < 0)
		return true;
	else
		return false;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed cross1 = getCrossProduct(b - a, point - a);
	Fixed cross2 = getCrossProduct(c - b, point - b);
	Fixed cross3 = getCrossProduct(a - c, point - c);

	return checkSigns(cross1, cross2, cross3);
}

