/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "matrix.h"

static void	*mult_helper(t_matrix *A, t_matrix *B, size_t x, size_t y)
{
	size_t		k;
	void		*elem;
	void		*tmp;

	k = 0;
	elem = new_elem();
	((t_vector *)elem)->dim = ((t_vector *)A->m[y][x])->dim;
	((t_vector *)elem)->coord = ft_calloc(
			((t_vector *)elem)->dim, sizeof (double));
	while (k < A->cols)
	{
		tmp = cpy_elem(A->m[k][x]);
		mult_elem(tmp, B->m[y][k]);
		add_elem(elem, tmp);
		free_elem(tmp);
		++k;
	}
	return (elem);
}

t_matrix	*mult_matrix(t_matrix *A, t_matrix *B)
{
	t_matrix	*self;
	size_t		j;
	size_t		i;

	if (A->cols == B->rows)
	{
		self = new_matrix(A->rows, B->cols);
		if (!self)
			return (NULL);
		j = 0;
		while (j < self->cols)
		{
			i = 0;
			while (i < self->rows)
			{
				self->m[j][i] = mult_helper(A, B, i, j);
				++i;
			}
			++j;
		}
		return (self);
	}
	return (NULL);
}

void	*cpy_elem(void *elem)
{
	t_vector	*tmp;
	t_vector	*cpy;
	size_t		k;

	tmp = elem;
	cpy = ft_calloc(1, sizeof (t_vector));
	if (!cpy)
		return (NULL);
	cpy->dim = tmp->dim;
	cpy->coord = ft_calloc(cpy->dim, sizeof (double));
	if (!cpy->coord)
	{
		free(cpy);
		return (NULL);
	}
	k = 0;
	while (k < cpy->dim)
	{
		cpy->coord[k] = tmp->coord[k];
		++k;
	}
	return (cpy);
}

void	*new_elem(void)
{
	t_vector	*e;

	e = calloc(1, sizeof(t_vector));
	if (!e)
		return (NULL);
	return (e);
}

void	free_elem(void *self)
{
	t_vector	*s;

	s = self;
	free(s->coord);
	free(s);
}
