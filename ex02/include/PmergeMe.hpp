/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:34:36 by jose-gon          #+#    #+#             */
/*   Updated: 2025/12/08 20:43:28 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define	PMERGEME_HPP

#include <vector>
#include <deque>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>

class PmergeMe
{
	private:

	template <typename T> void merge_container(T& container, int pair);
	template <typename T> void swap_pair(T it, int pair);
		
	public:
		PmergeMe();
		~PmergeMe();
		
		void sort(std::vector<int> &vec);
		void sort(std::deque<int> &de);
};

template <typename T> T next(T it, int step)
{
	std::advance(it, step);
	return it;
}

template <typename T> bool compare_pair(T first, T second)
{
	return first < second;
}

template <typename T> void PmergeMe::swap_pair(T start, int pair)
{
	for (T end = next(start,pair); start != end; start++)
		std::iter_swap(start, next(start, pair));
}

template <typename T> void PmergeMe::merge_container(T& container, int pair)
{
	typedef typename T::iterator iter;

	int nbr_pairs = container.size() / pair;
	if (nbr_pairs < 2)
		return;

	bool not_paired = nbr_pairs % 2 == 1;
	
	iter start = container.begin();
	iter last_pair = next(start, nbr_pairs * pair);
	iter end = next(last_pair, -(not_paired * pair));

	int advance = 2 * pair;
	
	for (iter it = start; it != end; std::advance(it, advance))
	{
		iter first = next(it, pair - 1);
		iter second = next(it, pair * 2 - 1);
		if (!compare_pair(first, second))
		{
			swap_pair(it, pair);
		}
	}
	merge_container(container, pair * 2);
}

#endif
