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
#include "vector.h"

void	add_elem(void *self, void *other)
{
	t_vector	*s;
	t_vector	*o;
	size_t		i;

	s = self;
	o = other;
	if (s->dim == o->dim)
	{
		i = 0;
		while (i < s->dim)
		{
			s->coord[i] += o->coord[i];
			++i;
		}
	}
}

void	mult_elem(void *self, void *other)
{
	t_vector	*s;
	t_vector	*o;
	size_t		i;

	s = self;
	o = other;
	if (s->dim == o->dim)
	{
		i = 0;
		while (i < s->dim)
		{
			s->coord[i] *= o->coord[i];
			++i;
		}
	}
}

void	print_line(t_matrix *self, int j)
{
	size_t		i;
	size_t		k;
	t_vector	*e;

	i = 0;
	while (i < self->rows)
	{
		e = self->m[j][i];
		k = 0;
		printf("(");
		while (k < e->dim)
		{
			printf("%.2f", e->coord[k]);
			if (k != e->dim - 1)
				printf(", ");
			++k;
		}
		printf(")");
		++i;
		if (i != self->rows)
			printf(", ");
	}
}

void	print_matrix(t_matrix *self)
{
	size_t		j;

	if (self)
	{
		j = 0;
		printf("[");
		while (j < self->cols)
		{
			printf("[");
			print_line(self, j);
			printf("]");
			++j;
			if (j != self->cols)
				printf("\n");
		}
		printf("]\n");
	}
}
