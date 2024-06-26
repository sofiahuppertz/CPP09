/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:51:38 by sofia             #+#    #+#             */
/*   Updated: 2024/06/25 16:30:06 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <stack>


class RPN {

  private:
    
    static bool isOperator ( std::string const &op );
    static bool isTerm ( std::string const &op );
    static void performOperation ( std::string const &op , std::stack<double> &nums);

    static double add ( double a, double b );
    static double sub ( double a, double b );
    static double mlt ( double a, double b );
    static double div ( double a, double b );

  protected:
    RPN ( void );
    RPN ( RPN const &other );
    RPN &operator=( RPN const &other);

  public:
    ~RPN ();

    static double calc( std::string expr );

    class execErrorException: public std::exception {
      public:
        virtual const char *what() const throw() {
          return "Invalid expression";
        }
    };
};