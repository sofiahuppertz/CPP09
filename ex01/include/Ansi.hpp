/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ansi.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:14 by sofia             #+#    #+#             */
/*   Updated: 2024/06/10 16:51:28 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sstream>
#include <string>

// Foreground
#define REDD "\x1B[31m"
#define GREN "\x1B[32m"
#define YLLW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MGNT "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHIT "\x1B[37m"

// Background
#define B_RED "\x1B[41m"
#define B_GRN "\x1B[42m"
#define B_YLW "\x1B[43m"
#define B_BLU "\x1B[44m"
#define B_MAG "\x1B[45m"
#define B_CYN "\x1B[46m"
#define B_WHI "\x1B[47m"

// Style
#define RSET "\x1B[0m"
#define BOLD "\x1B[1m"
#define ITAL "\x1B[3m"
#define UNDL "\x1B[4m"

#define FRED(x) (std::string(REDD) + toString(x) + RSET)
#define FGRN(x) (std::string(GREN) + toString(x) + RSET)
#define FYLW(x) (std::string(YLLW) + toString(x) + RSET)
#define FBLU(x) (std::string(BLUE) + toString(x) + RSET)
#define FMAG(x) (std::string(MGNT) + toString(x) + RSET)
#define FCYN(x) (std::string(CYAN) + toString(x) + RSET)
#define FWHI(x) (std::string(WHIT) + toString(x) + RSET)

#define BRED(x) (std::string(B_RED) + toString(x) + RSET)
#define BGRN(x) (std::string(B_GRN) + toString(x) + RSET)
#define BYLW(x) (std::string(B_YLW) + toString(x) + RSET)
#define BBLU(x) (std::string(B_BLU) + toString(x) + RSET)
#define BMAG(x) (std::string(B_MAG) + toString(x) + RSET)
#define BCYN(x) (std::string(B_CYN) + toString(x) + RSET)
#define BWHI(x) (std::string(B_WHI) + toString(x) + RSET)

#define SBOLD(x) (std::string(BOLD) + toString(x) + RSET)
#define SITAL(x) (std::string(ITAL) + toString(x) + RSET)
#define SUNDL(x) (std::string(UNDL) + toString(x) + RSET)

template <typename T>
std::string toString(const T &value)
{
  std::stringstream ss;
  ss << value;
  return ss.str();
}
