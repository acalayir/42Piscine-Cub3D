/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalayir <acalayir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:28:22 by acalayir          #+#    #+#             */
/*   Updated: 2022/10/06 18:56:14 by acalayir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "key.h"

static int	mouse_rotate(int x, int y, t_scene *scene)
{
	scene->camera.rotation.z -= (x - scene->mouse.x) * 0.1;
	scene->camera.rotation.y += (y - scene->mouse.y) * 0.1;
	scene->mouse.x = x;
	scene->mouse.y = y;
	matrix_new(scene->matrix);
	matrix_rotate(scene->matrix, scene->camera.rotation);
	draw(*scene);
	return (0);
}

int	mouse_pressed(int key, int x, int y, t_scene *scene)
{
	scene->mouse.x = x;
	scene->mouse.y = y;
	if (key == MOUSE_CLICK_LEFT)
	{
		mlx_hook(scene->mlx.win, 6, 0, mouse_rotate, scene);
	}
	return (0);
}

int	mouse_released(int key, int x, int y, t_scene *scene)
{
	(void)key;
	(void)x;
	(void)y;
	mlx_hook(scene->mlx.win, 6, 0, NULL, NULL);
	return (0);
}
