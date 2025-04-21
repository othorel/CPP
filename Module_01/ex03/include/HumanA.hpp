/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:26:24 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/21 16:26:24 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA {
	public:

		HumanA(const std::string& name, Weapon& weapon);
		~HumanA();

		void attack() const;

	private:

		std::string name;
		Weapon& weapon;
};

#endif