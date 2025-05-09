/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:47:46 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/09 14:53:26 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern &other) {
	(void)other;
	return (*this);
}

Intern::~Intern() {
}

static AForm *createShrubbery(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomy(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

static AForm *createPardon(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string const &formName, std::string const &target) const {
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (*formCreators[3])(const std::string&) = {
		&createShrubbery,
		&createRobotomy,
		&createPardon
	};
	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (formCreators[i](target));
		}
	}
	std::cerr << "Error: Form `" << formName << "' does not exist." << std::endl;
	throw Intern::WrongNameException();
	
}

const char* Intern::WrongNameException::what() const throw() {
	return ("Intern exception: unknown form name.");
}
