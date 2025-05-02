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
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
		_inventory[i] = NULL;
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}
