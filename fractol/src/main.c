/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhebert <zhebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:35:41 by zhebert           #+#    #+#             */
/*   Updated: 2024/02/22 18:48:55 by zhebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "../include/fractol.h"
#include <MLX42.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief    Iterates through the pixels of the window and calls the
 * appropriate function to draw the fractal.
 *
 * @param    fractal   The fractal structure.
 * @param    query     The name of the fractal to draw.
 */
int	draw_fractal(t_fractal *fractal, char *query)
{
	if (ft_strncmp(query, "mandel", 7) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp(query, "julia", 6) == 0)
	{
		if (!fractal->cx && !fractal->cy)
		{
			fractal->cx = -0.745429;
			fractal->cy = 0.05;
		}
		draw_julia(fractal);
	}
	else if (ft_strncmp(query, "ship", 5) == 0)
		draw_burning_ship(fractal);
	else
	{
		ft_putendl_fd("Available fractals: mandel, julia, ship", 1);
		exit_fractal(fractal);
	}
	mlx_image_to_window(fractal->mlx, fractal->image, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./fractol <fractal>", 1);
		ft_putendl_fd("Available fractals: mandelbrot, julia, ship", 1);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->mlx, &my_keyhook, fractal);
	mlx_scroll_hook(fractal->mlx, &scrollhook, fractal);
	mlx_close_hook(fractal->mlx, &exit_fractal, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
