/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:42:10 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/01 12:49:53 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    ScavTrap scav("Serena");

    scav.attack("enemy");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();

    return (0);
}