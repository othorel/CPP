/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:16:14 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/13 13:26:49 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <iostream>
#include "iter.hpp"

int main() {
	int int_tab[] = {1, 2, 3, 4, 5};
	std::string string_tab[] = {"hello", "world", "test"};

	std::cout << "Test with int tab : ";
	iter(int_tab, 5, print);
	std::cout << std::endl;

	std::cout << "Test with string tab: ";
	iter(string_tab, 3, print);
	std::cout << std::endl;

	return (0);
}
