/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:43:15 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/21 10:43:15 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		std::ostringstream fullName;
		fullName << name << (i + 1);
		horde[i].setName(fullName.str());
	}
	return (horde);
}
