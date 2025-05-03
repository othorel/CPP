/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:14:44 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/02 15:14:44 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {
}

AMateria::AMateria(std::string const &type) : _type(type) {
}

AMateria::AMateria(AMateria const &other) {
	*this = other;
}

AMateria::~AMateria() {
}

AMateria& AMateria::operator=(AMateria const &other) {
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string const &AMateria::getType() const {
	return (this->_type);
}

void AMateria::use(ICharacter& target) {
	(void)target;
}
