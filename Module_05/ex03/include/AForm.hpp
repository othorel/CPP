/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:29:02 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/09 11:45:24 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class AForm {
	
	public:

		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExec, const std::string& target);
		AForm(const AForm& other);
		virtual ~AForm();
		AForm& operator=(const AForm& other);

		const std::string& getName() const;
		const std::string& getTarget() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		void beSigned(const Bureaucrat& bureaucrat);
		void execute(Bureaucrat const& executor) const;

		class GradeTooHighException : public std::exception {

		public:

			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {

		public:

			const char* what() const throw();
		};

	protected:

		virtual void executeAction() const = 0;

	private:

		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;
		const std::string _target;

};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif