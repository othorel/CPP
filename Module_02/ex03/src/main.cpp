/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:48:14 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/30 10:07:25 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);

	Point inside(1, 1);
	Point outside(5, 5);
	Point onEdge(0, 0);

	std::cout << "Inside return "  << bsp(a, b, c, inside)  << std::endl;
	std::cout << "Outside return " << bsp(a, b, c, outside) << std::endl; 
	std::cout << "On edge return " << bsp(a, b, c, onEdge)  << std::endl; 

	return (0);
}
