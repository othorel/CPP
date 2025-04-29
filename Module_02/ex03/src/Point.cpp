/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:44:58 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/29 16:50:16 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point(const float xVal, const float yVal) : x(xVal), y(yVal) {
}

Point::Point(const Point& other) : x(other.x), y(other.y) {
}

Point& Point::operator=(const Point& other) {
	(void)other;
	return (*this);
}

Point::~Point() {
}

Fixed Point::getX() const {
	return (x);
}

Fixed Point::getY() const {
	return (y);
}
