/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:42:25 by jose-gon          #+#    #+#             */
/*   Updated: 2025/12/03 18:09:19 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

void check_args(int n, char** args)
{
	if (n == 1)
		throw std::runtime_error("Need a positive integer sequence as argument");
	if (all_positive_numbers(args))
		
}

int main(int argc, char **argv)
{
	check_args(argc, argv);
}