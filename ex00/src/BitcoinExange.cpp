/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExange.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:06:28 by jose-gon          #+#    #+#             */
/*   Updated: 2025/10/14 20:13:33 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExange.hpp>

BitcoinExange::BitcoinExange()
{};

BitcoinExange::~BitcoinExange()
{};

bool isNumeric(std::string num)
{
	size_t dot = 0;
	if (num[0] == '-')
		throw std::runtime_error("Error: not a positive number.");
	for (size_t i = 0; i < num.size(); i++)
	{
		if (num[i] == '.')
		{
			++dot;
			if (dot > 1)
				return false;
		}
		else if (!std::isdigit(static_cast<unsigned char>(num[i])))
			return false;
	}
	return true;
}

double BitcoinExange::isValidValue(std::string val)
{
	if (!isNumeric(val))
		throw std::runtime_error("Error: bad input => " + val);
	double dVal;
	std::istringstream strVal(val);
	if (!(strVal >> dVal))
		throw std::runtime_error("Error: bad input => " + val);
	if (dVal < 0)
		throw std::runtime_error("Error: not a positive number.");
	return dVal;
}

double BitcoinExange::isValidValueLimit(std::string val, int n)
{
	if (!isNumeric(val))
		throw std::runtime_error("Error: bad input => " + val);
	double dVal;
	std::istringstream strVal(val);
	if (!(strVal >> dVal))
		throw std::runtime_error("Error: bad input => " + val);
	if (dVal < 0)
		throw std::runtime_error("Error: not a positive number.");
	if (dVal > n)
		throw std::runtime_error("Error: too large a number.");
	return dVal;
}

int BitcoinExange::isValidDate(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw std::runtime_error("Error: bad input => " + date);
		
	std::string sYear = date.substr(0, 4);
	std::string sMonth = date.substr(5, 2);
	std::string sDay = date.substr(8, 2);

	if (!isNumeric(sYear))
		throw std::runtime_error("Error: bad input => " + date);
	if (!isNumeric(sMonth))
		throw std::runtime_error("Error: bad input => " + date);
	if (!isNumeric(sDay))
		throw std::runtime_error("Error: bad input => " + date);
		
	int year = std::atoi(sYear.c_str());
	int month = std::atoi(sMonth.c_str());
	int day = std::atoi(sDay.c_str());

	if (year < 1 || month < 1 || month > 12)
		throw std::runtime_error("Error: bad input => " + date);

	int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		daysInMonth[2] = 29;
	
	if (day < 1 || day > daysInMonth[month])
		throw std::runtime_error("Error: bad input => " + date);
		
	return year * 10000 + month * 100 + day;
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
		std::string rateValue = line.substr(commaPos + 1);
		int iDate;
		double dValue;
		try
		{
			iDate = isValidDate(date);
			dValue = isValidValue(rateValue);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			continue;
		}			
		_datab[iDate] = dValue;
	}
	filerates.close();
}

void BitcoinExange::makeExange(std::map<int, double>::iterator it, double val)
{
	int year = it->first / 10000;
	int month = (it->first / 100) % 100;
	int day = it->first % 100;

	std::cout << std::setfill('0')
	<< std::setw(4) << year << "-"
	<< std::setw(2) << month << "-"
	<< std::setw(2) << day
	<< " => " << val << " = " << val * it->second << std::endl;
}

void BitcoinExange::exangeValues(const std::string &file)
{
	std::ifstream fileval(file.c_str());
	if (!fileval)
		throw std::runtime_error("Cant open values data");
		
	std::string line;
	std::getline(fileval, line);
	while (std::getline(fileval, line))
	{
		if (line.empty())
			continue;
		
		size_t pipePos = line.find("|");
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " + line<< std::endl;
			continue;
		}
		std::string date = line.substr(0, pipePos - 1);
		std::string val = line.substr(pipePos + 2);
		int iDate;
		double dVal;
		try
		{
			iDate = isValidDate(date);
			dVal = isValidValueLimit(val, 1000);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			continue;
		}
		
		std::map<int, double>::iterator it = _datab.begin();
		
		while (it != _datab.end() && it->first < iDate)
			it++;
			
		if (it != _datab.end() && it->first == iDate)
			makeExange(it, dVal);
		else if (it == _datab.begin()) 
			std::cerr << "No hay una fecha anterior a " << date << std::endl;
		else if (it == _datab.end())
		{
		--it;
		makeExange(it, dVal);
		}
		else
		{
			--it;
			makeExange(it, dVal);
		}
	}
}
