/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:22:04 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/13 17:21:20 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
	
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::list<int> lst;
	vec.push_back(10);
	vec.push_back(20);
	lst.push_back(30);

	try {
		std::vector<int>::iterator it = easyfind(vec, 2);
		std::cout << "Found in vector : " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Vector error : " << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator it = easyfind(lst, 25);
		std::cout << "Found in list : " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "List error : " << e.what() << std::endl;
	}
	return (0);
}
