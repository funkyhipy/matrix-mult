/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_to_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>
#include "draw.h"

t_matrix	*hmap_to_world_matrix(t_hmap *self)
{
	size_t		i;
	size_t		j;
	t_matrix	*res;
	t_vector	*elem;

	res = new_matrix(self->width, self->height);
	j = 0;
	while (j < self->height)
	{
		i = 0;
		while (i < self->width)
		{
			elem = new_3vect((double)i, (double)j,
					(double)(self->z_matrix[j][i]));
			set_matrix_elem(res, elem, i, j);
			++i;
		}
		++j;
	}
	return (res);
}

t_matrix	*hmap_to_map_matrix(t_hmap *self)
{
	size_t		i;
	size_t		j;
	t_matrix	*res;
	t_vector	*elem;

	res = new_matrix(self->width, self->height);
	j = 0;
	while (j < self->height)
	{
		i = 0;
		while (i < self->width)
		{
			elem = new_2vect((double)(self->z_matrix[j][i]),
					(double)(self->c_matrix[j][i]));
			if (elem->coord[1] == -1)
				elem->coord[1] = (double)get_color_height
					(self->z_matrix[j][i], self);
			set_matrix_elem(res, elem, i, j);
			++i;
		}
		++j;
	}
	return (res);
}

int	get_color_height(int height, t_hmap *ref)
{
	double	ratio;

	ratio = (double)(height - ref->min_h) / (ref->max_h - ref->min_h);
	return (get_light(MIN_COLOR, MAX_COLOR, ratio));
}

t_env	*init_env(t_hmap *hmap)
{
	t_env	*self;

	self = ft_calloc(1, sizeof (t_env));
	self->map = hmap_to_map_matrix(hmap);
	self->world = hmap_to_world_matrix(hmap);
	self->cols = hmap->width;
	self->lines = hmap->height;
	self->camera = init_camera();
	self->camera->shift_center = get_shift_center_vector
		(self->world, self->camera);
	return (self);
}
