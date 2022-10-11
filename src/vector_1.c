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

t_vector	*new_3vect(double x, double y, double z)
{
	t_vector	*new;

	new = malloc(sizeof (t_vector));
	if (!new)
		return (NULL);
	new->dim = 3;
	new->coord = ft_calloc(3, sizeof (double));
	if (!new->coord)
	{
		free(new);
		return (NULL);
	}
	new->coord[0] = x;
	new->coord[1] = y;
	new->coord[2] = z;
	return (new);
}

t_vector	*new_2vect(double x, double y)
{
	t_vector	*new;

	new = malloc(sizeof (t_vector));
	if (!new)
		return (NULL);
	new->dim = 2;
	new->coord = ft_calloc(2, sizeof (double));
	if (!new->coord)
	{
		free(new);
		return (NULL);
	}
	new->coord[0] = x;
	new->coord[1] = y;
	return (new);
}

void	free_vect(t_vector *self)
{
	free(self->coord);
	free(self);
}

void	add_vect(t_vector *self, t_vector *other)
{
	size_t	dim;

	if (self->dim == other->dim)
	{
		dim = self->dim;
		while (dim-- > 0)
		{
			self->coord[dim] += other->coord[dim];
		}
	}
}

void	sbstr_vect(t_vector *self, t_vector *other)
{
	size_t	dim;

	if (self->dim == other->dim)
	{
		dim = self->dim;
		while (dim-- > 0)
		{
			self->coord[dim] -= other->coord[dim];
		}
	}
}
