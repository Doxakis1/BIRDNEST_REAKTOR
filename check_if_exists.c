#include "birdnest.h"

int	check_if_exists(t_entry *offenders_list, t_entry offender)
{
	int i;

	i  = 0;
	while ( i <= 1000)
	{
		if(check_for_match(offenders_list[i].SerialNumber, offender.SerialNumber)) //checks if a log exists already for the serialNumber
				return (i);
		i++;
	}
	return (-1); //we only reach this if entry is not in our list
}

int check_for_match(char *string1, char *string2)
{
	int i;

	i = 0;
	while (string1[i] && string2[i])
	{
		if(string1[i] == string2[i]) //checks one character at a time if they match
			i++;
		else
			return (0);
	}
	if (string1[i] ==  string2[i]) //this makes sure the strings are 100% identical hence both reached end of line at this point
		return (1);
	return (0);
}