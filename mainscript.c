#include "birdnest.h"

int	main(void)
{
	
	t_entry	offenders[ENTRY_AMOUNT];
	t_entry	current;
	char		date[25];
	int			counter = 0;
	int			log_file = 0;
	int			data_file = 0;

	while(counter < ENTRY_AMOUNT)
		my_bzero(&offenders[counter++], sizeof(t_entry));
	while (1)
	{
		my_bzero(&current, sizeof(t_entry));
		system("curl assignments.reaktor.com/birdnest/drones > got_data");
		data_file = open("got_data", O_RDONLY);
		system("cat /dev/null > logfile");
		log_file = open("logfile", O_WRONLY);
		get_date(data_file, &date[0]);

		while (fetch_next_entry(&current, data_file))
		{
			
			counter = 0;
			if (current.distance <= VIOLATION_DISTANCE)
			{
				get_details(&current);
				counter = check_if_exists(offenders, current);
				if(counter == -1) 
				{			
					counter = 0;
					while (counter <= ENTRY_AMOUNT && offenders[counter].status != 0)
					{
						counter++;
					}
					my_bzero(&offenders[counter], sizeof(t_entry));
					offenders[counter] = current;
				}
				else
				{
					if (offenders[counter].distance > current.distance)
					{
						my_bzero(&offenders[counter], sizeof(t_entry));
						offenders[counter] = current;
					}
					else
						offenders[counter].last_seen = -1;
				}
				store_details(&offenders[counter]);
			}
		}
		counter = 0;
		sort_by_time(offenders);
		write(log_file, "<h1 class=\"timestamp\">Last update: ", 35);
		write(log_file, date, 24);
		write(log_file, "</h1>\n", 6);
		while(counter < ENTRY_AMOUNT)
		{
			if (offenders[counter].status == 1)
			{
				offenders[counter].last_seen++;
				if (offenders[counter].last_seen <= TEN_MINUTES)
					log_offender(&offenders[counter], log_file);
				else
					offenders[counter].status = 0;
			}
			counter++;
		}
		close(log_file);
		close(data_file);
		usleep(REFRESH_RATE);
	}	
	
	return 0;
}
