/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:22:22 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/05 14:51:28 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	
	public:

		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExec);
		Form(const Form& other);
		~Form();
		Form& operator=(const Form& other);

		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {

		public:

			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {

		public:

			const char* what() const throw();
		};

	private:

		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;

};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif