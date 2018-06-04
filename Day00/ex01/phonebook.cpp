/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:05:58 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/04 17:57:22 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string		command;

	while(1)
	{
		std::cout << "Please Enter A Phonebook Command\n>>";
		std::cin >> command;	
		if (command.find("Exit") != std::string::npos)
		{
			std::cout << "Exiting...\n";
			return 0;
		}
		if (command.find("Add") != std::string::npos)
			std::cout << "Adding...\n";
		if (command.find("Find") != std::string::npos)
			std::cout << "Find...\n";
	}
	return 0;
}
