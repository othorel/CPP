/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:35:03 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/09 14:56:54 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
	try {
		Intern intern;
		Bureaucrat boss("Boss", 1);  // Grade 1 = peut tout faire

		AForm* f1 = intern.makeForm("shrubbery creation", "Garden");
		AForm* f2 = intern.makeForm("robotomy request", "Bender");
		AForm* f3 = intern.makeForm("presidential pardon", "Morty");

		f1->beSigned(boss);
		f2->beSigned(boss);
		f3->beSigned(boss);

		boss.executeForm(*f1);
		boss.executeForm(*f2);
		boss.executeForm(*f3);

		delete f1;
		delete f2;
		delete f3;

		std::cout << std::endl;

		AForm* bad = intern.makeForm("does not exist", "Nobody");
		delete bad;
	}
	catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	return (0);
}
