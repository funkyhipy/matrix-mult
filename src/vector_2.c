/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <vector.h>

void	mult_vect(t_vector *self, double scalar)
{
	size_t	dim;

	dim = self->dim;
	while (dim-- > 0)
		self->coord[dim] *= scalar;
}

double	dot_vect(t_vector *self, t_vector *other)
{
	double	tmp;
	size_t	dim;

	tmp = 0;
	if (self->dim == other->dim)
	{
		dim = self->dim;
		while (dim-- > 0)
		{
			tmp += self->coord[dim] * other->coord[dim];
		}
	}
	return (tmp);
}

double	cross_2vect(t_vector *self, t_vector *other)
{
	double	tmp;
	size_t	dim;

	tmp = 0;
	if (self->dim == other->dim)
	{
		dim = self->dim;
		if (dim == 2)
		{
			tmp = self->coord[0] * other->coord[1];
			tmp -= self->coord[1] * other->coord[0];
		}
	}
	return (tmp);
}

t_vector	*cross_3vect(t_vector *self, t_vector *other)
{
	t_vector	*tmp;
	size_t		dim;
	double		init[3];

	tmp = NULL;
	if (self->dim == other->dim)
	{
		dim = self->dim;
		if (dim == 3)
		{
			init[0] = self->coord[1] * other->coord[2]
				- self->coord[2] * other->coord[1];
			init[1] = self->coord[2] * other->coord[0]
				- self->coord[0] * other->coord[2];
			init[2] = self->coord[0] * other->coord[1]
				- self->coord[1] * other->coord[0];
			tmp = new_3vect(init[0], init[1], init[2]);
			if (!tmp)
				return (NULL);
		}
	}
	return (tmp);
}

double	get_norm(t_vector *self)
{
	double	tmp;
	size_t	dim;

	dim = self->dim;
	tmp = 0;
	while (dim-- > 0)
	{
		tmp += self->coord[dim] * self->coord[dim];
	}
	return (sqrt(tmp));
}
