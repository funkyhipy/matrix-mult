/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

int	handle_move(int keysym, t_param *self)
{
	if (keysym == ARROW_LEFT)
		self->env->camera->shift->coord[0] -= 10;
	else if (keysym == ARROW_RIGHT)
		self->env->camera->shift->coord[0] += 10;
	else if (keysym == ARROW_UP)
		self->env->camera->shift->coord[1] -= 10;
	else if (keysym == ARROW_DOWN)
		self->env->camera->shift->coord[1] += 10;
	return (0);
}

int	handle_quit(t_param *self)
{
	if (self->mlx->mlx && self->mlx->window)
	{
		mlx_destroy_image(self->mlx->mlx, self->img->img);
		mlx_destroy_window(self->mlx->mlx, self->mlx->window);
		self->mlx->window = NULL;
		self->mlx->mlx = NULL;
		free_params(self);
		exit(0);
	}
	return (0);
}
