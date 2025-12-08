/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:35:33 by jose-gon          #+#    #+#             */
/*   Updated: 2025/12/08 20:20:25 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

void PmergeMe::sort(std::vector<int> &vec)
{
	PmergeMe::merge_container(vec, 1);
}

void PmergeMe::sort(std::deque<int> &de)
{
	PmergeMe::merge_container(de, 1);
}

