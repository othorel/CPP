/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:51:56 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/30 09:57:29 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Produit vectoriel (AB x AC)
static Fixed crossVector(Point const& a, Point const& b, Point const& c) {
	Fixed ab_x = b.getX() - a.getX();
	Fixed ab_y = b.getY() - a.getY();
	Fixed ac_x = c.getX() - a.getX();
	Fixed ac_y = c.getY() - a.getY();

	Fixed result = (ab_x * ac_y) - (ab_y * ac_x);
	return (result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed p1 = crossVector(point, a, b);
	Fixed p2 = crossVector(point, b, c);
	Fixed p3 = crossVector(point, c, a);
	
	bool isNeg  = (p1 < 0) || (p2 < 0) || (p3 < 0);
	bool isPos  = (p1 > 0) || (p2 > 0) || (p3 > 0);
	bool isZero = (p1 == 0) || (p2 == 0) || (p3 == 0);

	if (!isZero && !(isNeg && isPos))
		return (true);
	else
		return (false);
}
