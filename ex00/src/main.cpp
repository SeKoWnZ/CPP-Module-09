/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:01:30 by jose-gon          #+#    #+#             */
/*   Updated: 2025/09/26 19:51:46 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExange.hpp>

int main()
{
// 	if (argc != 2)
// 		return 1;
	BitcoinExange exange;
	try
	{
		exange.loadRates("data.csv");

		std::map<std::string, double> data = exange.getData();
        for (std::map<std::string, double>::const_iterator it = data.begin(); it != data.end(); ++it) {
            std::cout << it->first << " => " << it->second << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
}
