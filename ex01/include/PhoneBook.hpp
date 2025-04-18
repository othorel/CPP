/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:10:40 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/16 16:10:40 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define RESET   "\033[0m"
# define CYAN    "\033[36m"
# define RED     "\033[31m"
# define BOLD    "\033[1m"

class PhoneBook {
	public:

		PhoneBook();
		~PhoneBook();
		void add_contact(void);
		void search_contact(void);

	private:

		Contact	contacts[8];
		int	_count;
		int	_old;
};

#endif