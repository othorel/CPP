/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:16:36 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/01 16:16:36 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructeur called, type: Dog" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog constructor called, type: " << type << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called on " << other._type << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Dog assignment operator called on " << other._type << std::endl;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called, type: " << this->_type << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Wouaf! Wouaf!" << std::endl;
}
