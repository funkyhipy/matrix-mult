/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c		                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:17:12 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/14 15:17:14 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>

t_img	*init_window(t_mlx *env)
{
	t_img	*image;

	image = malloc(sizeof (t_img));
	env->mlx = mlx_init();
	env->window = mlx_new_window(env->mlx, WIDTH, HEIGHT, "FDF");
	image->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &(image->bpp),
			&(image->line_len), &(image->endian));
	return (image);
}

t_param	*init_params(const char *path)
{
	t_mlx	*mlx;
	t_img	*img;
	t_env	*env;
	t_hmap	*map;
	t_param	*param;

	map = read_map(path);
	env = init_env(map);
	mlx = malloc(sizeof (t_mlx));
	img = init_window(mlx);
	param = malloc(sizeof (t_param));
	param->env = env;
	param->img = img;
	param->mlx = mlx;
	param->hmap = map;
	return (param);
}

t_camera	*init_camera(void)
{
	t_camera	*camera;

	camera = ft_calloc(1, sizeof (t_camera));
	if (!camera)
		return (NULL);
	camera->rota = new_3vect(0, 0, 0);
	if (!camera->rota)
		return (NULL);
	camera->shift = new_3vect(0, 0, 0);
	if (!camera->shift)
	{
		free_vect(camera->rota);
		return (NULL);
	}
	camera->shift_center = NULL;
	camera->projection = ORTHOGONAL;
	camera->zoom = 10;
	return (camera);
}

void	free_params(t_param *self)
{
	free_hmap(self->hmap);
	free_matrix(self->env->map, free_elem);
	free_matrix(self->env->world, free_elem);
	free_matrix(self->env->proj, free_elem);
	free_vect(self->env->camera->rota);
	free_vect(self->env->camera->shift);
	free_vect(self->env->camera->shift_center);
	free(self->env);
	free(self);
}
