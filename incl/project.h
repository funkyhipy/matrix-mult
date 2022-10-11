#ifndef MATRIX_MULT_PROJECT_H
# define MATRIX_MULT_PROJECT_H
# include <vector.h>

typedef enum
{
	ORTHOGONAL,
	ISOMETRIC,
	CONIC
}	t_projection;

typedef struct s_camera
{
	t_projection	projection;
	double			zoom;
	t_vector		*rota;
	t_vector		*shift;
	t_vector		*shift_center;
}	t_camera;

t_vector	*project_vect(t_vector *point, t_camera *camera);
double ft_round(double nb);
void rotate_vect(t_vector *self, t_vector *rota);
void rotate_vect_x(t_vector *self, double teta);
void rotate_vect_y(t_vector *self, double teta);
void rotate_vect_z(t_vector *self, double teta);
void shift_vect(t_vector *self, t_vector *shift);
void zoom_vect(t_vector *self, double zoom);
#endif //MATRIX_MULT_PROJECT_H
