#include "maps.h"

void err_msg(int err_status)
{
    printf("ERROR: ");
    if(err_status == 2)
        printf("this file don't exist\n");
    else if(err_status == 3)
        printf("the file must have a .cub extension\n");
    else if(err_status == 4)
        printf("allocation memory error\n");
    else if(err_status == 5)
        printf("texture coordinate error\n");
    else if(err_status == 6)
        printf("color info error\n");
    else if(err_status == 7)
        printf("color: id element error\n");
    else if(err_status == 8)
        printf("parse map error\n");
}
