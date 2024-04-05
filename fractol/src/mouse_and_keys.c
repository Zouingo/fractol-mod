/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_and_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhebert <zhebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:12:11 by zhebert           #+#    #+#             */
/*   Updated: 2024/02/18 17:20:45 by zhebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief    Zooms or dezooms the fractal.
 *
 * @param    fractal
 * @param    x         The x coordinate of the mouse.
 * @param    y         The y coordinate of the mouse.
 * @param    zoom      1 for zoom, -1 for dezoom.
 */
void	zoom(t_fractal *fractal, int zoom)
{
	double	zoom_level;
	double	center_x;
	double	center_y;

	zoom_level = 1.42;
	center_x = SIZE / 2.0;
	center_y = SIZE / 2.0;
	if (zoom == 1)
	{
		fractal->offset_x = (center_x / fractal->zoom + fractal->offset_x)
			- (center_x / (fractal->zoom * zoom_level));
		fractal->offset_y = (center_y / fractal->zoom + fractal->offset_y)
			- (center_y / (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (center_x / fractal->zoom + fractal->offset_x)
			- (center_x / (fractal->zoom / zoom_level));
		fractal->offset_y = (center_y / fractal->zoom + fractal->offset_y)
			- (center_y / (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
}

/**
 * @brief    Sets the constants of Julia to random values.
 *
 * @param    cx        A pointer to the cx constant.
 * @param    cy        A pointer to the cy constant.
 */
void	set_random_julia(double *cx, double *cy)
{
	*cx = generate_random_c();
	*cy = generate_random_c();
}

/**
 * @brief    The handler for keyboard events.
 * 				ESC: exit the program.
 * 				LEFT: move the fractal to the left.
 * 				RIGHT: move the fractal to the right.
 * 				UP: move the fractal up.
 * 				DOWN: move the fractal down.
 * 				R: reset the fractal.
 * 				C: change the color scheme.
 * 				J: set the constants of Julia to random values.
 * 				P: increase the max iterations.
 * 				M: reduce the max iterations.
 *
 * @param    keydata
 * @param    fractal
 */

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(1);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fractal->offset_y -= 42 / fractal->zoom;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fractal->offset_y += 42 / fractal->zoom;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fractal->offset_x -= 42 / fractal->zoom;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fractal->offset_x += 42 / fractal->zoom;
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		init_fractal(fractal);
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		set_random_julia(&fractal->cx, &fractal->cx);
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		fractal->color += (255 * 255 * 255) / 100;
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		change_iterations_reduce(fractal);
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		change_iterations_increase(fractal);
	draw_fractal(fractal, fractal->name);
}

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	(void)xdelta;
	if (ydelta > 0)
		zoom(fractal, 1);
	else if (ydelta < 0)
		zoom(fractal, -1);
	draw_fractal(fractal, fractal->name);
}
