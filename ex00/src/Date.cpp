/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:23:00 by sofia             #+#    #+#             */
/*   Updated: 2024/06/25 14:42:53 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

std::string Date::trimString(const std::string &str)
{
  size_t first = str.find_first_not_of(' ');
  if (std::string::npos == first)
  {
    return str;
  }
  size_t last = str.find_last_not_of(' ');
  return str.substr(first, (last - first + 1));
}

std::string Date::getToday()
{
  std::time_t t = std::time(0);
  std::tm *now = std::localtime(&t);

  char buf[80];
  std::strftime(buf, sizeof(buf), "%Y-%m-%d", now);

  return std::string(buf);
}

void Date::_stringToDate()
{
  std::string date;
  date = trimString(_date);

  // Check date is in format YYYY-MM-DD
  if (date.size() != 10)
    throw dateException(*this);
  for (int i = 0; i < 10; i++)
  {
    if (((i == 4 || i == 7) && date[i] != '-') && !isdigit(date[i]))
      throw dateException(*this);
  }

  // Extract year, month and day
  _year = std::stoi(date.substr(0, 4));
  _month = std::stoi(date.substr(5, 2));
  _day = std::stoi(date.substr(8, 2));

  // Check date is possible
  if (!_isValidDate())
    throw dateException(*this);
}

bool Date::_isValidDate(void) const
{
  if (_year < 0 || _month < 1 || _month > 12 || _day < 1) {
    return false;
  }
  int maxDay;
  switch (_month) {
    case 2:
      maxDay = 28;
      if (_year % 4 == 0 && (_year % 100 != 0 || _year % 400 == 0))
        maxDay = 29;
      break;
    case 4: case 6: case 9: case 11: maxDay = 30; break;
    default: maxDay = 31; break;
  }
  return _day <= maxDay;
}

int Date::_dateToNum(void) const {
  return _year * 10000 + _month * 100 + _day;
}

bool Date::isInRange(Date const &start, const Date &end) const {
  if (!(*this > end) && !(start > *this))
    return true;
  return false;
}


std::string Date::getDate() const {
  return _date;
}

