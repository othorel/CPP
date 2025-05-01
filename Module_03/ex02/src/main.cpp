/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:08:48 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/01 13:23:52 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
	FragTrap luffy("Luffy");

	luffy.attack("Kizaru");
	luffy.takeDamage(40);
	luffy.beRepaired(20);
	luffy.highFivesGuys();

	return (0);
}
