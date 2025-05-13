/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:53:45 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/13 16:23:39 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>
# include <iterator>
# include <vector>
# include <list>

class notFoundException : public std::exception {
	
	public:

		virtual const char* what() const throw() {
			return ("Value not found in container.");
		}
};

template <typename T>

typename T::iterator easyfind(T& container, int value);

# include "easyfind.tpp"

#endif