/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:51:49 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/01 10:51:50 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void)
{
	Point const a(-1, 0);
	Point const b(1, 0);
	Point const c(0, 2);

	// Test points
	Point const insidePoint(0, 1);	   // Inside the triangle
	Point const vertexPoint(-1, 0);	   // On vertex A
	Point const edgePoint(0, 0);	   // On edge AB
	Point const outsidePoint(2, 2);	   // Outside the triangle
	Point const centerPoint(0, 0.5f);  // Inside the triangle
	Point const outsidePoint2(-2, -1); // Far outside the triangle

	// Test 1: Point inside the triangle
	std::cout << "Test 1 - Point inside the triangle: ";
	if (bsp(a, b, c, insidePoint))
		std::cout << "Point(" << insidePoint.getX().toFloat() << ", " << insidePoint.getY().toFloat() << ") is inside the triangle." << std::endl;
	else
		std::cout << "Point is outside the triangle." << std::endl;

	// Test 2: Point on a vertex
	std::cout << "Test 2 - Point on a vertex: ";
	if (bsp(a, b, c, vertexPoint))
		std::cout << "Point is inside the triangle." << std::endl;
	else
		std::cout << "Point(" << vertexPoint.getX().toFloat() << ", " << vertexPoint.getY().toFloat() << ") is outside the triangle." << std::endl;

	// Test 3: Point on an edge
	std::cout << "Test 3 - Point on an edge: ";
	if (bsp(a, b, c, edgePoint))
		std::cout << "Point is inside the triangle." << std::endl;
	else
		std::cout << "Point(" << edgePoint.getX().toFloat() << ", " << edgePoint.getY().toFloat() << ") is outside the triangle." << std::endl;

	// Test 4: Point outside the triangle
	std::cout << "Test 4 - Point outside the triangle: ";
	if (bsp(a, b, c, outsidePoint))
		std::cout << "Point is inside the triangle." << std::endl;
	else
		std::cout << "Point(" << outsidePoint.getX().toFloat() << ", " << outsidePoint.getY().toFloat() << ") is outside the triangle." << std::endl;

	// Test 5: Another point inside the triangle
	std::cout << "Test 5 - Another point inside the triangle: ";
	if (bsp(a, b, c, centerPoint))
		std::cout << "Point(" << centerPoint.getX().toFloat() << ", " << centerPoint.getY().toFloat() << ") is inside the triangle." << std::endl;
	else
		std::cout << "Point is outside the triangle." << std::endl;

	// Test 6: Point far outside the triangle
	std::cout << "Test 6 - Point far outside the triangle: ";
	if (bsp(a, b, c, outsidePoint2))
		std::cout << "Point is inside the triangle." << std::endl;
	else
		std::cout << "Point(" << outsidePoint2.getX().toFloat() << ", " << outsidePoint2.getY().toFloat() << ") is outside the triangle." << std::endl;

	return 0;
}
