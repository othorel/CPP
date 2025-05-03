/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:24:14 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/02 16:24:14 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const &other) : _name(other._name) {
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
		_inventory[i] = NULL;
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

Character& Character::operator=(Character const &other) {
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++) {
			delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
			_inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const &Character::getName() const {
	return (_name);
}

void Character::equip(AMateria* materia) {
	if (!materia)
		return ;
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = materia;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4)
		return ;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4)
		return ;
	if (_inventory[idx])
		_inventory[idx]->use(target);
}
