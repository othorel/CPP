/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:08:34 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/06 17:08:15 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :
	_name("DefaultAForm"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExec(150),
	_target("Default") {
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec, const std::string& target) :
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec),
	_target(target) {
		
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();	
}

AForm::AForm(const AForm& other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExec(other._gradeToExec), 
	_target(other._target) {
}

AForm::~AForm() {
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

const std::string& AForm::getName() const {
	return (_name);
}

const std::string& AForm::getTarget() const {
	return (_target);
}

bool AForm::getIsSigned() const {
	return (_isSigned);
}

int AForm::getGradeToSign() const {
	return (_gradeToSign);
}

int AForm::getGradeToExec() const {
	return (_gradeToExec);
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (_isSigned)
		return;
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const& executor) const {
	if (!_isSigned)
		throw std::runtime_error("Form not signed");
	if (executor.getGrade() > _gradeToExec)
		throw GradeTooLowException();
	executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return ("AForm grade too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("AForm grade too low");
}

std::ostream& operator<<(std::ostream& out, const AForm& Aform) {
	out << "AForm \"" << Aform.getName()
		<< "\", signed: " << std::boolalpha << Aform.getIsSigned()
		<< ", Grade to sign: " << Aform.getGradeToSign()
		<< ", Grade to execute: " << Aform.getGradeToExec();
	return (out);
}