/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.Print.tpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:59:33 by sofia             #+#    #+#             */
/*   Updated: 2024/06/15 17:43:48 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <class T, class U>    
void FJA<T, U>::printBefore() const
{
  std::cout << "\t" << BBLU("Before :") << " ";
  int i = 0;
  for (typename T::const_iterator it = getSequence().begin(); it != getSequence().end() && i < 10; it++)
  {
    std::cout << SITAL(FBLU(*it)) << " ";
    i++;
    if (i == 10)
      std::cout << SITAL(FBLU("... (Only first 10 elements are shown 🙈)"));
  }
  std::cout << std::endl;
}

template <class T, class U>
void FJA<T, U>::printAfter()
{
  std::cout << "\t" <<BBLU("After Sorting 🎩✨:") << " ";
  int i = 0;
  for (typename T::const_iterator it = getSortedTerms().begin(); it != getSortedTerms().end() && i < 10; it++)
  {
    std::cout << SITAL(FBLU(*it)) << " ";
    i++;
    if (i == 10)
      std::cout << SITAL(FBLU("..."));
  }

  std::cout << std::endl;
}
