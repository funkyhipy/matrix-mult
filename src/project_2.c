/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <project.h>

void	rotate_vect(t_vector *self, t_vector *rota)
{
	rotate_vect_x(self, rota->coord[0]);
	rotate_vect_y(self, rota->coord[1]);
	rotate_vect_z(self, rota->coord[2]);
}

void	rotate_vect_x(t_vector *self, double teta)
{
	double	y;
	double	z;
	double	cos_t;
	double	sin_t;

	cos_t = cos(teta);
	sin_t = sin(teta);
	y = cos_t * self->coord[1] - sin_t * self->coord[2];
	z = sin_t * self->coord[1] + cos_t * self->coord[2];
	self->coord[1] = y;
	self->coord[2] = z;
}

void	rotate_vect_y(t_vector *self, double teta)
{
	double	x;
	double	z;
	double	cos_t;
	double	sin_t;

	cos_t = cos(teta);
	sin_t = sin(teta);
	x = cos_t * self->coord[0] + sin_t * self->coord[2];
	z = cos_t * self->coord[2] - sin_t * self->coord[0];
	self->coord[0] = x;
	self->coord[2] = z;
}

void	rotate_vect_z(t_vector *self, double teta)
{
	double	x;
	double	y;
	double	cos_t;
	double	sin_t;

	cos_t = cos(teta);
	sin_t = sin(teta);
	x = cos_t * self->coord[0] - sin_t * self->coord[1];
	y = sin_t * self->coord[0] + cos_t * self->coord[1];
	self->coord[0] = x;
	self->coord[1] = y;
}
