/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PROJECT_H
# define PROJECT_H
# include <vector.h>

typedef enum s_projection
{
	ORTHOGONAL,
	ISOMETRIC
}	t_projection;

typedef struct s_camera
{
	t_projection	projection;
	double			zoom;
	t_vector		*rota;
	t_vector		*shift;
	t_vector		*shift_center;
}	t_camera;

t_vector	*project_vect(t_vector *point, t_camera *camera);
double		ft_round(double nb);
void		rotate_vect(t_vector *self, t_vector *rota);
void		rotate_vect_x(t_vector *self, double teta);
void		rotate_vect_y(t_vector *self, double teta);
void		rotate_vect_z(t_vector *self, double teta);
void		shift_vect(t_vector *self, t_vector *shift);
void		zoom_vect(t_vector *self, double zoom);
#endif //PROJECT_H
