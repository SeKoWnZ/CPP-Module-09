/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:29:48 by jose-gon          #+#    #+#             */
/*   Updated: 2025/10/22 10:24:38 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

RPN::RPN(){
	
}

RPN::~RPN(){
	
}

void RPN::calculate(const std::string &expression)
{
	std::stack<int> stack;
	std::istringstream exp(expression);
	std::string token;
	
	while (exp >> token)
	{
		if (token[1])
			throw std::runtime_error("Error: wrong format.");
		else if (isdigit(token[0]))
			stack.push(std::atoi(token.c_str()));
		else
		{
			if (stack.size() != 2)
				throw std::runtime_error("Error: wrong number of operands.");

			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			
			switch (token[0])
			{
				case '+':
					stack.push(a + b);
					break;
				case '-':
					stack.push(a - b);
					break;
				case '*':
					stack.push(a * b);
					break;
				case '/':
				{
					if (b == 0)
						throw std::runtime_error("Error: wrong number of operands.");
					stack.push(a / b);	
					break;
				}
				default:
					throw std::runtime_error("Error: invalid operator");
			}
		}
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error: wrong format.");
	std::cout << "RESULT >>> " << stack.top() << " <<<" << std::endl;
}