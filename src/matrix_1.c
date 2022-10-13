/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "matrix.h"
#include "vector.h"

t_matrix	*new_matrix(size_t rows, size_t cols)
{
	t_matrix	*self;
	size_t		j;

	self = ft_calloc(1, sizeof (t_matrix));
	if (!self)
		return (NULL);
	self->m = ft_calloc(cols, sizeof (void *));
	j = 0;
	while (j < cols)
	{
		self->m[j] = ft_calloc(rows, sizeof (void *));
		if (!self->m[j])
		{
			while (j-- > 0)
				free(self->m[j]);
			return (NULL);
		}
		++j;
	}
	self->rows = rows;
	self->cols = cols;
	return (self);
}

t_matrix	*cpy_matrix(t_matrix *other)
{
	t_matrix	*self;
	size_t		j;
	size_t		i;

	if (!other)
		return (NULL);
	self = new_matrix(other->rows, other->cols);
	if (!self)
		return (NULL);
	j = 0;
	while (j < self->cols)
	{
		i = 0;
		while (i < self->rows)
		{
			self->m[j][i] = cpy_elem(other->m[j][i]);
			++i;
		}
		++j;
	}
	return (self);
}

void	set_matrix_elem(t_matrix *self, void *elem, size_t x, size_t y)
{
	if (self && self->m)
	{
		if (x < self->rows && y < self->cols)
			self->m[y][x] = elem;
	}
}

void	free_matrix(t_matrix *self, void (*f)(void*))
{
	size_t	j;
	size_t	i;

	if (self)
	{
		j = 0;
		while (j < self->cols)
		{
			i = 0;
			while (i < self->rows)
			{
				if (f != NULL)
					f(self->m[j][i]);
				++i;
			}
			free(self->m[j]);
			++j;
		}
		free(self->m);
		free(self);
	}
}
