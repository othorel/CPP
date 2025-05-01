/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:06:35 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/01 16:06:35 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal constructeur called, type: Animal" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal constructor called, type: " << type << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "Animal copy constructor called on " << other._type << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other)
		this->_type = other._type;
	std::cout << "Animal assignment operator called on " << other._type << std::endl;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called, type: " << this->_type << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal makes a generic sound" << std::endl;
}

std::string Animal::getType() const {
	return (this->_type);
}
