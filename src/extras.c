/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extras.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 13:34:33 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/19 13:59:13 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

void		memdel_and_exit(t_map *params)
{
	mlx_destroy_window(params->mlx, params->window);
	ft_lstdel(&params->map_start, ft_freezero);
	free(params->rgb);
	ft_putstr("ESC: Ending program.\n");
	free(params);
	exit(0);
}
