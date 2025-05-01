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

int main() {
	std::cout << "=== Creating Animals ===" << std::endl;

	Animal* animals[10];
	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Dog();
	animals[3] = new Dog();
	animals[4] = new Dog();
	animals[5] = new Cat();
	animals[6] = new Cat();
	animals[7] = new Cat();
	animals[8] = new Cat();
	animals[9] = new Cat();

	std::cout << "\n=== Displaying each animal's ideas ===" << std::endl;
	for (int i = 0; i < 10; i++) {
        std::cout << animals[i]->getType() << " : " << std::endl;
        for (int j = 0; j < 9; j++) {
            std::cout << std::setw(30) << std::left << animals[i]->getBrain()->getIdea(j) << std::endl;
        }
    }

	std::cout << "\n=== Destroying Animals ===" << std::endl;
	for (int i = 0; i < 10; i++) {
        delete animals[i];
    }
    return (0);
}
