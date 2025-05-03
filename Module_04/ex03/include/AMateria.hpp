/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:32:55 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/03 15:32:55 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class AMateria {
	public:
  	 	AMateria();
 	    AMateria(std::string const &type);
 	    AMateria(AMateria const &other);
 	    virtual ~AMateria();
  	    AMateria& operator=(AMateria const &other);

  	    std::string const &getType() const;
  	    virtual AMateria* clone() const = 0;
  	    virtual void use(ICharacter& target);
 
	protected:

   		std::string _type;
};

#endif