/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:06:35 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/01 16:06:35 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << "AAnimal constructeur called, type: AAnimal" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << "AAnimal constructor called, type: " << type << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
	std::cout << "AAnimal copy constructor called on " << other._type << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if (this != &other)
		this->_type = other._type;
	std::cout << "AAnimal assignment operator called on " << other._type << std::endl;
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called, type: " << this->_type << std::endl;
}

std::string AAnimal::getType() const {
	return (this->_type);
}
