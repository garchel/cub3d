#include <stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../gnl/get_next_line.c"
#include "../../gnl/get_next_line.h"
#include "../../gnl/get_next_line_utils.c"



int main()
{
	char	*line;
	int		i;
	int		fd1;
	fd1 = open("files_copy/lotr", O_RDONLY);
	i = 0;
	while (i < 9)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return 0;
}