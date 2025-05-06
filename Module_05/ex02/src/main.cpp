/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:35:03 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/06 18:36:07 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Bureaucrats avec différents grades
        Bureaucrat bob("Bob", 140);        // Peut signer le Shrubbery form
        Bureaucrat alice("Alice", 50);     // Peut signer/exécuter Robotomy
        Bureaucrat zaphod("Zaphod", 1);    // Peut tout faire

        std::cout << "==== Testing ShrubberyCreationForm ====" << std::endl;
        ShrubberyCreationForm shrub("garden");
        std::cout << shrub << std::endl;
        bob.signForm(shrub);
        bob.executeForm(shrub); // Execution échoue, grade insuffisant
        zaphod.executeForm(shrub); // Execution réussie

        std::cout << "\n==== Testing RobotomyRequestForm ====" << std::endl;
        RobotomyRequestForm robot("Marvin");
        std::cout << robot << std::endl;
        alice.signForm(robot);
        alice.executeForm(robot); // Exécution (random success/failure)

        std::cout << "\n==== Testing PresidentialPardonForm ====" << std::endl;
        PresidentialPardonForm pardon("Ford");
        std::cout << pardon << std::endl;
        zaphod.signForm(pardon);
        zaphod.executeForm(pardon); // Execution réussie

    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}