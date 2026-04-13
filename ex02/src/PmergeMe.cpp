/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:35:33 by jose-gon          #+#    #+#             */
/*   Updated: 2026/03/25 19:19:59 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

int PmergeMe::nbr_comps = 0;

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe(){}

void PmergeMe::sort(std::vector<int> &vec)
{
	PmergeMe::merge_container(vec, 1);
}

void PmergeMe::sort(std::deque<int> &de)
{
	PmergeMe::merge_container(de, 1);
}

long jacobsthal_nbr(long n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	
	long j0 = 0;
	long j1 = 1;
	long j;

	for (long i = 2; i <= n; i++)
	{
		j = j0 * 2 + j1;
		j0 = j1;
		j1 = j;
	}
	return j1;
}


