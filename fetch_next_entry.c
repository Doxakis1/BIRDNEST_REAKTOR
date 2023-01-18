#include "birdnest.h"

int	fetch_next_entry(t_entry *entry, int fd)
{
	char	buffer[100]; //we use this buffer to read into all the lines we do not need (gets deleted on-exit)
	int		a = 0;
	
	if(!(get_next_line(fd, 100, buffer)))
		return (0);
	if(!(get_next_line(fd, 100, entry->SerialNumber))) //getting the serialNumber
		return (0);
	while(a < 6) //skips lines not needed
	{
		if(!(get_next_line(fd, 100, buffer)))
			return (0);
		a++;
	}
	if(!(get_next_line(fd, 100, entry->ycord))) //getting the ycoordinate
		return (0);
	if(!(get_next_line(fd, 100, entry->xcord)))//getting the xcoordinate
		return (0);
	entry->distance = distance_calc(my_atol(&entry->ycord[17]), my_atol(&entry->xcord[17])); //calculate the distance
	while(a < 8) //skips lines not needed
	{
		if(!(get_next_line(fd, 100, buffer)))
			return (0);
		a++;
	}
	entry->status = 1;
	return (1);
}
