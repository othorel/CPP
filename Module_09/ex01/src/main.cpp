/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:40:28 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/15 15:48:34 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2)
	{
		std::cerr << "Error: invalid numbers of arguments" << std::endl;
		return (1);
	}
	RPN rpn;
	try {
		int result = rpn.evaluate(av[1]);
		std::cout << result << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
