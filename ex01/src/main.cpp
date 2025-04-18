/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:37:28 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/17 14:10:33 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	phonebook;
	std::string	command;

	std::cout << CYAN <<"==============================" << RESET << std::endl;
	std::cout << CYAN << " 📞  " << BOLD << "My Awesome PhoneBook" << RESET << CYAN << "  📞 " << RESET << std::endl;
	std::cout << CYAN <<"==============================" << RESET << std::endl;

	while (true) {
		std::cout << "Please enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin,command);
		if (std::cin.eof()) {
			std::cout << "\n👋 EOF received. Exiting." << std::endl;
			break ;
		}
		if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT") {
			std::cout << CYAN << "👋 Goodbye!" << RESET << std::endl;
			break ;
		}
		else if (!command.empty())
			std::cerr << RED << "Unknown command. Please use ADD, SEARCH or EXIT." << RESET << std::endl;
	}
	return (0);
}
