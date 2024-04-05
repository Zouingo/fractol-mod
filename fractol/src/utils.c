/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhebert <zhebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:52:19 by zhebert           #+#    #+#             */
/*   Updated: 2024/02/22 18:11:09 by zhebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	mlx_put_pixel(fractal->image, x, y, color);
}

void	exit_fractal(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	mlx_close_window(fractal->mlx);
	mlx_terminate(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	exit(1);
}

double	generate_random_c(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

void	change_iterations_reduce(t_fractal *fractal)
{
	if (fractal->max_iterations > 42)
		fractal->max_iterations -= 24;
}

void	change_iterations_increase(t_fractal *fractal)
{
	if (fractal->max_iterations < 4200)
		fractal->max_iterations += 24;
}
