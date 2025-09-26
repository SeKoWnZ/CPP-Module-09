/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExange.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:12:13 by jose-gon          #+#    #+#             */
/*   Updated: 2025/09/26 19:57:04 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXANGE_HPP
#define BITCOINEXANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <cstdlib>

class BitcoinExange
{
	private:
	
		std::map<std::string, double> _datab;
		
	public:
	
		BitcoinExange();
		~BitcoinExange();

		bool isValidDate(std::string date);
		void loadRates(const std::string &rates);
		
		const std::map<std::string, double>& getData() const {
        return _datab;}	// quitar
};

#endif