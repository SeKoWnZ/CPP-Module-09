/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:42:50 by jose-gon          #+#    #+#             */
/*   Updated: 2025/10/21 17:56:49 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "YOU HAVE TO WRITE AN EXPRESSION IN REVERSE POLISH NOTATION ALONG WITH THE PROGRAM" << std::endl;
		return 1;
	}
	
	std::string expression = argv[1];
	RPN rpn;

	try
	{
		rpn.calculate(expression);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}