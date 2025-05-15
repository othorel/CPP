/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:28:53 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/15 14:38:46 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <stack>
# include <exception>
# include <sstream>
# include <cstdlib>
# include <cctype>

class RPN {

	public:

		RPN();
		RPN(const RPN& other);
		~RPN();
		RPN& operator=(const RPN& other);
		
		int evaluate(const std::string& expression);
		
	private:

		bool isOperator(const std::string& token) const;
		int applyOperator(const std::string& op, int a, int b) const;
		
	class DivisionByZeroException : public std::exception {
		
		public:
		
			const char* what() const throw();
	};
	class InvalidOperatorException : public std::exception {

		public:

			const char* what() const throw();
	};
	class InvalidTokenException : public std::exception {
		
		public:

			const char* what() const throw();
	};
	class InvalidExpressionException : public std::exception {

		public:

			const char* what() const throw();
	};
};

#endif