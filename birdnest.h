#ifndef BIRDNEST_H
# define BIRDNEST_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>


# ifndef BIRDNEST_COORDINATES
#  define BIRDNEST_COORDINATES 250000
# endif

# ifndef TEN_MINUTES
#  define TEN_MINUTES 333
# endif

# ifndef ENTRY_AMOUNT
#  define ENTRY_AMOUNT 2000
# endif

# ifndef VIOLATION_DISTANCE
#  define VIOLATION_DISTANCE 100000
# endif

# ifndef REFRESH_RATE
#  define REFRESH_RATE 1800000
# endif

typedef	struct s_entry{
	int		status;
	int		last_seen;
	char	SerialNumber[100];
	char	ycord[50];
	char	xcord[50];
	char	details[300];
	long	distance;
}	t_entry;

//check_if_exists.c
int	check_if_exists(t_entry *offenders_list, t_entry offender);
int check_for_match(char *string1, char *string2);

//distance_calc.c
long	distance_calc(long	ycoodinate, long xcoodinate);

//file_parsing_functions.c
int write_without_tag(char *str, int fd);
int get_next_line(int fd, int max_size, char *dest);

//get_date.c
int	get_date(int fd, char *date);

//get_details.c
int get_details(t_entry *offender);
int	store_details(t_entry *offender);
int copy_into_location(char *str, char *dest);

//fetch_next_entry
int	fetch_next_entry(t_entry *entry, int fd);

//log_offender
int	log_offender(t_entry *offender, int fd);

//mainscript.c 
int	main(void);

//my_atol.c
long my_atol(const char *str);

//my_bzero.c
void	my_bzero(void *a, size_t b);

//my_strlen.c
size_t	my_strlen(const char *s);

//print_distance.c
int	print_distance(long n, int fd);

//sort_by_time.c
int	sort_by_time(t_entry *offenders);

#endif