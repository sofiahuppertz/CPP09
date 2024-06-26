/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DatesAndPrices.LifeCycle.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:43:06 by sofia             #+#    #+#             */
/*   Updated: 2024/06/25 13:29:36 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DatesAndPrices.hpp"

DatesAndPrices::DatesAndPrices(std::string database) : _initial(findFirstDate(database)), datesAndPrices(loadDB(database)) 
{}


DatesAndPrices::DatesAndPrices(DatesAndPrices const &other) {
  *this = other;
}

DatesAndPrices::~DatesAndPrices(){}

DatesAndPrices &DatesAndPrices::operator=(DatesAndPrices const &other) {
  (void)other;
  return *this;
}