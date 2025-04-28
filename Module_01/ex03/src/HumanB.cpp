/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:11:48 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/28 11:44:02 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL) {
}

HumanB::~HumanB() {
}

void	HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

void	HumanB::attack() const {
	if (_weapon)
		std::cout << _name << " Attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " Has no weapon to attack" << std::endl;
}

