/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalayir <acalayir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:56:55 by acalayir          #+#    #+#             */
/*   Updated: 2022/10/17 10:04:17 by acalayir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3_mulmat(t_vec3 vec, t_mat matrix)
{
	t_vec3	new;

	new.x = matrix[0][0] * vec.x + matrix[0][1] * vec.y + matrix[0][2] * vec.z;
	new.y = matrix[1][0] * vec.x + matrix[1][1] * vec.y + matrix[1][2] * vec.z;
	new.z = matrix[2][0] * vec.x + matrix[2][1] * vec.y + matrix[2][2] * vec.z;
	return (new);
}

t_vec3  vec3_mulv(t_vec3 vec, float value)
{
    vec.x *= value;
    vec.y *= value;
    vec.z *= value;  
    return(vec);
}

float   vec3_len(t_vec3 vec)
{
    return(sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vec3  vec3_normalize(t_vec3 vec)
{
    return (vec3_mulv(vec, 1 / vec3_len(vec)));
}


t_vec3	define_color(t_vec3 ro, t_vec3 rd, t_vec3 pos, t_vec2 it)
{
	t_vec3	light;
	t_vec3	n;
	t_vec3	reflected;
	t_vec3	color;
	float	diffuse;
	float	specular;

	light = vec3_normalize(vec3_new(0.0, -400.0, 0.0));
	n = vec3_normalize(vec3_add(vec3_sub(ro, pos), vec3_mulv(rd, it.x)));
	diffuse = maxf(0.0, vec3_dot(light, n));
	reflected = reflect(vec3_normalize(rd), n);
	specular = powf(maxf(0.0, vec3_dot(reflected, light)), 16.0);
	color = vec3_new(0.2, 0.3, 0.75);
	color = vec3_mulv(color, (diffuse + specular) * 0.5);
	return (color);
}

t_vec3	ray_tracing(t_vec3 ro, t_vec3 rd)
{
	t_vec2	it;

	it = draw_sphere(vec3_sub(ro, vec3_new(500.0, 0.0, 0.0)), rd, 300.0);
	if (it.x < 0.0)
	{
		return (vec3_new(0.15, 0.15, 0.20));
	}
	else
	{
		return (define_color(ro, rd, vec3_new(500, 0.0, 0.0), it));
	}
}

void    draw(t_scene scene)
{
    t_vec2  pixel;
    t_vec3  direction;
    t_vec3  col;

    pixel.y = 0.0;
    while(pixel.y < HEIGHT)
    {
        pixel.x = 0.0;
        while(pixel.x < WIDTH)
        {
            direction = vec3_normalize(vec3_new(scene.focus, pixel.x - WIDTH / 2.0, pixel.y - HEIGHT / 2.0));
            direction = vec3_mulmat(direction, scene.matrix);
            col = ray_tracing(scene.camera.location, direction);
            write_pixel(scene.view, pixel, col);
            pixel.x += 1.0;
        }
        pixel.y += 1.0;
    }
    mlx_put_image_to_window(scene.mlx.mlx, scene.mlx.win, scene.mlx.canvas, 0 ,0);
}

t_vec3	parsing_sphere(t_vec3 *vec, t_vec2 *vec2)
{
	t_vec3
}