/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:10:20 by sofia             #+#    #+#             */
/*   Updated: 2024/06/15 17:54:25 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main (int argc, char *argv[])
{
  if (argc < 2)
    return 1; 
  argv++;
  
  try
  {
    FJA< std::vector<int>, std::vector<std::pair<int, int> > > *vector = new PmergeMeVector(argv);
    vector->MergeInsertionSort();

    FJA< std::deque<int>, std::deque<std::pair<int, int> > > *deque = new PmergeMeDeque(argv);
    deque->MergeInsertionSort();

    FJA < std::list<int>, std::list<std::pair<int, int> > > *list = new PmergeMeList(argv);
    list->MergeInsertionSort();
    
    vector->printBefore();
    vector->printAfter();
    vector->printTime();
    deque->printTime();
    list->printTime();

    delete vector;
    delete deque;
    delete list;
  } 
  catch (std::exception &e) 
  {
    std::cerr << BRED("\tException caught:") << " " << SITAL(FRED(e.what())) << std::endl;
  }
  return 0;
}