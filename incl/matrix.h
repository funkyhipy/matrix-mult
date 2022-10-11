#ifndef MATRIX_MULT_MATRIX_H
# define MATRIX_MULT_MATRIX_H
# include <stdio.h>
# include <stdlib.h>

//this implementation works for matrices of int
typedef struct
{
	size_t	rows;
	size_t	cols;
	void	***m;
} t_matrix;

/*
 * Declarations
 */
t_matrix	*new_matrix(size_t rows, size_t cols);
t_matrix	*cpy_matrix(t_matrix *other);
void 		set_matrix_elem(t_matrix *self, void *elem, size_t x, size_t y);
void 		free_matrix(t_matrix *self, void (*f)(void*));

/*
 * Operators
 * t_matrix	*do_op(t_matrix *A, t_matrix *B);
 */
t_matrix	*mult_matrix(t_matrix *A, t_matrix *B);

/*
 * Elements Functions
 */
void 		*cpy_elem(void *elem);
void 		*new_elem();
void 		add_elem(void *self, void *other);
void 		mult_elem(void *self, void *other);
void 		free_elem(void *self);

/*
 * Helper
 */
void 		print_matrix(t_matrix *self);

#endif //MATRIX_MULT_MATRIX_H
