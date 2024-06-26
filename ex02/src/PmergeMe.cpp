/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:04:33 by sofia             #+#    #+#             */
/*   Updated: 2024/06/15 17:49:35 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "PmergeMe.hpp"

void PmergeMeVector::printTime() const
{
  std::cout << FGRN("\tTime to process a range of ") << SBOLD(FGRN(getSequence().size())) << FGRN(" elements with ") << SBOLD(FGRN("std::vector: ")) << SUNDL(FGRN(time)) << SUNDL(FGRN(" ms")) << " ✅" << std::endl;
}

void PmergeMeDeque::printTime() const
{
  std::cout << FGRN("\tTime to process a range of ") << SBOLD(FGRN(getSequence().size())) <<  FGRN(" elements with ") << SBOLD(FGRN("std::deque: "))<< SUNDL(FGRN(time)) << SUNDL(FGRN(" ms")) << " ✅" << std::endl;
}

void PmergeMeList::printTime() const
{
  std::cout << FGRN("\tTime to process a range of ") << SBOLD(FGRN(getSequence().size())) <<  FGRN(" elements with ") << SBOLD(FGRN("std::list: "))<< SUNDL(FGRN(time)) << SUNDL(FGRN(" ms")) << " ✅" << std::endl;
}