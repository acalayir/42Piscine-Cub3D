
#ifndef MINIRT_H
# define MINIRT_H

# define TRUE	1
# define FALSE	0

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "mlx/mlx.h"

// # define WIDTH	1920
// # define HEIGHT	1080

# define WIDTH	1080
# define HEIGHT	720

// # define WIDTH	500
// # define HEIGHT	500

typedef float	t_col[3];
typedef t_col	t_mat[3];

typedef struct s_vec2
{
	float	x;
	float	y;
} t_vec2;

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
} t_vec3;

struct s_obj
{
	t_vec3	location;
	t_vec3	rotation;
};

struct s_view
{
	char	*buffer;
	int		pixel;
	int		line;
	int		endian;
};

struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*canvas;
};

struct s_scene
{
	struct s_view	view;
	struct s_mlx	mlx;
	struct s_obj	camera;
	struct s_vec2	mouse;
	t_mat			matrix;
	float			focus;
	float			fov;
};

typedef struct s_obj	t_obj;
typedef struct s_view	t_view;
typedef struct s_mlx	t_mlx;
typedef struct s_scene	t_scene;
typedef int	t_bool;
typedef struct s_vec2	t_vec2;
typedef struct s_vec3	t_vec3;


void	draw(t_scene scene);
void	event(t_scene *scene);
int		key_pressed(int key, t_scene *scene);
void	minirt(char *path);
t_scene	parser(char *path);
int		terminate(t_scene *scene);
void	matrix_rotate(t_mat matrix, t_vec3 angle);
float	maxf(float a, float b);
t_vec3	vec3_mulmat(t_vec3 vec, t_mat matrix);
t_vec3	vec3_mulmat_xy(t_vec3 vec, t_mat matrix);
int		mouse_pressed(int key, int x, int y, t_scene *scene);
int		mouse_released(int key, int x, int y, t_scene *scene);
void	matrix_column(t_col column, float a1, float a2, float a3);
void	matrix_copy(t_mat matrix, t_mat b);
void	matrix_multiply(t_mat matrix, t_mat b);
void	matrix_new(t_mat matrix);
void	matrix_print(t_mat matrix);
void	matrix_rotate_x(t_mat matrix, float angle);
void	matrix_rotate_y(t_mat matrix, float angle);
void	matrix_rotate_z(t_mat matrix, float angle);
t_vec2	vec2_new(float x, float y);
void	vec2_print(char *name, t_vec2 vector);
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
float	vec3_dot(t_vec3 a, t_vec3 b);
float	vec3_len(t_vec3 vec);
t_vec3	vec3_mulv(t_vec3 vec, float value);
t_vec3	vec3_mul(t_vec3 a, t_vec3 b);	
t_vec3	vec3_newv(float value);
t_vec3	vec3_new(float x, float y, float z);
t_vec3	vec3_normalize(t_vec3 vec);
void	vec3_print(char *name, t_vec3 vector);
t_vec3	vec3_subv(t_vec3 a, float value);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	reflect(t_vec3 rd, t_vec3 n);
t_vec2	draw_sphere(t_vec3 ro, t_vec3 rd, float ra);
void	write_pixel(t_view view, t_vec2 pixel, t_vec3 col);



#endif 
