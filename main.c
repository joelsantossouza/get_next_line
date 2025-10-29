#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const int	file = open("test", O_RDONLY);
	char		*line;

	if (file < 0)
	{
		fprintf(stderr, "Cannot open file\n");
		return (1);
	}
	line = get_next_line(file);
	while(line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(file);
	}
	return (0);
}
