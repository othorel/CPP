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

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructeur called, type: Cat" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat constructor called, type: " << type << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor called on " << other._type << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Cat assignment operator called on " << other._type << std::endl;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called, type: " << this->_type << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Miaou! Miaou!" << std::endl;
}
