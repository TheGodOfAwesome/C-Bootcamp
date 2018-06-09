/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Characters.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 07:57:19 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/09 13:06:12 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTERS_HPP
	#define CHARACTERS_HPP

#include <iostream>
#include <ncurses.h>

class Characters{

	private:
		bool		_alive;
		int 		_positionY;
		int 		_positionX;

	public : 
		Characters(void);
		Characters(int posY, int posX);
		Characters(Characters const & src);		
		~Characters(void);

		void	moveCharacter(int posY, int posX);

		void	setAliveStatus(bool alive);
		void	setPosition(int positionY, int positionX);
		
		bool	getAliveStatus(void) const;
		int		getPositionY(void) const;
		int		getPositionX(void) const;

		Characters	& operator=(Characters const & rhs);
};

#endif
