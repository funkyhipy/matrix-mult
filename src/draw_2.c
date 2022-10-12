/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <draw.h>

void	put_pixel(t_img *img, int x, int y, int color)
{
	int		i;

	if (0 <= x && x < WIDTH && 0 <= y && y < HEIGHT)
	{
		i = (x * img->bpp / 8) + (y * img->line_len);
		img->addr[i] = color;
		img->addr[++i] = color >> 8;
		img->addr[++i] = color >> 16;
	}
}

int	get_light(int start, int end, double ratio)
{
	return ((int)((1 - ratio) * start + ratio * end));
}

int	get_color(t_vector *color, double ratio)
{
	int	red;
	int	green;
	int	blue;
	int	s;
	int	e;

	s = (int) color->coord[0];
	e = (int) color->coord[1];
	if (s == e)
		return (s);
	red = get_light((s >> 16) & 0xFF, (e >> 16) & 0xFF, ratio);
	green = get_light((s >> 8) & 0xFF, (e >> 8) & 0xFF, ratio);
	blue = get_light(s & 0xFF, e & 0xFF, ratio);
	return ((red << 16) | (green << 8) | blue);
}

void	draw_points(t_img *img, t_matrix *matrix, t_hmap *map)
{
	size_t		x;
	size_t		y;
	t_vector	*e;

	y = 0;
	while (y < matrix->cols)
	{
		x = 0;
		while (x < matrix->rows)
		{
			e = matrix->m[y][x];
			put_pixel(img, (int)(e->coord[0]), (int)(e->coord[1]),
				(map->c_matrix)[y][x]);
			++x;
		}
		++y;
	}
}

void	print_vect(t_vector *e)
{
	size_t	k;

	k = 0;
	printf("(");
	while (k < e->dim)
	{
		printf("%.2f", e->coord[k]);
		if (k != e->dim - 1)
			printf(", ");
		++k;
	}
	printf(")\n");
}
