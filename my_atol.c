#include "birdnest.h"

long my_atol(const char *str)
{
	long	final;
	long	sign;
	long	i;

	final = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			final = final * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	return (sign * final);
}