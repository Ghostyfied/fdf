/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 13:35:19 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/25 15:42:04 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void		get_grid_start_size(t_map *params)
{
	int			x;
	int			y;
	t_list		*drone;

	y = 0;
	x = params->map_start->content_size / sizeof(int);
	drone = params->map_start;
	while (drone)
	{
		drone = drone->next;
		y++;
	}
	params->grid_size = 1100 / (int)sqrt(x * x + y * y);
}

static void		clear_image(t_map *params)
{
	t_img		*img;

	img = params->img;
	ft_bzero(img, sizeof(t_img));
	img->ptr = mlx_new_image(params->mlx, X, Y);
	img->pixels = (int*)mlx_get_data_addr(img->ptr, &img->bpp, 
												&img->size_line, &img->endian);
}

static void		init_colors(t_map *params)
{
	params->color1[0] = 0xff;
	params->color1[1] = 0;
	params->color2[0] = 0xffa500;
	params->color2[1] = 0xffffff;
}

void			image_init(t_map *params)
{
	t_img		*new;

	if (!(new = (t_img*)ft_memalloc(sizeof(t_img))))
	{
		ft_putendl("Could not allocate memory for Image pointer!");
		memdel_and_exit(params);
	}
	params->img = new;
	clear_image(params);
}

t_map			*init(t_list *start, char *title)
{
	t_map		*params;

	params = (t_map*)ft_memalloc(sizeof(t_map));
	init_colors(params);
	params->mlx = mlx_init();
	params->window = mlx_new_window(params->mlx, X, Y, title);
	image_init(params);
	params->start_x = X / 2;
	params->start_y = Y /2;
	params->plot_head = NULL;
	params->alpha = -0.698132;
	params->beta = 0;
	params->gamma = 0.698132;
	params->map_start = start;
	params->max = (t_max*)ft_memalloc(sizeof(t_max));
	ft_bzero(params->max, sizeof(t_max));
	get_grid_start_size(params);
	params->heigth = 1;
	get_color_scheme(params, 0);
	return (params);
}