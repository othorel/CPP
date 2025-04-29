/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:51:56 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/29 16:57:56 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Produit vectoriel (AB x AC)
static Fixed crossVector(Point const& a, Point const& b, Point const& c) {
	Fixed ab_x = b.getX() - a.getX();
	Fixed ab_y = b.getX() - a.getY();
	Fixed 
}