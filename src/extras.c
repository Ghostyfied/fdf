/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extras.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 13:34:33 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/25 15:48:16 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

void			get_color_scheme(t_map *params, int i)
{
	t_rgb		*color;

	color = ft_memalloc(sizeof(t_rgb));
	color->rmax = ft_red(params->color2[i]);
	color->gmax = ft_green(params->color2[i]);
	color->bmax = ft_blue(params->color2[i]);
	color->rmin = ft_red(params->color1[i]);
	color->gmin = ft_green(params->color1[i]);
	color->bmin = ft_blue(params->color1[i]);
	params->rgb = color;
}

void			memdel_and_exit(t_map *params)
{
	mlx_destroy_window(params->mlx, params->window);
	ft_lstdel(&params->map_start, ft_freezero);
	free(params->rgb);
	ft_putstr("ESC: Ending program.\n");
	free(params);
	exit(0);
}
