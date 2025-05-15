/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:38:53 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/15 15:46:18 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
	(void)other;
}

RPN& RPN::operator=(const RPN& other) {
	(void)other;
	return (*this);
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::applyOperator(const std::string& op, int a, int b) const {
	if (op == "+")
		return (a + b);
	else if (op == "-")
		return (a - b);
	else if (op == "*")
		return (a * b);
	else if (op == "/") {
		if (b == 0)
			throw DivisionByZeroException();
		return (a / b);
	}
	throw InvalidOperatorException();
}

int RPN::evaluate(const std::string& expression) {
	std::stack<int> stack;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (token.length() == 1 && std::isdigit(token[0]))
			stack.push(token[0] - '0');
		else if (isOperator(token)) {
			if (stack.size() < 2)
				throw InvalidExpressionException();
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			int result = applyOperator(token, a, b);
			stack.push(result);
		}
		else
			throw InvalidTokenException();
	}
	if (stack.size() != 1)
		throw InvalidExpressionException();
	return (stack.top());
}

const char* RPN::DivisionByZeroException::what() const throw() {
	return ("Division by zero");
}

const char* RPN::InvalidOperatorException::what() const throw() {
	return ("Invalid operator");
}

const char* RPN::InvalidExpressionException::what() const throw() {
	return ("Invalid expression");
}

const char* RPN::InvalidTokenException::what() const throw() {
	return ("Invalid token");
}
