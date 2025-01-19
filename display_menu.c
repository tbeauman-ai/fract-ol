/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:15:04 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/19 23:13:16 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_menu2(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 5, 160, 0x00ffffff, "-I pour Burning Julia");
	mlx_string_put(e->mlx, e->win, 5, 175, 0x00ffffff, "-T pour Tricorne");
	mlx_string_put(e->mlx, e->win, 5, 190, 0x00ffffff, "-N pour Newton");
	mlx_string_put(e->mlx, e->win, 5, 205, 0x00ff00ff, "Notes:");
	mlx_string_put(e->mlx, e->win, 5, 220, 0x00ffffff,
		"Vous pouvez fixer un ensemble de Julia en appuyant sur F");
	mlx_string_put(e->mlx, e->win, 5, 240, 0x00ffffff,
		"Pour toutes les fractales sauf celle de Newton, appuyez sur O/P");
	mlx_string_put(e->mlx, e->win, 5, 260, 0x00ffffff,
		"pour diminuer/augmenter l'exposant");
	mlx_string_put(e->mlx, e->win, 5, 280, 0x00ffffff,
		"+/- pour augmenter/diminuer le nombre d'iterations");
	mlx_string_put(e->mlx, e->win, 5, 320, 0x00ffffff,
		"Zoomez/Dezoomez avec le scroll de la souris");
	mlx_string_put(e->mlx, e->win, 5, 360, 0x00ffffff,
		"Pour revoir le menu des commandes:");
	mlx_string_put(e->mlx, e->win, 10, 380, 0x00ffffff,
		"-Appuyez sur la touche Enter");
}

void	display_menu(t_env *e)
{
	e->ens = 0;
	mlx_string_put(e->mlx, e->win, 50, 10, 0x00ba54fc,
		"Bienvenue dans mon explorateur de fractales");
	mlx_string_put(e->mlx, e->win, 5, 50, 0x00ffffff,
		"Pour changer la palette de couleur:");
	mlx_string_put(e->mlx, e->win, 5, 65, 0x00ffffff,
		"-Touches du pave numerique 1/2/3/4");
	mlx_string_put(e->mlx, e->win, 5, 100, 0x00ffffff,
		"Pour visionner un ensemble different:");
	mlx_string_put(e->mlx, e->win, 5, 115, 0x00ffffff, "-M pour Mandelbrot");
	mlx_string_put(e->mlx, e->win, 5, 130, 0x00ffffff,
		"-J pour Julia (dispose d'un motion hook)");
	mlx_string_put(e->mlx, e->win, 5, 145, 0x00ffffff, "-B pour Burning ship");
	display_menu2(e);
}
