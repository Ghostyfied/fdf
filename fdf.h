/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <awehlbur@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 12:22:45 by awehlbur       #+#    #+#                */
/*   Updated: 2019/09/25 19:52:59 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./includes/libft/includes/libft.h"
# include "./includes/minilibx/mlx.h"

# define X 1300
# define Y 1300
# include <math.h>

# define ALPHA params->alpha
# define BETA params->beta
# define GAMMA params->gamma

typedef struct		s_grid
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				z1;
	int				z2;
	struct s_grid	*next;
}					t_grid;

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
	int					grid_size;
	double				alpha;
	double				beta;
	double				gamma;
	t_grid				*plot_head;
	t_max				*max;
	t_list				*map_start;
	t_img				*img;
	t_rgb				*rgb;
}						t_map;


typedef struct 			s_fdf
{
	t_list				*start;
}						t_fdf;

/*			main.c		 			*/
int				main(int argc, char **argv);

/*			read_and_check_input	*/
void			read_map(int fd, t_list	**start);
t_bool			check_input(t_list **start);

/*			extra.c		 			*/
void			ft_error(char *str);
void			memdel_and_exit(t_map *params);
void			get_color_scheme(t_map *params, int i);

t_map			*init(t_list *start, char *title);

/*			draw_map.c				 */
void			draw_map(t_map *params);

/*			get_colors.c			 */
int				ft_blue(int color);
int				ft_green(int color);
int				ft_red(int color);

/*			get_coor.c				 */
int				gety(int x, int y, int z, t_map *params);
int				getx(int x, int y, int z, t_map *params);

#endif