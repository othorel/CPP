/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:25:05 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/28 16:08:40 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << RED << "Usage: ./harlfilter <level>" << RESET << std::endl;
		return (1);
	}
	
	Harl harl;
	std::string level = av[1];
	int	levelIndex = getLevelIndex(level);
	
	if (levelIndex == -1) {
		std::cerr << RED << "[Probably complaining about insignificant problems]" << RESET << std::endl;
		return (1);
	}
	switch (levelIndex) {
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cerr << RED << "[Probably complaining about insignificant problems]" << RESET << std::endl;
	}
	return (0);
}