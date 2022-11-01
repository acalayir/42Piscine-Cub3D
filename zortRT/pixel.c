/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalayir <acalayir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:17:39 by acalayir          #+#    #+#             */
/*   Updated: 2022/10/06 18:59:35 by acalayir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	vec2_print(char *name, t_vec2 vector)
{
	//printf("\x1b[47m\x1b[1m%14s ", name);
	printf("x: %10.2f ", vector.x);
	//printf("\x1b[0m \x1b[42m \x1b[1m");
	printf("y: %10.2f ", vector.y);
	printf("\x1b[0m\n");
}

void	write_pixel(t_view view, t_vec2 pixel, t_vec3 col)
{
	unsigned char	*buffer;
	int				_pixel;

	if (pixel.x < 0.0 || pixel.x > WIDTH || pixel.y < 0.0 || pixel.y > HEIGHT)
	{
		printf("\x1b[41m\x1b[1m 💥 AMANIN NEREYE GELDİK 💥 \x1b[0m\n");
		vec2_print("pixel", pixel);
		exit(1);
	}
	buffer = (unsigned char *)view.buffer;
	_pixel = (pixel.y * view.line) + (pixel.x * 4);
	buffer[_pixel + 0] = col.z * 255;
	buffer[_pixel + 1] = col.y * 255;
	buffer[_pixel + 2] = col.x * 255;
}