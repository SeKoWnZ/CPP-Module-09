/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:34:36 by jose-gon          #+#    #+#             */
/*   Updated: 2026/04/19 23:48:03 by jose-gon         ###   ########.fr       */
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
#include <algorithm>
#include <ctime>
#include <iomanip>



////////// BORRAR ///////////
template <typename T> 
void print_container(const T& container)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
}

class PmergeMe
{
	private:

	template <typename T> void merge_container(T& container, int pair);
	template <typename T> void swap_pair(T it, int pair);
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		
		void sort(std::vector<int> &vec);
		void sort(std::deque<int> &de);

		static int nbr_comps;
};

long jacobsthal_nbr(long n);

template <typename T> T next(T it, int step)
{
	std::advance(it, step);
	return it;
}

template <typename T> bool compare_pair(T first, T second)
{
	PmergeMe::nbr_comps++;
	return *first < *second;
}

template <typename T> void PmergeMe::swap_pair(T start, int pair)
{
	for (T end = next(start,pair); start != end; start++)
		std::iter_swap(start, next(start, pair));
}

template <typename T> void PmergeMe::merge_container(T& container, int pair)
{
	typedef typename T::iterator Iter;

	int nbr_pairs = container.size() / pair;
	if (nbr_pairs < 2)
		return;

	bool not_paired = nbr_pairs % 2 == 1;
	
	Iter start = container.begin();
	Iter last_pair = next(start, nbr_pairs * pair);
	Iter end = next(last_pair, -(not_paired * pair));

	int advance = 2 * pair;
	
	for (Iter it = start; it != end; std::advance(it, advance))
	{
		Iter first = next(it, pair - 1);
		Iter second = next(it, pair * 2 - 1);
		if (!compare_pair(first, second))
		{
			swap_pair(it, pair);
		}
	}
	merge_container(container, pair * 2);

	std::vector<Iter> main;
	std::vector<Iter> pend;

	main.insert(main.end(), next(container.begin(), pair -1));
	main.insert(main.end(), next(container.begin(), pair * 2 -1));

	for (int i = 4; i <= nbr_pairs; i += 2)
	{
		pend.insert(pend.end(), next(container.begin(),pair * (i - 1) - 1));
		main.insert(main.end(), next(container.begin(), pair * i - 1));
	}
	
	if (not_paired)
		pend.insert(pend.end(), next(end, pair - 1));

	long prev_jacob = jacobsthal_nbr(1);
	long inserted_nbr = 0;
	
	for (int k = 2;; k++)
	{
		long curr_jacob = jacobsthal_nbr(k);
		long jacob_diff = curr_jacob - prev_jacob;
		int offset = 0;

		if (jacob_diff > static_cast<int>(pend.size()))
			break;
		
		int nbr_elements = jacob_diff;
		
		typename std::vector<Iter>::iterator pend_it = next(pend.begin(), jacob_diff - 1);
		typename std::vector<Iter>::iterator bound_it = next(main.begin(), curr_jacob + inserted_nbr);

		while (nbr_elements)
		{
			typename std::vector<Iter>::iterator idx = std::upper_bound(main.begin(), bound_it, *pend_it, compare_pair<Iter>);
			typename std::vector<Iter>::iterator inserted = main.insert(idx, *pend_it);
			nbr_elements--;
			pend_it = pend.erase(pend_it);
			std::advance(pend_it, -1);
			
			offset += (inserted - main.begin()) == curr_jacob + inserted_nbr;
			bound_it = next(main.begin(), curr_jacob + inserted_nbr - offset);
		}
		prev_jacob = curr_jacob;
		inserted_nbr += jacob_diff;
		offset = 0;
	}

	for (ssize_t i = pend.size() - 1; i >= 0; i--)
	{
		typename std::vector<Iter>::iterator curr_pend = next(pend.begin(), i);
		typename std::vector<Iter>::iterator curr_bound =
			next(main.begin(), main.size() - pend.size() + i + not_paired);
		typename std::vector<Iter>::iterator idx =
			std::upper_bound(main.begin(), curr_bound, *curr_pend, compare_pair<Iter>);
		main.insert(idx, *curr_pend);
	}

	std::vector<int> copy;
	copy.reserve(container.size());
	for (typename std::vector<Iter>::iterator it = main.begin(); it != main.end(); it++)
	{
		for (int i = 0; i < pair; i++)
		{
			Iter pair_start = *it;
			std::advance(pair_start, -pair + i + 1);
			copy.insert(copy.end(), *pair_start);
		}
	}

	Iter container_it = container.begin();
	std::vector<int>::iterator copy_it = copy.begin();
	while (copy_it != copy.end())
	{
		*container_it = *copy_it;
		container_it++;
		copy_it++;
	}
}

#endif
