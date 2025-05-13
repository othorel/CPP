/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:52:38 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/13 10:44:48 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>

void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>

T const &min(T const &a, T const &b) {
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>

T const &max(T const &a, T const &b) {
	if (a > b)
		return (a);
	else
		return (b);
}

#endif