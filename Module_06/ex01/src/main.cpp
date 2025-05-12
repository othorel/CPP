/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:13:47 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/12 11:24:17 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
	Data data;
	data.nb = 42;
	data.txt = "Hello World";

	std::cout << "Original pointer: " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	Data* recovered = Serializer::deserialize(raw);

	std::cout << "Recovered pointer: " << recovered << std::endl;

	if (recovered == &data)
		std::cout << "Success: The pointer was correctly serialized and deserialized." << std::endl;
	else
		std::cout << "Failure: The pointers do not match." << std::endl;
	std::cout << "Recovered data: number = " << recovered->nb << ", text = " << recovered->txt << std::endl;
	return (0);
}
