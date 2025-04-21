/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:33:12 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/21 10:33:12 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <sstream>

class Zombie {
	public:

		Zombie();
		~Zombie();

		void setName(std::string name);
		void announce() const;
		
		private:
		
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);
		
#endif
