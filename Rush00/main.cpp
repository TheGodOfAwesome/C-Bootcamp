/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 07:46:21 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/10 14:16:45 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

int main(void)
{
	Arena newArena;
	WINDOW	*my_win;
	int ch, maxY, maxX;
	
	//Initialise Arena
	newArena.create_arena();

	//Set Window Dimensions
	getmaxyx(stdscr, maxY, maxX);

	//Set Starting Point
	int startX = 0;
	int startY = 0;
	startX = 5;
	startY = startX;
	startY++;

	//Creating a center point.
	int centerX = (COLS) / 2;
	
	int randomNum1 = maxX / 9;
	int randomNum2 = maxX / 4;
	int randomNum3 = maxX / 6;
	int randomNum4 = maxX / 8;

	Bullet bullet(0, 0, maxY, maxX, '*');	
	
	Characters enemy(1, centerX, maxY, maxX, 'X');	
	Characters enemy1(1, randomNum1, maxY, maxX, 'X');
	Characters enemy2(1, randomNum2, maxY, maxX, 'X');
	Characters enemy3(1, randomNum3, maxY, maxX, 'X');
	Characters enemy4(1, randomNum4, maxY, maxX, 'X');
	
	Characters player(maxY - 2, centerX, maxY, maxX, '^');
	
	refresh();
	my_win = newArena.create_newwin(maxY, maxX, 0, 0);
	int timer = 0;
	int bulletTime = 0; 
	while(1)
	{
		if (timer == 60000)
		{
			int x = enemy.getPositionX();
			int y = enemy.getPositionY();
			if (y < enemy.getMaxY() - 2) 
			{
				enemy.moveCharacterDown();
				enemy1.moveCharacterDown();
				enemy2.moveCharacterDown();
				enemy3.moveCharacterDown();
				enemy4.moveCharacterDown();
			}
			else
			{
				mvaddch(y, x, ' ');
				enemy.setPosition(1, centerX);
				mvaddch(enemy1.getPositionY(), enemy1.getPositionX(), ' ');
				enemy1.setPosition(1, randomNum1);
				mvaddch(enemy2.getPositionY(), enemy2.getPositionX(), ' ');
				enemy2.setPosition(1, randomNum2);
				mvaddch(enemy3.getPositionY(), enemy3.getPositionX(), ' ');
				enemy3.setPosition(1, randomNum3);
				mvaddch(enemy4.getPositionY(), enemy4.getPositionX(), ' ');
				enemy4.setPosition(1, randomNum4);
			}
			timer = 0;
		}
		if (bulletTime == 10000)
		{
			bullet.moveBullet('u');
			bulletTime = 0;
		}
		timer++;
		bulletTime++;
		ch = getch();
		switch(ch)
		{
			case KEY_LEFT:
					player.moveCharacterLeft();
					break;
			case KEY_RIGHT:
					player.moveCharacterRight();
					break;
			case KEY_UP:	
					player.moveCharacterUp();
					break;
			case KEY_DOWN:
					player.moveCharacterDown();
					break;
			case 32: //Space Bar
					bullet.clearBullet();
					bullet.setPosition(player.getPositionY() - 1, player.getPositionX());
					break;
			case 27: //Esc
					endwin();
					return 0;
					break;
		}
		int x = bullet.getPositionX();
		int y = bullet.getPositionY();
		if((x == enemy.getPositionY()) && (y && enemy.getPositionX()))
			{
				enemy.setShape(' ');
			}
			if((x == enemy1.getPositionY()) && (y && enemy1.getPositionX()))
			{
				enemy1.setShape(' ');
			}
			if((x == enemy2.getPositionY()) && (y && enemy2.getPositionX()))
			{
				enemy2.setShape(' ');
			}
			if((x == enemy3.getPositionY()) && (y && enemy3.getPositionX()))
			{
				enemy3.setShape(' ');
			}
			if((x == enemy4.getPositionY()) && (y && enemy4.getPositionX()))
			{
				enemy4.setShape(' ');
			}
		int a = player.getPositionY();
		int b = player.getPositionX();	
		    if((a == enemy.getPositionY()) && (b && enemy.getPositionX()))
			{
				return 0;
			}
			if((a == enemy1.getPositionY()) && (b && enemy1.getPositionX()))
			{
				return 0;
			}
			if((a == enemy2.getPositionY()) && (b && enemy2.getPositionX()))
			{
				return 0;
			}
			if((a == enemy3.getPositionY()) && (b && enemy3.getPositionX()))
			{
				return 0;
			}
			if((a == enemy4.getPositionY()) && (b && enemy4.getPositionX()))
			{
				return 0;
			}
	}
	endwin();

	return(0);
}
