/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:49:29 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/21 15:49:29 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << "String's adress : "     << &brain << std::endl;
	std::cout << "String's ptr adress : " << stringPTR << std::endl;
	std::cout << "String's ref adress : " << &stringREF<< std::endl;

	std::cout << "String's value : "     << brain << std::endl;
	std::cout << "String's ptr value : " << *stringPTR << std::endl;
	std::cout << "String's ref value : " << stringREF<< std::endl;
	return (0);
}
