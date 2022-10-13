/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c		                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:17:12 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/14 15:17:14 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>
#include <fdf.h>

int	main(int argc, char *argv[])
{
	char	*path;
	t_param	*param;

	if (argc != 2)
		return (0);
	path = argv[1];
	param = init_params(path);
	if (param)
	{
		draw(param->img, param->env);
		mlx_put_image_to_window(param->mlx->mlx,
								param->mlx->window, param->img->img, 0, 0);
		mlx_loop_hook(param->mlx->mlx, &handle_no_event, param);
		mlx_hook(param->mlx->window, KEY_PRESS, KEYPRESSMASK,
				 &handle_keypress, param);
		mlx_hook(param->mlx->window, 17, 0L << 0, &handle_quit, param);
		mlx_loop(param->mlx->mlx);
	}
	return (0);
}
