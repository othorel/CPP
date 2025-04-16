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

class PhoneBook {
	public:

		PhoneBook();
		~PhoneBook();
		void	add_contact(void);
		void	search_contact(void);

	private:

		Contact	contacts[8];
		int	count;
		int	old;
};

#endif