/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.LifeCycle.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:29:07 by sofia             #+#    #+#             */
/*   Updated: 2024/06/25 16:31:26 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN ( RPN const &other ) {
  (void)other;
}

RPN &RPN::operator=( RPN const &other) {
  (void)other;
  return *this;
}

RPN::~RPN () {}