/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:14:59 by aaguiler          #+#    #+#             */
/*   Updated: 2023/03/23 18:59:40 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define HEIGHT 512
# define WIDTH 960
# define MS 64

# include "libft.h"
# include "MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>

# define PI 3.141593
# define P2 1.570796
# define P3 4.712389
# define DR 0.0174533 // One degree in radians

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_int
{
	int			x;
	int			y;
}				t_int;

typedef struct s_float
{
	float		x;
	float		y;
}				t_float;

typedef struct s_ray
{
	float		x;
	float		y;
	int			dir;
	float		distance;
	float		line_h;
	float		ray_angle;
	float		ty_offset;
	float		ty_step;
}				t_ray;

typedef struct s_var
{
	mlx_t			*mlx;
	mlx_image_t		*g_img;
	t_point			p;
	t_float			pd;
	float			p_angle;
	t_int			map;
	t_int			map_real;
	char			**map_data;
	int				mouse_x;
	char			dir;
	__uint32_t		ceiling;
	__uint32_t		floor;
	mlx_texture_t	*t_no;
	mlx_texture_t	*t_su;
	mlx_texture_t	*t_es;
	mlx_texture_t	*t_we;
}					t_var;

// Hooks
void			hook(void *param);
void			movement_keyhook(mlx_key_data_t keydata, void *param);
void			my_curhook(double xpos, double ypos, void *param);

// Loop
void			ft_loop(t_var *vars);

// Terminate
void			ft_terminate(t_var *vars);

// Init
t_var			*ft_init_vars(int arcg, char *argv[]);

// Display
void			ft_display_minimap(t_var *vars);
void			ft_display(t_var *vars);
void			ft_display_rays(t_var *vars);

// Utils
float			dist(t_point a, t_ray b);
void			ft_draw_vertical_line(t_var *vars, int x, t_ray *ray);
void			ft_put_pixel(t_var *vars, int x, int y, int color);
int				ft_is_minimap(t_var *vars, t_point p);
float			ft_safe_float_sum(float a, float b);
void			ft_recalculate_angle(t_var *vars, float variation);
void			ft_move_player(t_var *vars, int x, int y);
void			ft_get_angle(t_var *vars);
int				ft_set_player(t_var *vars);
void			ft_parse_map(char **fl, t_var *vars);
void			ft_set_map_x(t_var *vars, char **map);
mlx_texture_t	*ft_get_texture_property(char **file_lines,
					char *property, int *error);
__uint32_t		ft_get_color_property(char **file_lines,
					char *property, int *error);
int				ft_error(char *message, int print_strerror);
int				ft_check_args(int argc, char **argv);
char			*ft_get_file_property(char **file_lines,
					char *property, char *line);
void			ft_free_vars(t_var *vars);
int				ft_check_map_wall(char **map, int height, int width);
int				ft_check_map_content(char **map);

#endif