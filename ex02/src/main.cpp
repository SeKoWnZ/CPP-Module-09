/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:42:25 by jose-gon          #+#    #+#             */
/*   Updated: 2025/12/11 13:53:01 by jose-gon         ###   ########.fr       */
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

void args_to_vect(std::vector<int> &vec, char **argv)
{
	for (; *argv != NULL; argv++)
		vec.push_back(atoi(*argv));
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
	std::vector<int> vec;
	args_to_vect(vec, argv);
	me.sort(vec);
	print_container(vec);
	
	return 0;
}