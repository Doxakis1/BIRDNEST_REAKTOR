#include "birdnest.h"


long	distance_calc(long	ycoodinate, long xcoodinate)
{
	long	distance;
	distance = sqrt(pow((ycoodinate - BIRDNEST_COORDINATES),2) + pow((xcoodinate - BIRDNEST_COORDINATES),2));

	return (distance);
}