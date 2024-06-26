/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.Get.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:49:16 by sofia             #+#    #+#             */
/*   Updated: 2024/06/15 17:12:47 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T, class U>
U &FJA<T, U>::getPairs() {
  return _pairs;
}
    
template <class T, class U> 
T const &FJA<T, U>::getSequence() const {
  return _sequence;
}

template <class T, class U>
T &FJA<T, U>::getSortedTerms() {
  return _sortedTerms;
}

template <class T, class U>
T &FJA<T, U>::getUnresolved() {
  return _unresolved;
}

template <class T, class U>
T &FJA<T, U>::getInsertPositions() {
  return _insertPositions;
}