/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DatesAndPrices.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:34:27 by sofia             #+#    #+#             */
/*   Updated: 2024/06/10 15:37:10 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include "Date.hpp"
#include "Ansi.hpp"

class DatesAndPrices {

  private:
    DatesAndPrices(DatesAndPrices const &src);
    DatesAndPrices &operator=(DatesAndPrices const &rhs);
    void parsePrice(std::string &num) const;
    void parseDate(std::string &date) const;
    std::string findFirstDate(std::string db);
    std::map<std::string, double> loadDB(std::string filename);
   
    const Date _initial;
    const std::map<std::string, double> datesAndPrices;

  public:
    DatesAndPrices(std::string database);
    ~DatesAndPrices();

    double priceForDate(std::string date);
    void printFees(std::string filename);

    class notANumber : public std::exception
    {
      public:
        virtual const char *what() const throw()
        {
          return "Not a number.";
        }
    };

    class negativeNumber : public std::exception
    {
      public:
        virtual const char *what() const throw()
        {
          return "Not a positive number.";
        }
    };

    class tooLargeNumber : public std::exception
    {
      public:
        virtual const char *what() const throw()
        {
          return "Number is too large.";
        }
    };
};
