/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>
#include "draw.h"

int	handle_no_event(void *data)
{
	if (data)
		return (0);
	return (0);
}

int	handle_keypress(int keysym, t_param *self)
{
	int	r;

	r = 0;
	r += handle_exit(keysym, self);
	r += handle_camera(keysym, self);
	r += handle_rota(keysym, self);
	if (r == 0)
	{
		draw(self->img, self->env);
		mlx_put_image_to_window(self->mlx->mlx,
			self->mlx->window, self->img->img, 0, 0);
	}
	return (0);
}

int	handle_rota(int keysym, t_param *self)
{
	if (keysym == XK_KP_UP)
	{
		self->env->camera->rota->coord[0] += M_PI / 180;
	}
	else if (keysym == XK_KP_DOWN)
	{
		self->env->camera->rota->coord[0] -= M_PI / 180;
	}
	else if (keysym == XK_KP_LEFT)
	{
		self->env->camera->rota->coord[1] += M_PI / 180;
	}
	else if (keysym == XK_KP_RIGHT)
	{
		self->env->camera->rota->coord[1] -= M_PI / 180;
	}
	return (0);
}

int	handle_camera(int keysym, t_param *self)
{
	if (keysym == XK_C)
	{
		if (self->env->camera->projection == ISOMETRIC)
			self->env->camera->projection = ORTHOGONAL;
		else if (self->env->camera->projection == ORTHOGONAL)
			self->env->camera->projection = ISOMETRIC;
	}
	else if (keysym == XK_KP_ADD)
	{
		self->env->camera->zoom += 1;
	}
	else if (keysym == XK_KP_SUBTRACT)
	{
		if (self->env->camera->zoom > 1)
			self->env->camera->zoom -= 1;
	}
	return (0);
}

int	handle_exit(int keysym, t_param *self)
{
	if (keysym == XK_ESCAPE)
	{
		handle_quit(self);
		return (1);
	}
	return (0);
}
