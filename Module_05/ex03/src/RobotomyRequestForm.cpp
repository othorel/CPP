/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:39:03 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/06 17:55:43 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("RobotomyRequestForm", 72, 45, target) {
	std::srand(std::time(0));		
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void RobotomyRequestForm::executeAction() const {
	std::cout << "Drilling noises..." << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << "Robotomy on " << getTarget() << " has been succefull!" << std::endl;
	else
		std::cout << "Robotomy on " << getTarget() << " failed!" << std::endl;
}
