/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap.c	                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <hmap.h>

t_hmap	*init_hmap(t_hmap *self, size_t width, size_t height)
{
	int			*z_line;
	int			*c_line;

	self->width = width;
	self->height = 0;
	self->z_matrix = calloc(height, sizeof (int *));
	self->c_matrix = calloc(height, sizeof (int *));
	while (self->height < height)
	{
		z_line = ft_calloc(width, sizeof (int));
		if (!z_line)
			return (free_hmap(self));
		c_line = ft_calloc(width, sizeof (int));
		if (!c_line)
		{
			free(z_line);
			return (free_hmap(self));
		}
		self->z_matrix[self->height] = z_line;
		self->c_matrix[self->height] = c_line;
		++self->height;
	}
	return (self);
}

t_hmap	*new_hmap(t_hmap_dim *dimensions)
{
	t_hmap	*self;
	t_hmap	*tmp;

	self = ft_calloc(1, sizeof (t_hmap));
	if (!self)
	{
		free(dimensions);
		return (NULL);
	}
	self->counter = ft_calloc(1, sizeof(t_hmap_dim));
	if (!self->counter)
	{
		free(self);
		free(dimensions);
		return (NULL);
	}
	tmp = init_hmap(self, dimensions->width, dimensions->height);
	if (!tmp)
	{
		free(dimensions);
		return (NULL);
	}
	free(dimensions);
	return (self);
}

void	*free_hmap(t_hmap *self)
{
	reset_counter(self->counter);
	while (self->counter->height < self->height)
	{
		free(self->c_matrix[self->counter->height]);
		free(self->z_matrix[self->counter->height]);
		++(self->counter->height);
	}
	free(self->c_matrix);
	free(self->z_matrix);
	free(self->counter);
	free(self);
	return (NULL);
}

void	reset_counter(t_hmap_dim *self)
{
	self->width = 0;
	self->height = 0;
}
