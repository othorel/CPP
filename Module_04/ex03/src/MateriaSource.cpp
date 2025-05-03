/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:58:42 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/03 14:58:42 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_storage[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other) {
	for (int i = 0; i < 4; i++) {
		if (other._storage[i])
			_storage[i] = other._storage[i]->clone();
		else
		_storage[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		delete _storage[i];
}

MateriaSource& MateriaSource::operator=(MateriaSource const &other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			delete _storage[i];
			if (other._storage[i])
				_storage[i] = other._storage[i]->clone();
			else
				_storage[i] = NULL;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia) {
	if (!materia)
		return ;
	for (int i = 0; i < 4; i++) {
		if (!_storage[i]) {
			_storage[i] = materia->clone();
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_storage[i] && _storage[i]->getType() == type)
			return (_storage[i]->clone());
	}
	return (0);
}
