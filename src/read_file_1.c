/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:17:12 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/14 15:17:14 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

static size_t	get_dimensions_height(int fd, char *line)
{
	size_t	counter;

	counter = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		++counter;
	}
	return (counter);
}

static size_t	get_dimensions_width(int fd, char **line)
{
	size_t	counter;
	char	*iter;
	bool	valid;

	counter = 0;
	valid = true;
	*line = get_next_line(fd);
	if (*line == NULL)
		return (0);
	iter = *line;
	while (*iter)
	{
		if (*iter == ' ' && valid)
		{
			valid = false;
			++counter;
		}
		else if (*iter != ' ')
			valid = true;
		++iter;
	}
	return (counter + 1);
}

t_hmap_dim	*get_dimensions(const char *fdf_filename)
{
	int			fd;
	char		*line;
	t_hmap_dim	*dim;

	dim = ft_calloc(1, sizeof (t_hmap_dim));
	if (!dim)
		return (NULL);
	fd = open(fdf_filename, O_RDONLY);
	if (fd > 0)
	{
		dim->width = get_dimensions_width(fd, &line);
		dim->height = get_dimensions_height(fd, line);
		close(fd);
	}
	return (dim);
}

// helper debug fonction not needed for final
void	print_data(t_hmap *self)
{
	self->counter->height = 0;
	while (self->counter->height < self->height)
	{
		self->counter->width = 0;
		while (self->counter->width < self->width)
		{
			ft_printf("(%d, %d)\t",
				self->z_matrix[self->counter->height][self->counter->width],
				self->c_matrix[self->counter->height][self->counter->width]);
			++(self->counter->width);
		}
		ft_printf("\n");
		++(self->counter->height);
	}
}
