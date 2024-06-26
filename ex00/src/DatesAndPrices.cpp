/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DatesAndPrices.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:23:08 by sofia             #+#    #+#             */
/*   Updated: 2024/06/10 16:50:54 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DatesAndPrices.hpp"

void DatesAndPrices::printFees(std::string filename)
{
  std::ifstream file(filename);

  // Check if file is open
  if (!file.is_open())
  {
    throw std::runtime_error("Could not open file");
  }

  // Skip header
  std::string header;
  std::getline(file, header);

  // Read file line by line
  std::string line;
  while (std::getline(file, line))
  {
    try
    {
      std::istringstream iss(line);
      std::string newDate;
      std::string newNumStr;
      double newNum;
      double price_for_date;

      getline(iss, newDate, '|');
      parseDate(newDate);
      getline(iss, newNumStr);
      parsePrice(newNumStr);
      std::stringstream ss(newNumStr);
      ss >> newNum;

      price_for_date = priceForDate(newDate);
      std::cout << "\t" << SITAL(FGRN(newDate)) << FGRN("\t=>\t") << FGRN(newNum) << FGRN("\t=\t") << SBOLD(SUNDL(FGRN(price_for_date * newNum))) << std::endl;
    }
    catch (std::exception &e)
    {
      std::cerr << SBOLD(BRED(FWHI(" Error: "))) << " " << FRED(e.what()) << std::endl;
    }
  }
}


double DatesAndPrices::priceForDate(std::string date) {
  std::map<std::string, double>::const_iterator it = datesAndPrices.find(date);

  if (it == datesAndPrices.end())
  {
    it = datesAndPrices.upper_bound(date);
    it--;
  }
  return it->second;
}

std::string DatesAndPrices::findFirstDate(std::string db)
{
  Date result;

  std::ifstream file(db);
  if (!file.is_open())
    throw std::runtime_error("Could not open file");
  std::string header;
  std::getline(file, header);

  std::string line;
  while (getline(file, line))
  {
    std::istringstream ss(line);
    std::string date;
    if (!getline(ss, date, ','))
      throw std::runtime_error("Could not parse line");
    Date curr(date);
    if (result > curr)
      result = curr; 
  }
  file.close();
  return result.getDate();
}


std::map<std::string, double> DatesAndPrices::loadDB(std::string filename)
{
  std::map<std::string, double> dataset;
  
  std::ifstream file(filename);
  if (!file.is_open())
    throw std::runtime_error("Could not open file");

  std::string header;
  std::getline(file, header);

  std::string line;
  while (std::getline(file, line))
  {
    std::istringstream iss(line);

    std::string date;
    double value;
    if (!(getline(iss, date, ',') && (iss >> value)))
      throw std::runtime_error("Could not parse line 1");
    dataset[date] = value;
  }
  file.close();
  return dataset;
}

void DatesAndPrices::parsePrice(std::string &num) const
{
  num = Date::trimString(num);
  for (unsigned int i = 0; i < num.length() - 1; i++)
  {
    if (num[0] != '-' && num[i] != '.' && !std::isdigit(num[i]))
      throw DatesAndPrices::notANumber();
  }

  double number;
  std::stringstream ss(num);
  ss >> number;
  if (!number || number <= 0)
    throw DatesAndPrices::negativeNumber();
  else if (number >= 1000)
    throw DatesAndPrices::tooLargeNumber();
}

void DatesAndPrices::parseDate(std::string &dateStr) const {

  Date date(dateStr);
  // Check date is between the beginning of the DB and today
  if (!date.isInRange(_initial, Date(Date::getToday())))
    throw Date::dateException(date);
}


