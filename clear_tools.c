/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:13:14 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/19 23:13:58 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	clear_mlx(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_display(e->mlx);
	free(e->mlx);
	return (1);
}

void	reset_image(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, 600, 400);
	e->img_address = mlx_get_data_addr(e->img, &e->bpp, &e->sline, &e->endian);
}

void	putpixel(int x, int y, t_env *e, int i)
{
	int	*iimg_addr;

	(void)i;
	if (x + y * 400 > 600 * 400 || x > 599 || y > 399 || x < 0 || y < 0)
		return ;
	iimg_addr = (int *)e->img_address;
	iimg_addr[x + y * 600] = e->palette(i, e);
	e->img_address = (char *)iimg_addr;
}
