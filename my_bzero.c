#include "birdnest.h"

void	my_bzero(void *a, size_t b)
{
	size_t	i;
	char	*pointer;

	i = 0;
	pointer = (char *)a;
	while (i < b)
	{
		pointer[i] = 0;
		i++;
	}
}
