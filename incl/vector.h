/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stddef.h>
# include <stdlib.h>
# include <math.h>
# include <libft.h>

typedef struct s_vector
{
	size_t	dim;
	double	*coord;
}	t_vector;

t_vector	*new_3vect(double x, double y, double z);
t_vector	*new_2vect(double x, double y);
void		free_vect(t_vector *self);
double		get_norm(t_vector *self);
void		add_vect(t_vector *self, t_vector *other);
void		sbstr_vect(t_vector *self, t_vector *other);
void		mult_vect(t_vector *self, double scalar);
double		dot_vect(t_vector *self, t_vector *other);
double		cross_2vect(t_vector *self, t_vector *other);
t_vector	*cross_3vect(t_vector *self, t_vector *other);
#endif //VECTOR_H
