/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.LifeCycle.tpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:31:35 by sofia             #+#    #+#             */
/*   Updated: 2024/06/15 16:59:37 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T, class U>
FJA<T, U>::FJA() {}

template <class T, class U>
FJA<T, U>::FJA(char *argv[]) : _sequence(_setSequence(argv)) {}

template <class T, class U>
FJA<T, U>::FJA( FJA const &other ) {
  *this = other;
}

template <class T, class U>
FJA<T, U> &FJA<T, U>::operator=( FJA<T, U> const &other){
  (void)other;
  return *this;
}

template <class T, class U>
FJA<T, U>::~FJA() {}


template <class T, class U>
T const FJA<T, U>::_setSequence(char *argv[])
{
  int num;
  char *ptr;
  T sequence;
  
  for (int i = 0; argv[i] != NULL; i++)
  { 
    if (argv[i][0] == '\0')
      throw FJA::InvalidInputException();
    
    num = std::strtol(argv[i], &ptr, 10);

    if (*ptr != '\0' || num < 0)
      throw FJA::InvalidInputException();
    sequence.push_back(num); 
  }
  return sequence;
}