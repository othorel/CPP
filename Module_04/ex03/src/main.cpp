/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:09:35 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/03 15:09:35 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
	IMateriaSource* src = new MateriaSource();
	// Create temporary Materias to teach to the source
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	 // Teach the source by cloning them internally, then delete originals
	src->learnMateria(ice);
	src->learnMateria(cure);
	delete ice;
	delete cure;

	ICharacter* me = new Character("me");
	// Create and equip Materias cloned from the source
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	return (0);
}

// Function to print title for testing phases
// static void title(const char* msg)
// {
//     std::cout << "\n=== " << msg << " ===\n";
// }

// int main() {
//     title("Setup materia source");
//     IMateriaSource* src = new MateriaSource();
//     // Teach two materias
//     AMateria* ice = new Ice();
//     AMateria* cure = new Cure();
//     src->learnMateria(ice);
//     src->learnMateria(cure);
//     delete ice; delete cure; // Clean up

//     title("Test createMateria with unknown type");
//     // Test creating a materia with an unknown type
//     AMateria* none = src->createMateria("fire");
//     std::cout << "createMateria(\"fire\") -> " 
//               << (none ? "not NULL" : "NULL") 
//               << std::endl;
//     delete none; // Safe even if none is NULL

//     title("Setup character and over-equip");
//     ICharacter* me = new Character("me");
//     // Try equipping 5 materias (should only equip 4 max)
//     for (int i = 0; i < 5; ++i) {
//         AMateria* m = src->createMateria(i % 2 ? "ice" : "cure");
//         me->equip(m);
//         std::cout << "equip(" << (i % 2 ? "ice" : "cure") 
//                   << ") attempt #" << (i+1) << std::endl;
//     }

//     title("Test use on valid and invalid slots");
//     // Test use of valid slots
//     me->use(0, *me);
//     me->use(1, *me);
//     // Test invalid slots (index out of bounds and empty slot)
//     me->use(4, *me);
//     me->use(-1, *me);

//     title("Test unequip and reuse slot");
//     me->unequip(1); // Unequip index 1
//     std::cout << "After unequip(1), use(1) -> ";
//     me->use(1, *me);
//     // Re-equip a new materia and use the slot again
//     AMateria* newIce = src->createMateria("ice");
//     me->equip(newIce);
//     std::cout << "After re-equip ice, use(1) -> ";
//     me->use(1, *me);

//     title("Test deep copy of Character");
//     // Test deep copy of the Character object
//     Character copy = *static_cast<Character*>(me);
//     std::cout << "Original use(0) -> ";
//     me->use(0, *me);
//     std::cout << "Copy     use(0) -> ";
//     copy.use(0, copy); // Ensure the copy works independently

//     title("Cleanup");
//     delete me;  // This will delete all materias in the character's inventory
//     delete src; // Clean up MateriaSource

//     return (0);
// }
