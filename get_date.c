#include "birdnest.h"

int	get_date(int fd, char *date)
{
	int		skip_lines;
	char	discard[100];

	skip_lines = 0;
	while( skip_lines < 8) //skips first 8 lines
	{
		if(!(get_next_line(fd, 100, discard)))
			return (0);
		skip_lines++;
	}
	read(fd, discard, 30);
	read(fd, date, 25); 
	date[24] = '\n';
	read(fd, discard, 13); 
	return (1);
}