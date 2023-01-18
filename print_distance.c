#include "birdnest.h"

int	print_distance(long n, int fd)
{
	int		counter;
	int		prints;
	char	str[20];
	long	number;

	counter = 0;
	if (n == 100000)
		counter = 8; //7 because  6 digits and '\n' and '\0' (we count from 0)
	if (n < 100000 && n >= 10000)
		counter = 7; //6 because  6 digits and '\n' and '\0' (we count from 0)
	if (n < 10000)
		counter = 6; //5 because  4 digits and '\n' and '\0' (we count from 0)
	prints = counter;
	number = n;
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	if (number == 0)
		str[0] = '0';
	str[counter--] = '\0';
	str[counter--] = '\n';
	while (counter >= 0)
	{
		str[counter--] = number % 10 + '0';
		if(counter == prints - 5) // 5 because '\n' and '\0'
			str[counter--] = '.';
		number = number / 10;
	}
	write(fd, str, prints);
	return (counter);
}