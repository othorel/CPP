/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:43:37 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/30 11:11:46 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	public:
	
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		~Fixed();
		//Operateur affectation
		Fixed& operator=(const Fixed& other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		//Conversion
		int toInt( void ) const;
		float toFloat( void ) const;
		
	private:
	
		int	_fixedValue;
		static const int _fractBit = 8;
};
//Surcharge operateur <<
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif