/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                           :+:      :+:    :+:     */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DRAW_H
# define DRAW_H
# include <project.h>
# include <matrix.h>
# include <fdf.h>
# define MAX_COLOR 16711680
# define MIN_COLOR 16777215

typedef struct s_line_helper
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e_xy;
	int		xi;
	int		yi;
	int		i;
	int		n;
}	t_line_helper;

t_matrix		*projected_matrix(t_matrix *A, t_camera *cam);

t_camera		*init_camera(void);

t_vector		*get_gravity_center(t_matrix *self);
t_vector		*get_shift_center_vector(t_matrix *self, t_camera *cam);

int				get_light(int start, int end, double ratio);
int				get_color(t_vector *start, t_vector *end, double ratio);

void			draw(t_img *img, t_env *env);
//créer un nouvel objet qui contiendrait tout?!
void			draw_line(t_vector *s, t_vector *e,
					t_vector *shc, t_vector *ehc, t_img *img);
void			clear_img(t_img *self);

t_line_helper	*new_line_helper(t_vector *start, t_vector *end);

void			put_pixel(t_img *img, int x, int y, int color);
void			draw_points(t_img *img, t_matrix *matrix, t_hmap *map);
void			print_vect(t_vector *e);

#endif //DRAW_H
