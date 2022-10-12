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
	r += handle_moves(keysym, self);
	if (r == 0)
	{
		draw(self->img, self->env);
		mlx_put_image_to_window(self->mlx->mlx,
			self->mlx->window, self->img->img, 0, 0);
	}
	printf("Keypress: %x\n", keysym);
	return (0);
}

int	handle_moves(int keysym, t_param *self)
{
	if (keysym == XK_KP_Up)
	{
		self->env->camera->rota->coord[0] += M_PI / 180;
	}
	else if (keysym == XK_KP_Down)
	{
		self->env->camera->rota->coord[0] -= M_PI / 180;
	}
	else if (keysym == XK_KP_Left)
	{
		self->env->camera->rota->coord[1] += M_PI / 180;
	}
	else if (keysym == XK_KP_Right)
	{
		self->env->camera->rota->coord[1] -= M_PI / 180;
	}
	return (0);
}

int	handle_camera(int keysym, t_param *self)
{
	if (keysym == XK_c)
	{
		if (self->env->camera->projection == ISOMETRIC)
			self->env->camera->projection = ORTHOGONAL;
		else if (self->env->camera->projection == ORTHOGONAL)
			self->env->camera->projection = ISOMETRIC;
	}
	else if (keysym == XK_KP_Add)
	{
		self->env->camera->zoom += 1;
	}
	else if (keysym == XK_KP_Subtract)
	{
		if (self->env->camera->zoom > 1)
			self->env->camera->zoom -= 1;
	}
	return (0);
}

int	handle_exit(int keysym, t_param *self)
{
	if (keysym == XK_Escape)
	{
		if (self->mlx->mlx && self->mlx->window)
		{
			mlx_destroy_window(self->mlx->mlx, self->mlx->window);
			self->mlx->window = NULL;
			return (1);
		}
	}
	return (0);
}
