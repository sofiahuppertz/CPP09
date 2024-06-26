/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.LifeCycle.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:20:04 by sofia             #+#    #+#             */
/*   Updated: 2024/06/15 17:56:57 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* Vector lifecycle */

PmergeMeVector::PmergeMeVector(char *argv[]): FJA<std::vector <int>, std::vector<std::pair< int, int > > >( argv ) {}

PmergeMeVector::~PmergeMeVector(){}

PmergeMeVector::PmergeMeVector( PmergeMeVector const &other ) {
  (void)other;
}

PmergeMeVector &PmergeMeVector::operator=( PmergeMeVector const &other) {
  (void)other;
  return *this;
}

/* Deque lifecycle */


PmergeMeDeque::PmergeMeDeque(char *argv[]): FJA<std::deque <int> , std::deque<std::pair <int, int> > >( argv ) {}

PmergeMeDeque::~PmergeMeDeque(){}

PmergeMeDeque::PmergeMeDeque( PmergeMeDeque const &other ) {
  (void)other;
}

PmergeMeDeque &PmergeMeDeque::operator=( PmergeMeDeque const &other) {
  (void)other;
  return *this;
}

/* List lifecycle */

PmergeMeList::PmergeMeList(char *argv[]): FJA<std::list <int> , std::list<std::pair <int, int> > >( argv ) {}

PmergeMeList::~PmergeMeList(){}

PmergeMeList::PmergeMeList( PmergeMeList const &other ) {
  (void)other;
}

PmergeMeList &PmergeMeList::operator=( PmergeMeList const &other) {
  (void)other;
  return *this;
}

