/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:23:13 by sofia             #+#    #+#             */
/*   Updated: 2024/06/25 15:13:04 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DatesAndPrices.hpp"

#define BITCOIN "static/bitcoin.csv"
#define ETHEREUM "static/ethereum.csv"
#define DOGE "static/doge.csv"

int main ( void )
{
    try 
    {
        std::cout << SBOLD(SITAL(BCYN("\t\t Bitcoin exchange fees: " ))) << std::endl << std::endl;
        DatesAndPrices bitcoin(BITCOIN);
        bitcoin.printFees("static/input.csv");
        
        std::cout << std::endl << std::endl;
        std::cout << SBOLD(SITAL(BMAG("\t\t Ethereum exchange fees: "))) << std::endl << std::endl;
        DatesAndPrices ether(ETHEREUM);
        ether.printFees("static/input.csv");

        std::cout << std::endl << std::endl;
        std::cout << SBOLD(SITAL(BYLW("\t\t Doge coin exchange fees: "))) << std::endl << std::endl;
        DatesAndPrices doge(DOGE);
        doge.printFees("static/input.csv");
    } 
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}