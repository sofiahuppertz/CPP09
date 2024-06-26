/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:42:42 by sofia             #+#    #+#             */
/*   Updated: 2024/06/24 10:19:45 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include "Ansi.hpp"


template <class T, class U>
class FJA
{
  private:
    FJA( FJA const &other );
    FJA &operator=( FJA const &other);

    static T const _setSequence( char *argv[] );
    static void mergeSort(typename U::iterator begin, typename U::iterator end);
    static void merge(typename U::iterator begin, typename U::iterator mid, typename U::iterator end);
    static T insertSequence(size_t n);
    static int jacobsthal(int n);
    static typename T::iterator binarySearch(int value, typename T::iterator left, typename T::iterator right);
    
    T const _sequence;
    U _pairs;
    T _unresolved;
    T _insertPositions;
    T _sortedTerms;
    
    void _makeSortedPairs();
    void _setHalfSortSequence();
    void _insertionSort();
    
  
  protected:
    T &getSortedTerms();
    T &getUnresolved();
    T &getInsertPositions();
    U &getPairs();
    T const &getSequence() const;

  public:
    FJA();
    FJA(char *argv[]);
    virtual ~FJA();
    double time;
        
    void MergeInsertionSort();
    void printBefore() const;
    void printAfter();
    virtual void printTime() const = 0;
    

    class InvalidInputException: public std::exception {
      public:
        virtual const char *what() const throw() {
          return "Invalid Input 💩";
        }
    };
};


class PmergeMeVector : public FJA< std::vector<int>, std::vector<std::pair<int, int> > > 
{
  private:
    PmergeMeVector( PmergeMeVector const &other );  
    PmergeMeVector &operator=( PmergeMeVector const &other);

  public:
    PmergeMeVector(char *argv[]);
    ~PmergeMeVector();
    void printTime() const;
};


class PmergeMeDeque : public FJA< std::deque<int>, std::deque<std::pair <int, int> > > 
{
  private:
    PmergeMeDeque( PmergeMeDeque const &other );  
    PmergeMeDeque &operator=( PmergeMeDeque const &other);

  public:
    PmergeMeDeque(char *argv[]);
    ~PmergeMeDeque();
    void printTime() const;
};

class PmergeMeList : public FJA< std::list<int>, std::list<std::pair <int, int> > > 
{
  private:
    PmergeMeList( PmergeMeList const &other );  
    PmergeMeList &operator=( PmergeMeList const &other);

  public:
    PmergeMeList(char *argv[]);
    ~PmergeMeList();
    void printTime() const;
};



#include "PmergeMe.LifeCycle.tpp"
#include "PmergeMe.Print.tpp"
#include "PmergeMe.Get.tpp"
#include "PmergeMe.tpp"