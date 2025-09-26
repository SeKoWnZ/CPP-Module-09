/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExange.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:06:28 by jose-gon          #+#    #+#             */
/*   Updated: 2025/09/26 19:33:33 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExange.hpp>

BitcoinExange::BitcoinExange()
{};

BitcoinExange::~BitcoinExange()
{};

bool BitcoinExange::isValidDate(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || month > 12)
		return false;
		
	int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		daysInMonth[2] = 29;
	
	if (day < 1 || day > daysInMonth[month])
		return false;
	return true;
}

void BitcoinExange::loadRates(const std::string &rates)
{
	std::ifstream filerates(rates.c_str());
	if (!filerates)
		throw std::runtime_error("Can open rates data");
	
	std::string line;
	std::getline(filerates, line);
	while (std::getline(filerates, line)) {
		if (line.empty())
			continue;
	
		size_t commaPos = line.find(",");
		if (commaPos == std::string::npos)
			continue;
			
		std::string date = line.substr(0, commaPos);
		if (!this->isValidDate(date))
			continue;
			
		std::string rateValue = line.substr(commaPos + 1);
		
		std::istringstream strValue(rateValue);
		double dValue;
		if (!(strValue >> dValue)) {
			std::cerr << "Error in line: " << line << std::endl;
			continue;
		}
		this->_datab[date] = dValue;
	}
	filerates.close();
}
