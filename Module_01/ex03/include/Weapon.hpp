/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:35:25 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/21 16:35:25 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
    public:

        Weapon(const std::string& type);
        ~Weapon();

        const std::string& getType() const;
        void setType(const std::string& type);

    private:

        std::string _type;

};

#endif