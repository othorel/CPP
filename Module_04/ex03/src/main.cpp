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
