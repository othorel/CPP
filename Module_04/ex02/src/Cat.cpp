/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:21:33 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/01 16:21:33 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
	std::cout << "Cat constructeur called, type: Cat" << std::endl;
	_brain = new Brain();
}

Cat::Cat(std::string type) : AAnimal(type) {
	std::cout << "Cat constructor called, type: " << type << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat& other) : AAnimal(other) {
	std::cout << "Cat copy constructor called on " << other._type << std::endl;
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called on " << other._type << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called, type: " << this->_type << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Miaou! Miaou!" << std::endl;
}

Brain* Cat::getBrain() const {
	return (_brain);
}
