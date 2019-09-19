/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_and_check_input.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 13:15:55 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/19 13:16:24 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_bool			check_input(t_list **start)
{
	t_list		*temp;
	size_t		len;

	if (*start)
	{
		temp = *start;
		len = temp->content_size;
		while (temp)
		{
			if (temp->content_size != len)
			{
				ft_lstdel(start, ft_freezero);
				return (0);
			}
			temp = temp->next;
		}
		return (1);
	}
	return (0);
}

static int		*create_int_array(char **temp, int size)
{
	int			*temp_tab;
	int			i;

	i = 0;
	temp_tab = ft_memalloc(sizeof(int) * size);
	while (i < size)
	{
		temp_tab[i] = ft_atoi(temp[i]);
		i++;
	}
	return (temp_tab);
}

void			read_map(int fd, t_list	**start)
{
	char		*line;
	char		**temp;
	int			i;
	int			*tab;

	*start = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		temp = ft_strsplit(line, ' ');
		while (temp[i])
			i++;
		tab = create_int_array(temp, i);
		ft_lstcat(start, ft_lstnew(tab, sizeof(int) * i));
		free(temp);
		free(tab);
	}
	ft_freezero(line, ft_strlen(line));
	close(fd);
}