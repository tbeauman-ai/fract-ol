/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:04:17 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/19 23:13:51 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	module(t_complex z)
{
	return (sqrt(z.re * z.re + z.im * z.im));
}

t_complex	cpx_mult(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.re = a.re * b.re - a.im * b.im;
	ret.im = a.re * b.im + a.im * b.re;
	return (ret);
}

t_complex	cpx_pow(t_complex a, int n)
{
	t_complex	id;

	id.re = 1;
	id.im = 0;
	if (n == 0)
		return (id);
	return (cpx_mult(a, cpx_pow(a, n - 1)));
}

t_complex	cpx_div(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.re = 0;
	ret.im = 0;
	if (b.re == 0 && b.im == 0)
		return (ret);
	ret.re = (a.re * b.re + a.im * b.im) / (b.re * b.re + b.im * b.im);
	ret.im = (a.im * b.re - a.re * b.im) / (b.re * b.re + b.im * b.im);
	return (ret);
}

t_complex	cpx_inv(t_complex a)
{
	t_complex	one;

	one.re = 1;
	one.im = 0;
	return (cpx_div(one, a));
}
