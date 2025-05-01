/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:33:01 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/01 13:33:01 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap constructor called for " << _name << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "DiamondTrap " << _name << " cannot attack (no HP or energy)." << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "DiamondTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount) {
	ClapTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount) {
	ClapTrap::beRepaired(amount);
}

void DiamondTrap::whoAmI() {
	std::cout << "I am " << _name << " and my ClapTrap name is " << getClapName() << std::endl;
}
