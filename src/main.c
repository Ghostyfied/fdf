/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 12:22:32 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/19 14:23:46 by awehlbur      ########   odam.nl         */
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

// testing:
	// int			i = 0;
	// while (start)
	// {
		// ft_putnbr(start->content);
		// ft_putnbr(i++);
		// start = start->next;
	// }

	return (0);
	}
}