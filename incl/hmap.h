#ifndef MATRIX_H
# define MATRIX_H
# include <libft.h>

typedef struct s_hmap_dim
{
	size_t	width;
	size_t	height;
}	t_hmap_dim;

typedef struct s_hmap
{
	size_t			width;
	size_t			height;
	int				**z_matrix;
	int				**c_matrix;
	int 			min_h;
	int 			max_h;
	t_hmap_dim		*counter;

}	t_hmap;

t_hmap	*new_hmap(t_hmap_dim *dimensions);
t_hmap 	*init_hmap(t_hmap *self, size_t width, size_t height);
void	*free_hmap(t_hmap *self);

int		get_color_height(int height, t_hmap *ref);

void	reset_counter(t_hmap_dim *self);

#endif //MATRIX_H
