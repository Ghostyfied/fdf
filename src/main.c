/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 12:22:32 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/25 17:34:57 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"



int				main(int argc, char **argv)
{
	int			fd;
	t_list		*start;
	t_map		*params;

	if (argc >= 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			ft_error("Could not open file!");
		read_map(fd, &start);
		if (!check_input(&start))
			ft_error("Not a valid map!");
		params = init(start, argv[1]);
		draw_map(params);
		// mlx_key_hook(params->window, my_key_funct, params);
		// mlx_expose_hook(params->window, my_expose_funct, params);
		// mlx_loop(params->mlx);
		return (0);
	}
}