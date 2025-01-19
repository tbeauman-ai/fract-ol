/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:13:14 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/19 12:13:50 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     clear_mlx(t_env *e)
{
    mlx_destroy_window(e->mlx, e->win);
    mlx_destroy_image(e->mlx, e->img);
    mlx_destroy_display(e->mlx);
    free(e->mlx);
    return (1);
}