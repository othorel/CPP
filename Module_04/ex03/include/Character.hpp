/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:11:23 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/02 16:11:23 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter {
	
	public:

		Character(std::string const &name);
		Character(Character const &other);
		~Character();
		Character& operator=(Character const &other);

		std::string const &getName() const;
		void equip(AMateria* materia);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:

		std::string _name;
		AMateria* _inventory[4];
};

#endif