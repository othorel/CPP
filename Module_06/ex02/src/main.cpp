/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:19:16 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/12 15:41:37 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base* generate() {
	std::srand(std::time(0));
	int r = std::rand() % 3;
	
	if (r == 0)
		return (new A);
	else if (r == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	} catch (const std::bad_cast& e) {}
	
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	} catch (const std::bad_cast& e) {}

	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	} catch (const std::bad_cast& e) {}
}

int main() {
	Base* ptr = generate();

	std::cout << "Identify using pointer: ";
	identify(ptr);

	std::cout << "Identify using reference: ";
	identify(*ptr);
	delete(ptr);
	return (0);
}
