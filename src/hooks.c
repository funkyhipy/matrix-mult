#include <fdf.h>
#include "draw.h"

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	if (data)
		return (0);
	return (0);
}

int	handle_keypress(int keysym, t_param *self)
{
	//t_mlx *self, t_env *env, t_img *img
	if (keysym == XK_Escape)
	{
		if (self->mlx->mlx && self->mlx->window)
		{
			mlx_destroy_window(self->mlx->mlx, self->mlx->window);
			self->mlx->window = NULL;
			return (0);
		}
	}
	else if (keysym == XK_c)
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
	else if (keysym == XK_KP_Up)
	{
		self->env->camera->rota->coord[0] += M_PI/180;
	}
	else if (keysym == XK_KP_Down)
	{
		self->env->camera->rota->coord[0] -= M_PI/180;
	}
	else if (keysym == XK_KP_Left)
	{
		self->env->camera->rota->coord[1] += M_PI/180;
	}
	else if (keysym == XK_KP_Right)
	{
		self->env->camera->rota->coord[1] -= M_PI/180;
	}
	draw(self->img, self->env);
	mlx_put_image_to_window(self->mlx->mlx, self->mlx->window, self->img->img, 0, 0);
	printf("Keypress: %x\n", keysym);
	return (0);
}