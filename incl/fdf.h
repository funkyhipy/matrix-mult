/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <vector.h>
# include <hmap.h>
# include <matrix.h>
# include <project.h>

# define HEIGHT			1000
# define WIDTH			2000

typedef struct s_point
{
	t_vector	*vect;
	int			color;
}	t_point;

typedef struct s_line
{
	t_point	*A;
	t_point	*B;
}	t_line;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}	t_mlx;

typedef struct s_env
{
	t_matrix	*map;
	t_matrix	*world;
	t_matrix	*proj;
	size_t		cols;
	size_t		lines;
	t_camera	*camera;
}	t_env;

typedef struct s_param
{
	t_mlx	*mlx;
	t_img	*img;
	t_env	*env;
	t_hmap	*hmap;
}	t_param;

int			handle_no_event(void *data);
int			handle_keypress(int keysym, t_param *self);

//hmap_to_matrix.c
t_matrix	*hmap_to_world_matrix(t_hmap *self);
t_matrix	*hmap_to_map_matrix(t_hmap *self);
t_env		*init_env(t_hmap *hmap);

//init.c
t_img		*init_window(t_mlx *env);
t_param		*init_params(const char *path);
void		free_params(t_param *self);

//read_file.c
t_hmap_dim	*get_dimensions(const char *fdf_filename);
t_hmap		*read_map(const char *fdf_filename);
void		print_data(t_hmap *data);

#endif //FDF_FDF_H
