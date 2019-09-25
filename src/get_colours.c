/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_colours.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 15:45:45 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/25 15:47:23 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_red(int color)
{
	return ((color & 0xff0000) >> 16);
}

int			ft_green(int color)
{
	return ((color & 0xff00) >> 8);
}

int			ft_blue(int color)
{
	return (color & 0xff);
}