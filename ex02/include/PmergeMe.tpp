/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:41:38 by sofia             #+#    #+#             */
/*   Updated: 2024/06/15 17:59:19 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T, class U>
void FJA<T, U>::MergeInsertionSort()
{
  // Start the clock
  clock_t start = clock();
  if ( getSequence().size() == 1 )
    getSortedTerms() = getSequence();
  else 
  {
    _makeSortedPairs(); // STEP 1
    _setHalfSortSequence(); // STEP 3
    _insertionSort(); // STEP 4
  }
  // Compute time
  time = (double)(clock() - start) / CLOCKS_PER_SEC * 1000;
}


/* STEP 1: Make pairs and sort in ascending order inside each pair */

template <class T, class U>
void FJA<T, U>::_makeSortedPairs()
{
  typename T::const_iterator it = getSequence().begin();
  while ( it  != getSequence().end())
  {
    int first = *it;
    it++;
    if (it != getSequence().end())
    {
      int second = *it++;

      if (first < second)
        std::swap(first, second);

      getPairs().push_back(std::make_pair(first, second));
    }
  }
}

/* STEP 2: Merge Sort the pairs according to the first (biggest) value */

template <class T, class U>
void FJA<T, U>::merge(typename U::iterator begin, typename U::iterator mid, typename U::iterator end)
{
    // 2 sub containers using range constructors
    U first_half(begin, mid);
    U second_half(mid, end);

    // iterators for the 2 sub containers and the merged sorted container
    typename U::iterator first_it =first_half.begin();
    typename U::iterator second_it = second_half.begin();
    typename U::iterator it = begin;

    while (first_it != first_half.end() && second_it != second_half.end())
    {
      if (first_it->first <= second_it->first)
        *it = *first_it++;
      else
        *it = *second_it++;
      it++;
    }
    while (first_it != first_half.end()) 
        *it++ = *first_it++;
    while (second_it != second_half.end())
        *it++ = *second_it++;
}

template <class T, class U>
void FJA<T, U>::mergeSort(typename U::iterator begin, typename U::iterator end)
{
  if (std::distance(begin, end) > 1)
  {
    typename U::iterator mid = begin;
    std::advance(mid, std::distance(begin, end) / 2);
    FJA<T, U>::mergeSort(begin, mid);
    FJA<T, U>::mergeSort(mid, end);
    FJA<T, U>::merge(begin, mid, end);  
  }
}

// STEP 3: Set the sorted sequence

template <class T, class U>
void FJA<T, U>::_setHalfSortSequence() 
{

  FJA<T, U>::mergeSort(getPairs().begin(), getPairs().end());

  typename U::const_iterator it = getPairs().begin();
  getSortedTerms().push_back(it->second);

  for (; it != getPairs().end(); it++)
  {
    getSortedTerms().push_back(it->first);
    getUnresolved().push_back(it->second);
  }
}

/* STEP 4: Insertion sort with comparison optimization using Jacobsthal sequence */

template <class T, class U>
void FJA<T, U>::_insertionSort()
{
  typename T::iterator toInsert;
  size_t insertCount = 0;
  typename T::iterator realIndex;
  typename T::iterator lastPos;
  
  getInsertPositions() = insertSequence(getUnresolved().size());

  for ( typename T::iterator it = getInsertPositions().begin(); it != getInsertPositions().end(); it++ )
  {
    toInsert = getUnresolved().begin();
    std::advance(toInsert, *it - 1);
    lastPos = getSortedTerms().begin();
    std::advance(lastPos, *it + insertCount);
    insertCount++;
    realIndex = FJA<T,U>::binarySearch(*toInsert, getSortedTerms().begin(), lastPos);
    getSortedTerms().insert(realIndex, *toInsert);
  }
  if (getSequence().size() % 2 != 0)
  {
    int val =  getSequence().back();
    realIndex = FJA<T,U>::binarySearch(val, getSortedTerms().begin(), getSortedTerms().end());
    getSortedTerms().insert(realIndex, val);
  }
}

template <class T, class U>
typename T::iterator FJA<T, U>::binarySearch(int value, typename T::iterator left, typename T::iterator right)
{
  typename T::iterator mid;
  while (std::distance(left, right) > 1)
  {
    mid = left;
    std::advance(mid, std::distance(left, right) / 2);
    if (value >*mid)
      left = mid;
    else
      right = mid;
  }
  if (value > *left)
    return std::next(left);
  return left;
}

template <class T, class U>
T  FJA<T, U>::insertSequence(size_t n)
{
  int index = 3;
  T jacobSequence;
  T insertSeq;

  if (n == 0) return insertSeq;

  // Generate the Jacobsthal sequence
  size_t value = FJA<T,U>::jacobsthal(index);
  while (value < n - 1) {
    jacobSequence.push_back(value);
    value = FJA<T,U>::jacobsthal(++index);
  }
  
  // Generate the optimal insert positions by adding a jacobshtal value and the values between the previous and the current value in descending order.
  size_t prevJacobVal = 1;
  for (typename T::const_iterator jacobVal = jacobSequence.begin(); jacobVal != jacobSequence.end(); jacobVal++) {
    prevJacobVal = *jacobVal;
    insertSeq.push_back(*jacobVal);
    for (size_t i = *jacobVal; i > prevJacobVal + 1; i--)
      insertSeq.push_back(i);   
  }

  while (prevJacobVal++ < n) {
      insertSeq.push_back(prevJacobVal);
  }
  return insertSeq;
}

template <class T, class U>
int FJA<T, U>::jacobsthal(int n)
{
  if (n == 0) return 0;
  if (n == 1) return 1;
  return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}