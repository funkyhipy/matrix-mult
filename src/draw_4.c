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

void	draw_degeu(t_vector	**color, long *i)
{
	*color = new_2vect(MIN_COLOR, MIN_COLOR);
	i[0] = -1;
}

void	draw_init(t_img *img, t_env *env, t_vector ****proj, t_vector ****map)
{
	draw_helper(env);
	*proj = (t_vector ***)env->proj->m;
	*map = (t_vector ***)env->map->m;
	clear_img(img);
}

void	draw(t_img *img, t_env *env)
{
	long		i[2];
	t_vector	***proj;
	t_vector	***map;
	t_vector	*color;

	draw_init(img, env, &proj, &map);
	draw_degeu(&color, i);
	while (++(i[0]) < (long)(env->lines))
	{
		i[1] = -1;
		while (++(i[1]) < (long)(env->cols))
		{
			if (i[1] < (long)(env->cols - 1))
			{
				draw2(0, color, map, i);
				draw_line(proj[i[0]][i[1]], proj[i[0]][i[1] + 1], color, img);
			}
			if (i[0] < (long)(env->lines - 1))
			{
				draw2(1, color, map, i);
				draw_line(proj[i[0]][i[1]], proj[i[0] + 1][i[1]], color, img);
			}
		}
	}
	free_vect(color);
}
