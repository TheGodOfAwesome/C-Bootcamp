/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arena.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:23:01 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/10 14:24:20 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_HPP
	#define ARENA_HPP

#include "ft_retro.hpp"

class Arena{

	private:

	protected:
		bool		_alive;
		int			_maxY;
		int			_maxX;
		char		_shape;

	public : 
		Arena(void);
		Arena(int maxX, int maxY);
		Arena(Arena const & src);	
		~Arena(void);

		
        virtual WINDOW	*create_newwin(int height, int width, int startY, int startX);
		virtual void	destroy_win(WINDOW *local_win);
		virtual void	create_arena(void) const;

		virtual int		getMaxY(void) const;
		virtual int		getMaxX(void) const;

		Arena	& operator=(Arena const & rhs);
};

#endif
