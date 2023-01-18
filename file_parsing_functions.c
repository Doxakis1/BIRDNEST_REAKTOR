#include "birdnest.h"

int write_without_tag(char *str, int fd)
{
	int		k;
	int		i;

	write(fd, "\t", 1);
	k = 0;
	i = 0;
	while( str[i]) //finding starting point
		{
			if (str[i++] == '>')
				break ;
		}
	while( str[i + k] && str[i + k] != '<') //finding ending point
		{
			k++;
		}
	if (k == 0) //if there were no tags
	{	
		k = i;
		i = 0;
	}
	write(fd, &str[i], k); //writing the line
	write(fd, "\n", 1); //putting a newline
	
	return (1);
}

int get_next_line(int fd, int max_size, char *dest)
{
	char	buffer[1];
	int		read_bytes = 0;
	int		k = 0;

	read_bytes = read(fd, buffer, 1);
	while (buffer[0] != '\n' && buffer[0] != '}')//copying into destination starts here
	{
		if (read_bytes == 0 || k == max_size - 2) //checking if file ended abruptly or we ran out of buffer space
			return (0);
		dest[k++] = buffer[0];
		read_bytes = read(fd, buffer, 1);
	}
	dest[k++] = '\n';
	dest[k] = '\0'; // copying into destination ends here
	return (1);
}