/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:40:09 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/01 11:51:22 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap {

	public:

		ClapTrap(const std::string& name);
		virtual ~ClapTrap();
		ClavTrap(const ClavTrap& other);
		ClavTrap& operator=(const ClavTrap& other);

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:

		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;							
};

#endif