#include "matrix.h"
#include "vector.h"
void 		add_elem(void *self, void *other)
{
	t_vector	*s;
	t_vector	*o;
	size_t		i;

	s = self;
	o = other;
	if (s->dim == o->dim)
	{
		i = 0;
		while (i < s->dim)
		{
			s->coord[i] += o->coord[i];
			++i;
		}
	}
}

void 		mult_elem(void *self, void *other)
{
	t_vector	*s;
	t_vector	*o;
	size_t		i;

	s = self;
	o = other;
	if (s->dim == o->dim)
	{
		i = 0;
		while (i < s->dim)
		{
			s->coord[i] *= o->coord[i];
			++i;
		}
	}
}

void 		print_matrix(t_matrix *self)
{
	size_t		j;
	size_t		i;
	size_t		k;
	t_vector	*e;

	if (self)
	{
		j = 0;
		printf("[");
		while (j < self->cols)
		{
			printf("[");
			i = 0;
			while (i < self->rows)
			{
				e = self->m[j][i];
				k = 0;
				printf("(");
				while (k < e->dim)
				{
					printf("%.2f", e->coord[k]);
					if (k != e->dim - 1)
						printf(", ");
					++k;
				}
				printf(")");
				++i;
				if (i != self->rows)
					printf(", ");
			}
			printf("]");
			++j;
			if (j != self->cols)
				printf("\n");
		}
		printf("]\n");
	}
}