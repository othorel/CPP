/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:14:57 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/01 13:14:57 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called for " << _name << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for " << _name << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "FragTrap " << _name << " cannot attack (no HP or energy)." << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " request a high five!" << std::endl;
}
