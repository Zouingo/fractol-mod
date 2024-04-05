/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhebert <zhebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:56:26 by zhebert           #+#    #+#             */
/*   Updated: 2024/02/12 18:08:38 by zhebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFCBE11;
	fractal->zoom = 300;
	fractal->offset_x = -1.21;
	fractal->offset_y = -1.21;
	fractal->max_iterations = 42;
}

/**
 * @brief    Initializes the MiniLibX variables.
 *
 * @param    fractal
 */
void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init(SIZE, SIZE, "fract-ol", true);
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	mlx_image_to_window(fractal->mlx, fractal->image, 0, 0);
}
