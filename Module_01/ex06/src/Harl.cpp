/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:22:46 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/28 15:33:21 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void	Harl::debug( void ) {
	std::cout << CYAN << "[ DEBUG ]" << RESET << std::endl;
	std::cout << GREEN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET << std::endl;
}

void	Harl::info( void ) {
	std::cout << CYAN << "[ INFO ]" << RESET << std::endl;
	std::cout << GREEN << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}

void	Harl::warning( void ) {
	std::cout << CYAN << "[ WARNING ]" << RESET << std::endl;
	std::cout << GREEN << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << RESET << std::endl;
}

void	Harl::error( void ) {
	std::cout << CYAN << "[ ERROR ]" << RESET << std::endl;
	std::cout << GREEN << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

void	Harl::complain( std::string level ) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*ft[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*ft[i])();
			return ;
		}
	}
}

int	getLevelIndex(std::string level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			return (i);
		}
	}
	return (-1);
}
