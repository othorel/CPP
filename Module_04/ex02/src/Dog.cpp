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

Dog::Dog() : AAnimal("Dog") {
	std::cout << "Dog constructeur called, type: Dog" << std::endl;
	_brain = new Brain();
}

Dog::Dog(std::string type) : AAnimal(type) {
	std::cout << "Dog constructor called, type: " << type << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other) {
	std::cout << "Dog copy constructor called on " << other._type << std::endl;
	_brain = new Brain(*other._brain);
	
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called on " << other._type << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called, type: " << this->_type << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Wouaf! Wouaf!" << std::endl;
}

Brain* Dog::getBrain() const {
	return (_brain);
}
