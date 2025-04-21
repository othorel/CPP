/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:50:06 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/21 10:50:06 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie *horde = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
