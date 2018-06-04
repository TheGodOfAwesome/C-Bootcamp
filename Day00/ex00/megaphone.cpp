/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:32:02 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/04 15:27:00 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char ** argv)
{
	char	c;
	int		i;
	int		j;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < argc)
	{
		j = 0; 
		while(argv[i][j])
		{
			if (argv[i][j] > 96 && argv[i][j] < 123)
				c = argv[i][j] - 32;
			else
				c = argv[i][j];
			std::cout << c;
			j++;
		}
		i++;
	}
	std::cout << '\n';
	return 0;
}
