/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:39:44 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/28 15:16:26 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

# define CYAN    "\033[36m"
# define GREEN   "\033[32m"
# define RESET   "\033[0m"

class Harl {
	public:
	
		Harl();
		~Harl();

		void complain( std::string level );

	private:
	
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif