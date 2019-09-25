/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_map1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 16:58:47 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/25 19:58:24 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	grid_switchx(t_grid *plot_head, int shift)
{
	t_grid	*tmp;

	tmp = plot_head;
	while (tmp)
	{
		tmp->x1 += shift;
		tmp->x2 += shift;
		tmp = tmp->next;
	}
}

void	grid_switchy(t_grid *plot_head, int shift)
{
	t_grid	*tmp;

	tmp = plot_head;
	while (tmp)
	{
		tmp->y1 += shift;
		tmp->y2 += shift;
		tmp = tmp->next;
	}
}

void	draw(t_map *params)
{
	t_grid	*tmp;
	t_grid	*clear;

	tmp = params->plot_head;
	while (tmp)
	{
		bresenham(tmp, params);
		tmp = tmp->next;
	}
	tmp = params->plot_head;
	while (tmp)
	{
		clear = tmp;
		tmp = tmp->next;
		free(clear);
	}
	params->plot_head = NULL;
	ft_freezero(params->max, sizeof(t_max));
	params->max = (t_max *)ft_memalloc(sizeof(t_max));
	image_put(params);
	wf_print_legend(params, "text/legend1.txt", 0);
	wf_print_legend(params, "text/legend2.txt", 1);
}

void				add_grid(t_map *params, t_grid *new)
{
	t_max	*max;

	new->next = params->plot_head;
	params->plot_head = new;
	max = params->max;
	max->xmax = ft_max(max->xmax, new->x1);
	max->xmin = ft_min(max->xmin, new->x1);
	max->ymax = ft_max(max->ymax, new->y1);
	max->ymin = ft_min(max->ymin, new->y1);
	max->zmax = ft_max(max->zmax, new->z1);
	max->zmin = ft_min(max->zmin, new->z1);
}

static t_list		*get_array(t_list *map_start, int size)
{
	int		n;
	t_list	*drone;

	n = 0;
	drone = map_start;
	while (n++ < size)
		drone = drone->next;
	return (drone);
}

static t_grid		*grid(t_map *params, int k, int i, char axe)
{
	int			*tab;
	t_grid		*grid;
	t_list		*drone;

	grid = ft_memalloc(sizeof(t_grid));
	drone = get_array(params->map_start, k);
	tab = drone->content;
	grid->x1 = getx(i, k, tab[i + 1], params);
	grid->y1 = gety(i, k, tab[i + 1], params);
	grid->z1 = tab[i];
	if (axe == 'x')
	{
		grid->x2 = getx(i + 1, k, tab[i + 1], params);
		grid->y2= gety(i + 1, k, tab[i + 1], params);
		grid->z2 = tab[i + 1];
	}
	else
	{
		tab = drone->next->content;
		grid->x2 = getx(i, k + 1, tab[i], params);
		grid->y2= gety(i, k + 1, tab[i], params);
		grid->z2 = tab[i];
	}
	return (grid);
}

void				draw_map(t_map *params)
{
	int			i;
	int			k;
	t_list		*drone;

	k = 0;
	drone = params->map_start;
	while (drone)
	{
		i = -1;
		while (++i < drone->content_size / sizeof(int))
		{
			if (i + 1 < drone->content_size / sizeof(int))
				add_grid(params, grid(params, k, i, 'x'));
			if (drone->next)
				add_grid(params, grid(params, k, i, 'y'));
		}
		drone = drone->next;
		k++;
	}
	if (params->max->xmin < 0)
		grid_switchx(params->plot_head, -1 * params->max->ymin);
	if (params->max->ymin < 0)
		grid_switchy(params->plot_head, -1 * params->max->ymin);
	// draw(params);
}