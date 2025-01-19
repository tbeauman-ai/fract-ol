/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:58:44 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/19 23:07:04 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	interpolate_color(int color1, int color2, double t)
{
	int	r;
	int	g;
	int	b;

	r = ((color1 >> 16) & 0xFF) * (1 - t) + ((color2 >> 16) & 0xFF) * t;
	g = ((color1 >> 8) & 0xFF) * (1 - t) + ((color2 >> 8) & 0xFF) * t;
	b = (color1 & 0xFF) * (1 - t) + (color2 & 0xFF) * t;
	return ((r << 16) | (g << 8) | b);
}

int	palette_2(int index, t_env *e)
{
	(void)e;
	if (index < 100)
		return (interpolate_color(0x00ffe5e5, 0x00330000, (index / 100.0)));
	else
		return (0x00330000);
}

int	palette_4(int index, t_env *e)
{
	const int	colors[12] = {0x00ffff66, 0x00ff6754, 0x00ff6600, 0x0000ff00,
		0x000099ff, 0x00f8a72b, 0x000044fa, 0x00fa48f0, 0x00c12d78,
		0x0078ff00, 0x00aa77ff, 0x00ff88cc};
	double		t;
	int			color1;
	int			color2;

	(void)e;
	t = (index % 25) / 25.0;
	color1 = colors[(index / 100) * 12];
	color2 = colors[((index / 100) + 1) * 12];
	return (interpolate_color(color1, color2, t));
}

int	palette_3(int index, t_env *e)
{
	const int	colors[12] = {0x00ffff66, 0x00ff6754, 0x00ff6600, 0x0000ff00,
		0x000099ff, 0x00f8a72b, 0x000044fa, 0x00fa48f0, 0x00c12d78,
		0x0078ff00, 0x00aa77ff, 0x00ff88cc};

	(void)e;
	return (colors[index % 12]);
}

int	palette_1(int index, t_env *e)
{
	(void)e;
	if (index == e->nb_it)
		return (0);
	return (index * 777777 / 1000);
}
