/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:38:58 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/30 10:04:14 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point {
	
	public:
	
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();

		Fixed getX() const;
		Fixed getY() const;

	private:

		const Fixed x;
		const Fixed y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif