/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>
#include <hmap.h>

static bool	is_valid_hex(const char *hex_str)
{
	size_t	i;
	char	c;

	i = 0;
	c = *(hex_str + i);
	while (i < 6)
	{
		if (ft_isdigit(c) || ('A' <= c && c <= 'F'))
			c = *(hex_str + (++i));
		else
			return (false);
	}
	return (true);
}

//here 0 is returned for wrong hex format
// we could catch it as a mistake?
static int	str_hex_to_int(char *hex_str)
{
	size_t	i;
	int		tmp;
	char	c;

	if (*hex_str == '0' && *(hex_str + 1) == 'x')
	{
		hex_str += 2;
		if (!is_valid_hex(hex_str))
			return (0);
		tmp = 0;
		i = 0;
		while (i < 6)
		{
			tmp *= 16;
			c = *(hex_str + i++);
			if (ft_isdigit(c))
				tmp += c - '0';
			else
				tmp += c - 'A' + 10;
		}
		return (tmp);
	}
	return (0);
}

static void	read_file_helper_elems(t_hmap *m, char *line)
{
	char		**elems;
	char		*color;
	int			height;

	elems = ft_split(line, ' ');
	while (m->counter->width < m->width && *(elems + m->counter->width))
	{
		color = NULL;
		height = ft_atoi(*(elems + m->counter->width));
		if (m->min_h > height)
			m->min_h = height;
		if (m->max_h < height)
			m->max_h = height;
		m->z_matrix[m->counter->height][m->counter->width] = height;
		color = ft_strchr(*(elems + m->counter->width), ',');
		if (color)
			m->c_matrix[m->counter->height][m->counter->width]
				= str_hex_to_int(color + 1);
		else
			m->c_matrix[m->counter->height][m->counter->width] = -1;
		free(*(elems + m->counter->width));
		++(m->counter->width);
	}
	free(elems);
}

void	read_file_helper(int fd, t_hmap *m)
{
	char		*line;

	m->counter->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		m->counter->width = 0;
		read_file_helper_elems(m, line);
		free(line);
		line = get_next_line(fd);
		++(m->counter->height);
	}
}

t_hmap	*read_map(const char *fdf_filename)
{
	int			fd;
	t_hmap		*self;
	t_hmap_dim 	*dim;

	dim = get_dimensions(fdf_filename);
	if (!dim)
		return (NULL);
	self = new_hmap(dim);
	if (!self)
		return (NULL);
	fd = open(fdf_filename, O_RDONLY);
	if (fd > 0)
	{
		read_file_helper(fd, self);
		close(fd);
	}
	return (self);
}
