/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:12:13 by jose-gon          #+#    #+#             */
/*   Updated: 2025/10/07 18:17:48 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include <iomanip>

class BitcoinExchange
{
	private:
	
		std::map<int, double> _datab;
		
	public:
	
		BitcoinExchange();
		~BitcoinExchange();

		int isValidDate(std::string date);
		double isValidValue(std::string val);
		double isValidValueLimit(std::string val, int n);
		void makeExchange(std::map<int, double>::iterator it, double val);
		void loadRates(const std::string &rates);
		void exchangeValues(const std::string &file);
};

#endif
