/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:02:46 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/20 15:02:46 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
	public:

		Zombie(std::string name);
		~Zombie();

		void announce() const;
		
		private:
		
		std::string name;
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);
		

#endif
