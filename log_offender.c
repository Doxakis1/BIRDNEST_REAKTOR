#include "birdnest.h"

int	log_offender(t_entry *offender, int fd)
{
	write(fd, "<br><table class=\"offender\"><tr><th>Offenders device SerialNumber: ", 66);
	write_without_tag(offender->SerialNumber, fd);
	write(fd, "</tr></th><tr><td>Offenders closest recorded distance: <b>", 58);
	print_distance(offender->distance, fd);
	write(fd, "</b></td></tr><tr><td>Offenders details <button onclick=\"copyContents(this)\">Copy this data</button>", 100);
	write(fd, offender->details, strlen(offender->details));
	write(fd, "</td></tr></table>\n", 19);

	return 1;
}