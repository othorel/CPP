/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:04:47 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/02 16:04:47 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {

	public:

		Cure();
		Cure(Cure const &other);
		~Cure();
		Cure& operator=(Cure const &other);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif