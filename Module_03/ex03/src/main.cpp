/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:08:48 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/01 13:46:11 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	DiamondTrap Diamond("Luffy");

	Diamond.attack("Kizaru");
	Diamond.takeDamage(50);
	Diamond.beRepaired(30);
	Diamond.whoAmI();

    return (0);
}
