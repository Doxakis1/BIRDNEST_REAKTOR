#include "birdnest.h"

int	sort_by_time(t_entry *offenders) //bubblesorting by time
{
	int i;
	int j;
	t_entry temp;

	i = 0;
	j = 0;
	while(i <= 1000)
	{
		if (offenders[i].status == 1)
			{
				j = i;
				while( j <= 1000)
					{
						if (offenders[j].status == 1 && offenders[i].last_seen > offenders[j].last_seen)
							{
								temp = offenders[i];
								offenders[i] = offenders[j];
								offenders[j] = temp;
							}
						j++;
					}
			}
		i++;
	}
	return (1);
}