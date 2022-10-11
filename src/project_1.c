/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <project.h>

t_vector	*project_vect(t_vector *point, t_camera *camera)
{
	t_vector	*proj;
	t_vector	*rota;

	zoom_vect(point, camera->zoom);
	if (camera->projection == ISOMETRIC)
	{
		rota = new_3vect(0, 0, M_PI_4);
		rotate_vect(point, rota);
		free_vect(rota);
		rota = new_3vect(atan(M_SQRT1_2), 0, 0);
		rotate_vect(point, rota);
		free_vect(rota);
	}
	rota = camera->rota;
	rotate_vect(point, rota);
	shift_vect(point, camera->shift);
	proj = new_2vect(ft_round(point->coord[0]), ft_round(point->coord[1]));
	if (camera->shift_center)
		shift_vect(proj, camera->shift_center);
	return (proj);
}

double	ft_round(double nb)
{
	if (fmod(nb, 1) > 0.5)
		return (ceil(nb));
	return (floor(nb));
}

void	shift_vect(t_vector *self, t_vector *shift)
{
	add_vect(self, shift);
}

void	zoom_vect(t_vector *self, double zoom)
{
	mult_vect(self, zoom);
}
