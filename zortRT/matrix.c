/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalayir <acalayir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:46:44 by acalayir          #+#    #+#             */
/*   Updated: 2022/10/06 19:23:58 by acalayir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	matrix_copy(t_mat matrix, t_mat b)
{
	matrix_column(matrix[0], b[0][0], b[0][1], b[0][2]);
	matrix_column(matrix[1], b[1][0], b[1][1], b[1][2]);
	matrix_column(matrix[2], b[2][0], b[2][1], b[2][2]);
}

void	matrix_multiply(t_mat matrix, t_mat b)
{
	t_mat	a;

	matrix_copy(a, matrix);
	matrix[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0] + a[0][2] * b[2][0];
	matrix[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1] + a[0][2] * b[2][1];
	matrix[0][2] = a[0][0] * b[0][2] + a[0][1] * b[1][2] + a[0][2] * b[2][2];
	matrix[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0] + a[1][2] * b[2][0];
	matrix[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1] + a[1][2] * b[2][1];
	matrix[1][2] = a[1][0] * b[0][2] + a[1][1] * b[1][2] + a[1][2] * b[2][2];
	matrix[2][0] = a[2][0] * b[0][0] + a[2][1] * b[1][0] + a[2][2] * b[2][0];
	matrix[2][1] = a[2][0] * b[0][1] + a[2][1] * b[1][1] + a[2][2] * b[2][1];
	matrix[2][2] = a[2][0] * b[0][2] + a[2][1] * b[1][2] + a[2][2] * b[2][2];
}

void	matrix_rotate_x(t_mat matrix, float angle)
{
	float	a;
	t_mat	rotate;

	a = M_PI / 180 * angle;
	matrix_column(rotate[0], 1.0, 0.0, 0.0);
	matrix_column(rotate[1], 0.0, +cosf(a), +sinf(a));
	matrix_column(rotate[2], 0.0, -sinf(a), +cosf(a));
	matrix_multiply(matrix, rotate);
}

void	matrix_rotate_y(t_mat matrix, float angle)
{
	float	a;
	t_mat	rotate;

	a = M_PI / 180 * angle;
	matrix_column(rotate[0], cosf(a), 0.0, -sinf(a));
	matrix_column(rotate[1], 0.0, 1.0, 0.0);
	matrix_column(rotate[2], +sinf(a), 0.0, +cosf(a));
	matrix_multiply(matrix, rotate);
}

void	matrix_rotate_z(t_mat matrix, float angle)
{
	float	a;
	t_mat	rotate;

	a = M_PI / 180 * angle;
	matrix_column(rotate[0], +cosf(a), +sinf(a), 0.0);
	matrix_column(rotate[1], -sinf(a), +cosf(a), 0.0);
	matrix_column(rotate[2], 0.0, 0.0, 1.0);
	matrix_multiply(matrix, rotate);
}

void    matrix_rotate(t_mat matrix, t_vec3 angle)
{
    matrix_rotate_x(matrix, angle.x);
    matrix_rotate_y(matrix, angle.y);
    matrix_rotate_z(matrix, angle.z);
}

void    matrix_column(t_col column, float x1, float y1, float z1)
{
    column[0] = x1;
    column[1] = y1;
    column[2] = z1;
}

void    matrix_new(t_mat matrix)
{
    matrix_column(matrix[0], 1.0, 0.0, 0.0);
    matrix_column(matrix[1], 0.0, 1.0, 0.0);
    matrix_column(matrix[2], 0.0, 0.0, 1.0);
}
