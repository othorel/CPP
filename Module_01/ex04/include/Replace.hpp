/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:50:19 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/28 14:20:06 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <iostream>
# include <fstream>

# define RED     "\033[31m"
# define CYAN    "\033[36m"
# define RESET   "\033[0m"

class Replace {
    public:
    
    Replace();
    ~Replace();
    
    void processFile(const std::string& filename, const std::string& s1,const std::string& s2);
};

#endif