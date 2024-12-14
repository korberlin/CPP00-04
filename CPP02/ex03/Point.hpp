/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:52:03 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/01 10:52:04 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point {
	private:
		Fixed _x;
		Fixed _y;
	public:
		Point();
		Point(float const x, float const y);
		Point(const Fixed& x, const Fixed& y);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();

		Point operator-(const Point& other) const;

		const Fixed getX(void) const;
		const Fixed getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
