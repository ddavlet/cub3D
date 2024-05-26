#include "../cub3d.h"

int32_t check_pix(t_float_pixel pix)
{
	if (pix.x < 0 || pix.y < 0 || pix.x > WINDOW_WIDTH - 1 || pix.y > WINDOW_HEIGHT -1)
	{
		ft_putendl_fd("Warning\nInvalid pixel", 2);
		return (0);
	}
	else
		return(1);
}

int32_t ft_float_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
