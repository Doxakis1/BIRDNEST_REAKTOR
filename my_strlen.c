#include "birdnest.h"

size_t	my_strlen(const char *s)
{
	int	length;

	length = 0;
	while (*(s++))
		length++;
	return (length);
}
