/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:37:24 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/21 10:37:24 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::~Zombie() {
	std::cout << _name << " is destroyed!" << std::endl;
}

void	Zombie::setName(std::string name) {
	_name = name;
}

void	Zombie::announce() const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
