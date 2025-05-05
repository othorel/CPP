/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:52:12 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/05 16:16:28 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
	_name("DefaultForm"),
	_isSigned(false),
	_gradeToSign(75),
	_gradeToExec(75) {
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec) :
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec) {
		
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();	
};

Form::Form(const Form& other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExec(other._gradeToExec) {
}

Form::~Form() {
}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

const std::string& Form::getName() const {
	return (_name);
}

bool Form::getIsSigned() const {
	return (_isSigned);
}

int Form::getGradeToSign() const {
	return (_gradeToSign);
}

int Form::getGradeToExec() const {
	return (_gradeToExec);
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (_isSigned)
		return ;
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return ("Form grade too high");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Form grade too low");
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
	out << "Form \"" << form.getName()
		<< "\", signed: " << std::boolalpha << form.getIsSigned()
		<< ", Grade to sign: " << form.getGradeToSign()
		<< ", Grade to execute: " << form.getGradeToExec();
	return (out);
}
