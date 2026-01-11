/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:01:30 by jose-gon          #+#    #+#             */
/*   Updated: 2026/01/11 18:54:09 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

int main(int argc, char **argv)
{
 	if (argc != 2)
 		return 1;
	BitcoinExchange exchange;
	try
	{
		exchange.loadRates("data.csv");
		exchange.exchangeValues(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
