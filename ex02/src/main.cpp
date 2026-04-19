/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:42:25 by jose-gon          #+#    #+#             */
/*   Updated: 2026/04/19 23:46:32 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

void check_args(int n, char** args)
{
	if (n == 1)
		throw std::runtime_error("Need a positive integer sequence as argument");
	long number;	
	for (;*args != NULL; ++args)
	{
		std::istringstream arg(*args); 
		if (!(arg >> number) || !arg.eof() || number < 0 || number > __INT_MAX__)
			throw std::runtime_error("Only positive integer sequence is accepted as an argument");
	}
}

void args_to_str(std::string &str, char **argv)
{
	str += *argv;
	argv++;
	for (; *argv != NULL; argv++)
	{
		str += " ";
		str += *argv;
	}
}

void args_to_vect(std::vector<int> &vec, char **argv)
{
	for (; *argv != NULL; argv++)
		vec.push_back(atoi(*argv));
}

void args_to_deque(std::deque<int> &deq, char **argv)
{
	for (; *argv != NULL; argv++)
		deq.push_back(atoi(*argv));		
}

int main(int argc, char **argv)
{
	PmergeMe me;
	
	try
	{
		check_args(argc, argv + 1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	
	argv++;
	std::string str;
	std::vector<int> vec;
	std::deque<int> deq;
	
	args_to_str(str, argv);
	args_to_vect(vec, argv);
	args_to_deque(deq, argv);
	
	std::cout << "Before: " << str << std::endl;
	{
		clock_t start = clock();
		me.sort(vec);
		clock_t end = clock();
		double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

		std::cout << "After: ";
		print_container(vec);
		std::cout << std::endl;
		
		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(6) << elapsedTime << " us" << std::endl;
	}
	
	{
		clock_t start = clock();
		me.sort(deq);
		clock_t end = clock();
		double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << elapsedTime << " us" << std::endl;
	}
	
	//print_container(deq);
	//std::cout << "Number of Comparations: " << me.nbr_comps << std::endl;
	
	return 0;
}
