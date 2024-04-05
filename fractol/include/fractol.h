/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhebert <zhebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:58:41 by zhebert           #+#    #+#             */
/*   Updated: 2024/02/18 17:17:31 by zhebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42.h"
# include <math.h>
# include <pthread.h>
# include <stdlib.h>

# define SIZE 1000
# define THREAD_WIDTH 7
# define THREAD_NUMBER 100

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;

// utils.c
void		put_color_to_pixel(t_fractal *fractal, int x, int y, int colour);
void		exit_fractal(void *param);
double		generate_random_c(void);
void		change_iterations_increase(t_fractal *fractal);
void		change_iterations_reduce(t_fractal *fractal);

// init.c
void		init_fractal(t_fractal *fractal);
void		init_mlx(t_fractal *fractal);

// mandelbrot.c
void		calculate_mandelbrot(t_fractal *fractal);

// julia.c
void		calculate_julia(t_fractal *fractal);

// burning_ship.c
void		calculate_burning_ship(t_fractal *fractal);

// main.c
int			draw_fractal(t_fractal *fractal, char *query);

// mouse_and_keys.c
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		scrollhook(double xdelta, double ydelta, void *param);

// draw.c
void		*draw_mandelbrot(void *fractal_void);
void		draw_julia(t_fractal *fractal);
void		draw_burning_ship(t_fractal *fractal);

// libft
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putendl_fd(char *s, int fd);

#endif