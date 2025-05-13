/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:09:32 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/13 13:50:49 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T>

void iter(T* tab, size_t len, void (*ft)(T const &)) {
	for (size_t i = 0; i < len; i++)
		ft(tab[i]);
}
//FT test for iter
template <typename T>

void print(const T& elem) {
	std::cout << elem << " ";
}

#endif