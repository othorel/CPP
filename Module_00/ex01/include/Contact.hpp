/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:31:33 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/16 16:31:33 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>

class Contact {
	public:

		Contact();
		~Contact();

		void setContact();
    	bool isValid() const;
  	 	void displaySummary(int index) const;
    	void displayFull() const;

	private:

		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;
		std::string formatField(const std::string& str) const;
		bool isPhoneNumberValid(const std::string& number) const;
};

#endif