/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalayir <acalayir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:10:53 by acalayir          #+#    #+#             */
/*   Updated: 2022/10/08 14:10:43 by acalayir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec2	vec2_new(float x, float y)
{
	t_vec2	new;

	new.x = x;
	new.y = y;
	return (new);
}

t_vec3	vec3_sub(t_vec3 a, t_vec3 b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_vec3	vec3_subv(t_vec3 a, float value)
{
	a.x -= value;
	a.y -= value;
	a.z -= value;
	return (a);
}

t_vec3	reflect(t_vec3 rd, t_vec3 n)
{
	return (vec3_sub(rd, vec3_mulv(vec3_mulv(n, vec3_dot(n, rd)), 2.0)));
}

float	maxf(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
 
t_vec3	vec3_add(t_vec3 a, t_vec3 b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}


float	vec3_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec2	draw_sphere(t_vec3 ro, t_vec3 rd, float ra)
{
	float	b;
	float	c;
	float	h;

	b = vec3_dot(ro, rd);
	c = vec3_dot(ro, ro) - ra * ra;
	h = b * b - c;
	if (h < 0.0)
	{
		return (vec2_new(-1.0, 0.0));
	}
	else
	{
		h = sqrt(h);
		return (vec2_new(-b - h, -b + h));
	}
}