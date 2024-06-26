/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.LifeCycle.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:57:00 by sofia             #+#    #+#             */
/*   Updated: 2024/06/25 14:00:05 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date(std::string date) : _date(date) {
  _stringToDate();
}

Date::Date(): _date(Date::getToday()) {
  _stringToDate();
}

bool Date::operator>(Date const &other) const {
  return _dateToNum() > other._dateToNum();
}



Date &Date::operator=(Date const &other) {
  _date = other._date;
  _year = other._year;
  _month = other._month;
  _day = other._day;
  return *this;
}

Date::Date(Date const &src) : _date(src._date),
                              _year(src._year),
                              _month(src._month),
                              _day(src._day)
{}

Date::~Date() {}
