#include "cub3d.h"

void error_message(char *msg)
{
    printf("ERROR:");
	perror(msg);
	exit(1);
}
