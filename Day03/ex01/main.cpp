/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:21:34 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/08 16:54:40 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main( void ) {

	std::string	command;
	std::string test = "sasuke";
	ScavTrap ninshu;
	ScavTrap ninpo;
	ScavTrap nin(test);
	ScavTrap const konagakure( ninpo );
	
	while(1)
	{
		std::cin >> command;
		if (command.find("Exit") != std::string::npos)
		{
			std::cout << "Exiting...\n";
			return 0;
		}
		if (command.find("reset") != std::string::npos)
		{
			ninshu = ninpo;
			std::cout << ninshu.getHp() << std::endl;	
		}
		if (command.find("R") != std::string::npos)
			ninshu.rangedAttack(test);
		if (command.find("M") != std::string::npos)
			ninshu.meleeAttack(test);	
		if (command.find("Heal") != std::string::npos)
			ninshu.beRepaired(10);	
		if (command.find("V") != std::string::npos)
			ninshu.challengeNewcomer(test);
	}
	return 0;
}
