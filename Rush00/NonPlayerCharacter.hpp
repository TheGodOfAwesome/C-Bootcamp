/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NonPlayerCharacter.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 07:59:40 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/09 07:59:42 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NONPLAYERCHARACTER_HPP
	#define NONPLAYERCHARACTER_HPP

#include "ft_retro.hpp"

class NonPlayerCharacter : public Characters
{

	private:
		bool		_alive;
		int 		_positionY;
		int 		_positionX;
		int			_maxY;
		int			_maxX;
		char		_shape;

	public : 
		NonPlayerCharacter(void);
		NonPlayerCharacter(int posY, int posX, int maxX, int maxY, char shape);
		NonPlayerCharacter(NonPlayerCharacter const & src);	
		~NonPlayerCharacter(void);

        void moveNonPlayerCharacter(void);
        void clearNonPlayerCharacter(void) const;

		NonPlayerCharacter	& operator=(NonPlayerCharacter const & rhs);
};

#endif