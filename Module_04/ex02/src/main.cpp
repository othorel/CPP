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
	std::cout << "=== Trying to instantiate AAnimal (should fail) ===" << std::endl;
	//AAnimal test; //test for instance

    std::cout << "=== Creating Animals ===" << std::endl;

    const int size = 10;
    AAnimal* animals[size];
    srand(time(0));

    for (int i = 0; i < size; ++i) {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n=== Setting and displaying each animal's ideas ===" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << animals[i]->getType() << " : " << std::endl;
        if (Dog* dog = dynamic_cast<Dog*>(animals[i])) {
            int ideaIndex = rand() % 10;
            dog->getBrain()->setIdea(0, dog->getBrain()->getIdea(ideaIndex));
            std::cout << "Idea : " << dog->getBrain()->getIdea(0) << std::endl;
        }
        else if (Cat* cat = dynamic_cast<Cat*>(animals[i])) {
            int ideaIndex = rand() % 10;
            cat->getBrain()->setIdea(0, cat->getBrain()->getIdea(ideaIndex));
            std::cout << "Idea : " << cat->getBrain()->getIdea(0) << std::endl;
        }
    }

    std::cout << "\n=== Destroying Animals ===" << std::endl;
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }
    return (0);
}
