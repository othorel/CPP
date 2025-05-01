/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:13:57 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/01 17:13:57 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* h = new Animal();
	const Animal* i = new Cat("Ron");
	const Animal* j = new Dog("Raymond");
	const WrongAnimal* k = new WrongAnimal();
	const WrongCat* l = new WrongCat();

	std::cout << std::endl;
	std::cout << h->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	std::cout << std::endl;

	h->makeSound();
	i->makeSound();
	j->makeSound();
	k->makeSound();
	l->makeSound();
	std::cout << std::endl;

	delete h;
	delete i;
	delete j;
	delete k;
	delete l;

	return (0);
}
