#include "birdnest.h"


int get_details(t_entry *offender)
{
	char	*start = "curl assignments.reaktor.com/birdnest/pilots/";
	char	*end = " > entry_details";
	char	command[120];
	//enough to hold the command for the information, the reason why I decided to hand write the \0 is to guarantee that the compiler allocates them correctly from the get go
	int 	i;
	int		j;

	i = 0;
	j = 0;
	my_bzero(command, 120);
	system("cat /dev/null > entry_details");
	while(start[i]) //copying the first part of the link into the buffer;
		{
			command[i] = start[i];
			if(start[i++] == '\n')
				break ;
		}
	
	while(offender->SerialNumber[j] != '\0')//copying the start of the command string
		if(offender->SerialNumber[j++] == '>')
			break ;
	while(offender->SerialNumber[j] != '\0')//copying the middle of the command string
		{
			if(offender->SerialNumber[j] == '<')
				break ;
			else
			{
				command[i] = offender->SerialNumber[j];
			}
			i++;
			j++;
		}
	j = 0;
	while(end[j] != '\0')
		{
			command[i] = end[j];
			i++;
			j++;
		}
	command[i] = '\0';
	system(command);
	
	return 0;
}

int	store_details(t_entry *offender) //I could have cut this code down a little bit but I honestly think it is better to do it in one function to not lose track(?maybe)
{
	char 	buff[1];
	int		readbytes;
	int	fd = open("entry_details", O_RDONLY);
	int	detailIndex; //We only want details "firstName","lastName", "phoneNumber" and "email", hence we want only want to read between quatations 7-8,11-12,15-16 and 23-24
	int	i;
	int got_details;

	i = 0;
	got_details = 0;
	detailIndex = 0;
	readbytes = read(fd, buff, 1);
	my_bzero(offender->details, 300);
	if(readbytes)
	{
		i += copy_into_location("<br>Offenders name: <b>", &offender->details[0]);
		while(readbytes) //Copying the name starts here
		{
			if(buff[0] == '"')
				detailIndex++;
			readbytes = read(fd, buff, 1);
			if(detailIndex == 7)
				break ;
		}
		while(readbytes)
		{
			if(buff[0] == '"')
			{
				detailIndex++;
				offender->details[i++] = ' ';
				readbytes = read(fd, buff, 1);
				break ;
			}
			else
			{
				offender->details[i++] = buff[0];
				readbytes = read(fd, buff, 1);
			}
				
		} //copied the first name
		while(readbytes) //Going for the surname
		{
			if(buff[0] == '"')
				detailIndex++;
			readbytes = read(fd, buff, 1);
			if(detailIndex == 11)
				break ;
		}
		while(readbytes)
		{
			if(buff[0] == '"')
			{
				detailIndex++;
				readbytes = read(fd, buff, 1);
				got_details++;
				break ;
			}
			else
			{
				offender->details[i++] = buff[0];
				readbytes = read(fd, buff, 1);
			}
				
		} //copied the whole name
		i += copy_into_location("</b><br>Offenders phonenumber: <b>", &offender->details[i]);
		while(readbytes) //Copying the phonenumber starts here
		{
			if(buff[0] == '"')
				detailIndex++;
			readbytes = read(fd, buff, 1);
			if(detailIndex == 15)
				break ;
		}
		while(readbytes) 
		{
			if(buff[0] == '"')
			{
				detailIndex++;
				readbytes = read(fd, buff, 1);
				got_details++;
				break ;
			}
			else
			{
				offender->details[i++] = buff[0];
				readbytes = read(fd, buff, 1);
			}
				
		} //copied the phonenumber
		i += copy_into_location("</b><br>Offenders email: <b>", &offender->details[i]);
		while(readbytes) //Copying the email starts here
		{
			if(buff[0] == '"')
				detailIndex++;
			readbytes = read(fd, buff, 1);
			if(detailIndex == 23)
				break ;
		}
		while(readbytes) 
		{
			if(buff[0] == '"')
			{
				detailIndex++;
				readbytes = read(fd, buff, 1);
				got_details++;
				break ;
			}
			else
			{
				offender->details[i++] = buff[0];
				readbytes = read(fd, buff, 1);
			}
				
		} //copied the email
		i += copy_into_location("</b><br>", &offender->details[i]);
	}
	if (got_details < 3)//means we did not copy eveyrthing we wanted
		i += copy_into_location("Sadly no details for user :c", &offender->details[i]);
	offender->details[i++] = '\n';
	offender->details[i] = '\0';
	close(fd);

	return (1);
}

int copy_into_location(char *str, char *dest) //I love this function, small
{
	int i;
	i = 0;
	while(str[i] && str[i] != '\0')
		{
			*(dest++) = str[i];
			i++;
		}
	return (i);
}