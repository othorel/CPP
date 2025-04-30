/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:18:27 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/30 14:26:25 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main() {
	ClapTrap luffy("Luffy");
	ClapTrap kizaru("Kizaru");

	luffy.attack("Kizaru");
	kizaru.takeDamage(0);
	kizaru.attack("Luffy");
	luffy.takeDamage(0);
	luffy.beRepaired(5);
	
	for (int i = 0; i < 11; i++)
		luffy.attack("Kizaru");
	kizaru.takeDamage(10);
	kizaru.attack("Luffy");
	return (0);
}
