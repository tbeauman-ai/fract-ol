/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurrences.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:26:41 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/19 22:43:56 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	mandelbrot_rec(t_complex z, t_complex c, t_env *e)
{
	t_complex	ret;
	t_complex	z_2;
	int			i;

	i = 1;
	z_2 = z;
	while (i++ < abs(e->puissance))
		z_2 = cpx_mult(z, z_2);
	if (e->puissance < 0)
		z_2 = cpx_inv(z_2);
	if (e->puissance == 0)
	{
		z_2.re = 1;
		z_2.im = 0;
	}
	ret.re = z_2.re + c.re;
	ret.im = z_2.im + c.im;
	return (ret);
}

t_complex	burning_ship_rec(t_complex z, t_complex c, t_env *e)
{
	t_complex	ret;
	t_complex	z_2;
	int			i;

	i = 1;
	z_2.re = fabs(z.re);
	z_2.im = fabs(z.im);
	while (i++ < abs(e->puissance))
	{
		z.re = fabs(z.re);
		z.im = fabs(z.im);
		z_2 = cpx_mult(z, z_2);
	}
	if (e->puissance < 0)
		z_2 = cpx_inv(z_2);
	if (e->puissance == 0)
	{
		z_2.re = 1;
		z_2.im = 0;
	}
	ret.re = z_2.re + c.re;
	ret.im = z_2.im + c.im;
	return (ret);
}

t_complex	tricorn_rec(t_complex z, t_complex c, t_env *e)
{
	t_complex	ret;
	t_complex	z_2;
	int			i;

	i = 1;
	z.im = -z.im;
	z_2 = z;
	while (i++ < abs(e->puissance))
	{
		z_2 = cpx_mult(z, z_2);
	}
	if (e->puissance < 0)
		z_2 = cpx_inv(z_2);
	if (e->puissance == 0)
	{
		z_2.re = 1;
		z_2.im = 0;
	}
	ret.re = z_2.re + c.re;
	ret.im = z_2.im + c.im;
	return (ret);
}
