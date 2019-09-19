/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 12:22:45 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/19 14:42:52 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./includes/libft/includes/libft.h"
# include "./includes/minilibx/mlx.h"

# define X 1300
# define Y 1300

typedef struct		s_plot
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				z1;
	int				z2;
	struct s_plot	*next;
}					t_plot;

typedef struct		s_max
{
	int				xmax;
	int				xmin;
	int				ymax;
	int				ymin;
	int				zmax;
	int				zmin;
}					t_max;

typedef struct		s_img
{
	void			*ptr;
	int				*pixels;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_rgb
{
	int				rmax;
	int				rmin;
	int				gmax;
	int				gmin;
	int				bmax;
	int				bmin;
}					t_rgb;

typedef struct			s_map
{
	void				*mlx;
	void				*window;
	int					start_x;
	int					start_y;
	int					color1[2];
	int					color2[2];
	int					heigth;
	double				alpha;
	double				beta;
	double				gamma;
	t_plot				*plot_head;
	t_max				*max;
	t_list				*map_start;
	t_img				*img;
	t_rgb				*rgb;
}						t_map;


typedef struct 			s_fdf
{
	t_list				*start;
}						t_fdf;


int				main(int argc, char **argv);

void			read_map(int fd, t_list	**start);
t_bool			check_input(t_list **start);

void			ft_error(char *str);
void			memdel_and_exit(t_map *params);

t_map			*init(t_list *start, char *title);

#endif