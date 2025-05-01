/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:00:52 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/01 12:02:24 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClavTrap(name) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::~ScavTrap() {
	st::cout << "ScavTrap destructor called for " << _name << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "ScavTrap " << _name << " cannot attack (no HP or energy)." << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
