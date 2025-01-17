/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:58:44 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/16 12:01:15 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		palette_2(int index, t_env *e)
{
	(void)e;
	if (index < 5)
		return (0x00b3bbd8);
	else if (index < 10)
		return (0x00b9c8ff);
	else if (index < 20)
		return (0x00708fff);
	else if (index < 30)
		return (0x003159e7);
	else if (index < 40)
		return (0x000e32b4);
	else if (index < 50)
		return (0x000b2583);
	else if (index < 60)
		return (0x006185a);
	else if (index < 100)
		return (0x00010c36);
	else
		return (0x00180129);
}

int		palette_4(int index, t_env *e)
{
	(void)e;
	if (index % 12 == 1)
		return (0x00FFFF66);
	else if (index % 12 == 2)
		return (0x00ff6754);
	else if (index % 12 == 3)
		return (0x00FF6600);
	else if (index % 12 == 4)
		return (0x0000FF00);
	else if (index % 12 == 5)
		return (0x000099FF);
	else if (index % 12 == 6)
		return (0x00f8a72b);
	else if (index % 12 == 7)
		return (0x000044fa);
	else if (index % 12 == 8)
		return (0x00fa48f0);
	else if (index % 12 == 9)
		return (0x00c12d78);
	else if (index % 12 == 10)
		return (0x0078ff00);
	else if (index % 12 == 11)
		return (0x00aa77ff);
	else
		return (0x00ff88cc);
}

int		palette_3(int index, t_env *e)
{
	if (index == e->nb_it)
		return (0);
	srand(0);
	return (rand() + palette_4(index, e));
}

int		palette_1(int index, t_env *e)
{
	(void)e;
	if (index == e->nb_it)
		return (0);
	return (index * 777777 / 1000);
}

int		newton_palette(int ret, t_env *e)
{
	(void)e;
	if (ret == 1)
		return (0x00ff0000);
	if (ret == 2)
		return (0x0000ff00);
	if (ret == 3)
		return (0x000000ff);
	else
		return (0);
}
