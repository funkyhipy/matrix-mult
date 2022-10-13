/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <draw.h>

t_matrix	*projected_matrix(t_matrix *A, t_camera *cam)
{
	t_matrix	*res;
	t_vector	*tmp;
	size_t		i;
	size_t		j;

	res = cpy_matrix(A);
	j = 0;
	while (j < res->cols)
	{
		i = 0;
		while (i < res->rows)
		{
			tmp = project_vect(res->m[j][i], cam);
			free_elem(res->m[j][i]);
			res->m[j][i] = tmp;
			++i;
		}
		++j;
	}
	return (res);
}

t_vector	*get_gravity_center(t_matrix *self)
{
	t_vector	*res;
	size_t		i;
	size_t		j;
	size_t		k;
	double		n;

	n = (double)(self->rows * self->cols);
	res = new_3vect(0, 0, 0);
	j = 0;
	while (j < self->cols)
	{
		i = 0;
		while (i < self->rows)
		{
			k = 0;
			while (k < ((t_vector *)(self->m[j][i]))->dim)
			{
				res->coord[k] += (((t_vector *)(self->m[j][i]))->coord[k]) / n;
				++k;
			}
			++i;
		}
		++j;
	}
	return (res);
}

t_vector	*get_shift_center_vector(t_matrix *self, t_camera *cam)
{
	t_vector	*img_center;
	t_vector	*matrix_center;
	t_vector	*proj_center;

	img_center = new_2vect(WIDTH / 2.0, HEIGHT / 2.0);
	matrix_center = get_gravity_center(self);
	proj_center = project_vect(matrix_center, cam);
	sbstr_vect(img_center, proj_center);
	free_vect(proj_center);
	free_vect(matrix_center);
	return (img_center);
}
