/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:22:29 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/20 15:22:29 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie* zombie1 = newZombie("foo");
	zombie1->announce();
	delete zombie1;
	randomChump("Bar");
	return (0);
}
