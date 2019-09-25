/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_coor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 19:26:42 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/25 19:29:00 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	getx(int x, int y, int z, t_map *params)
{
	int	g;

	g = params->grid_size;
	z *= params->grid_size * 10000 / 100000 * params->heigth;
	y = y * g;
	x = x * g;
	x = cos(BETA) * cos(GAMMA) * x -
		cos(BETA) * sin(GAMMA) * y +
		sin(BETA) * z;
	return (x);
}

int	gety(int x, int y, int z, t_map *params)
{
	int	g;

	g = params->grid_size;
	z *= params->grid_size * 10000 / 100000 * params->heigth;
	x = x * g;
	y = y * g;
	y = (sin(ALPHA) * sin(BETA) * cos(GAMMA) + cos(BETA) * sin(GAMMA)) * x +
		(cos(ALPHA) * cos(GAMMA) - sin(ALPHA) * sin(BETA) * sin(GAMMA)) * (y) +
		sin(ALPHA) * cos(BETA) * z;
	return (y);
}