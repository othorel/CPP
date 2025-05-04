/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:35:00 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/04 11:35:00 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void testBureaucrat(const std::string& name, int grade)
{
    try {
        Bureaucrat b(name, grade);
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << "After increment: " << b << std::endl;
        b.decrementGrade();
        std::cout << "After decrement: " << b << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception for " << name << " (grade " << grade << "): " << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "--- Valid Bureaucrats ---" << std::endl;
    testBureaucrat("John", 75);
    testBureaucrat("Alice", 2);
    testBureaucrat("Bob", 149);

    std::cout << "\n--- Invalid Bureaucrats ---" << std::endl;
    testBureaucrat("Clara", 0);// too high
    testBureaucrat("Dave", 151);// too low

    std::cout << "\n--- Edge Increment/Decrement ---" << std::endl;

    try {
        Bureaucrat top("Max", 1);
        std::cout << top << std::endl;
        top.incrementGrade();// Should throw
    }
    catch (std::exception& e) {
        std::cout << "Exception on incrementing Max: " << e.what() << std::endl;
    }

    try {
        Bureaucrat low("Min", 150);
        std::cout << low << std::endl;
        low.decrementGrade();// Should throw
    }
    catch (std::exception& e) {
        std::cout << "Exception on decrementing Min: " << e.what() << std::endl;
    }

    return 0;
}
