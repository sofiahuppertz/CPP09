/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:02:11 by sofia             #+#    #+#             */
/*   Updated: 2024/06/25 16:31:52 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


double RPN::calc ( std::string expression ) {
  
  std::istringstream ss(expression);
  std::stack<double> nums;
  std::string elem;  

  while (ss >> elem) {
    if (isOperator(elem))
    {
      performOperation(elem, nums);
    }
    else if (isTerm(elem))
    {
      nums.push(std::atoi(elem.c_str()));
    }
    else
      throw RPN::execErrorException();

  }
  if (nums.size() != 1)
    throw RPN::execErrorException();
  return nums.top();
}

void RPN::performOperation ( std::string const &op, std::stack<double> &nums ) {
  
  double a, b;
  std::map <std::string, double(*)(double, double)> operations;
  operations["+"] = &RPN::add;
  operations["-"] = &RPN::sub;
  operations["*"] = &RPN::mlt;
  operations["/"] = &RPN::div;

  if (nums.size() < 2)
    throw RPN::execErrorException();
  b = nums.top();
  nums.pop();
  a = nums.top();
  nums.pop();

  if (operations.find(op) != operations.end())
    nums.push(operations[op](a, b));
}

double RPN::add ( double a, double b ) { return a + b; }
double RPN::sub ( double a, double b ) { return a - b; }
double RPN::mlt ( double a, double b ) { return a * b; }
double RPN::div ( double a, double b ) { return a / b; }

bool RPN::isOperator ( std::string const &op ) {

  char operators[4] = {'+', '-', '/', '*'};

  if (op.size() != 1)
    return false;
  char c = static_cast<char>(op[0]);
  for ( int i = 0; i < 4; i++)
  {
    if (c == operators[i])
      return true;
  }
  return false;
}

bool RPN::isTerm ( std::string const &op ) {

  if (op.size() != 1)
    return false;
  return std::isdigit(op[0]);
}




