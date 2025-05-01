/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:41:44 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/01 11:53:59 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << name << " has been constructed." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " has been destroyed." << std::endl;
}

ClavTrap::ClavTrap(const ClavTrap& other) = default;

ClavTrap ClavTrap::operator(const ClavTrap& other) = default;

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " cannot attack (no HP or energy)." << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! HP now: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " cannot repair (no HP or energy)." << std::endl;
		return ; 
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount << " hit points! HP now: " << _hitPoints << std::endl;
}
