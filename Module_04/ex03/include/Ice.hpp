/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:40:16 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/02 15:40:16 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {

	public:

		Ice();
		Ice(Ice const &other);
		~Ice();
		Ice& operator=(Ice const &other);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif