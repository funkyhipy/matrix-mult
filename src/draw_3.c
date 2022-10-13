/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <draw.h>

void	draw_line(t_vector *s, t_vector *e, t_vector *color, t_img *img)
{
	t_line_helper	*c;

	c = new_line_helper(s, e);
	while (true)
	{
		put_pixel(img, c->xi, c->yi,
			get_color(color, (c->i / (double)c->n)));
		if ((c->xi == (int)e->coord[0]) && (c->yi == (int)e->coord[1]))
		{
			free(c);
			break ;
		}
		c->e_xy = 2 * c->err;
		if (c->e_xy >= c->dy)
		{
			c->err += c->dy;
			c->xi += c->sx;
		}
		if (c->e_xy <= c->dx)
		{
			c->err += c->dx;
			c->yi += c->sy;
		}
		++(c->i);
	}
}

t_line_helper	*new_line_helper(t_vector *start, t_vector *end)
{
	t_line_helper	*self;

	self = ft_calloc(1, sizeof (t_line_helper));
	self->dx = (int)fabs(end->coord[0] - start->coord[0]);
	self->dy = -(int)fabs(end->coord[1] - start->coord[1]);
	if (start->coord[0] < end->coord[0])
		self->sx = 1;
	else
		self->sx = -1;
	if (start->coord[1] < end->coord[1])
		self->sy = 1;
	else
		self->sy = -1;
	self->err = self->dx + self->dy;
	self->xi = (int)(start->coord[0]);
	self->yi = (int)(start->coord[1]);
	self->n = (int)(fmax(self->dx, -self->dy)
			+ (2929 * fmin(self->dx, -self->dy)) / 7071);
	self->i = 0;
	return (self);
}

void	draw_helper(t_env *env)
{
	if (env->proj)
		free_matrix(env->proj, free_elem);
	if (env->camera->shift_center)
	{
		free_vect(env->camera->shift_center);
		env->camera->shift_center = NULL;
	}
	env->camera->shift_center = get_shift_center_vector
		(env->world, env->camera);
	env->proj = projected_matrix(env->world, env->camera);
}

void	clear_img(t_img *self)
{
	ft_bzero(self->addr, WIDTH * HEIGHT * (self->bpp / 8));
}

void	draw2(int n, t_vector *color, t_vector ***map, long i[2])
{
	if (n == 0)
	{
		color->coord[0] = map[i[0]][i[1]]->coord[1];
		color->coord[1] = map[i[0]][i[1] + 1]->coord[1];
	}
	if (n == 1)
	{
		color->coord[0] = map[i[0]][i[1]]->coord[1];
		color->coord[1] = map[i[0] + 1][i[1]]->coord[1];
	}
}
