/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:35:00 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/04 11:35:00 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		std::cout << "===== TEST 1: Bureaucrats =====" << std::endl;
		Bureaucrat bob("Bob", 50);
		Bureaucrat alice("Alice", 5);
		std::cout << bob << std::endl;
		std::cout << alice << std::endl;

		std::cout << "\n===== TEST 2: Valid Form =====" << std::endl;
		Form taxForm("TaxForm", 10, 20);
		std::cout << taxForm << std::endl;

		std::cout << "\n===== TEST 3: Bob tries to sign TaxForm (should fail) =====" << std::endl;
		bob.signForm(taxForm);

		std::cout << "\n===== TEST 4: Alice signs TaxForm (should succeed) =====" << std::endl;
		alice.signForm(taxForm);
		std::cout << taxForm << std::endl;

		std::cout << "\n===== TEST 5: Creating Form with grade too high =====" << std::endl;
		try {
			Form impossibleHigh("ImpossibleHigh", 0, 20); // invalid
		} catch (const std::exception& e) {
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}

		std::cout << "\n===== TEST 6: Creating Form with grade too low =====" << std::endl;
		try {
			Form impossibleLow("ImpossibleLow", 151, 20); // invalid
		} catch (const std::exception& e) {
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}

		std::cout << "\n===== TEST 7: Re-signing already signed form =====" << std::endl;
		alice.signForm(taxForm); // déjà signé, voir comportement

		std::cout << "\n===== TEST 8: Another valid form =====" << std::endl;
		Form leaveForm("LeaveRequest", 75, 75);
		std::cout << leaveForm << std::endl;

		std::cout << "\n===== TEST 9: Bob signs LeaveRequest (should succeed) =====" << std::endl;
		bob.signForm(leaveForm);
		std::cout << leaveForm << std::endl;

	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return(0);
}
