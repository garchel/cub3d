#ifndef MACROS_H

# define MACROS_H
# include <math.h>

# define TRUE 0
# define FALSE 1
# define TOP 0x77
# define DOWN 0x73
# define LEFT 0x61
# define RIGHT 0x64
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ESC 0xff1b
# define TILE 64
# define BLACK 16777216
# define REDMLX 0x00FF0000
# define WHITE 0xFFFAFA
# define GREEN 0x8EF5BF
# define GREY  0xA0A0A0 
# define BLUEMLX 0x0000FF

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define NUM_TEXTURES 4

# define WIDTH 1200
# define HEIGHT 800

# define TEXTURE_WIDTH TILE
# define TEXTURE_HEIGHT TILE

# define PI 3.14159265
# define TWO_PI 6.28318530
# define NUM_RAYS WIDTH

#define FOV_ANGLE (60 * (double) (PI / 180))

#endif