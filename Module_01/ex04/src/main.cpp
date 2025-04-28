/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:44:31 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/28 13:44:37 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int ac, char **av) {
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	Replace replacer;

	if (ac != 4) {
		std::cerr << RED << "Usage: ./replace <filename> <s1> <s2>" << RESET << std::endl;
		return (1);
	}
	replacer.processFile(filename, s1, s2);
	return (0);
}
