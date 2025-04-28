/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:54:25 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/28 14:20:55 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace() {
}

Replace::~Replace() {
}

void	Replace::processFile(const std::string& filename, const std::string& s1,const std::string& s2) {
	std::ifstream inputFile(filename.c_str());

	if (!inputFile.is_open()) {
		std::cerr << RED << "Error: Could not open file " << RESET << filename << std::endl;
		return ;
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	
	if (!outputFile.is_open()) {
		std::cerr << RED << "Error: Could not create file " << RESET << filename + ".replace" << std::endl;
		return ;
	}
	std::string line;
	size_t pos;
	while (std::getline(inputFile, line)) {
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
	outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
	std::cout  << CYAN << "File " << filename << " has been processed and saved as " << RESET << filename + ".replace" << std::endl;
}
