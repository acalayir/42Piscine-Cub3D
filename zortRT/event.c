#include "miniRT.h"
#include "key.h"


int	terminate(t_scene *scene)
{
	(void)scene;
	exit(0);
	return (-1);
}

t_vec3	vec3_mulmat_xy(t_vec3 vec, t_mat matrix)
{
	t_vec3	new;

	new.x = matrix[0][0] * vec.x + matrix[0][1] * vec.y;
	new.y = matrix[1][0] * vec.x + matrix[1][1] * vec.y;
	new.z = vec.z;
	return (new);
}

t_bool	ismovement(int key, t_scene *scene)
{
	t_vec3	vector;

	if (key == KEY_W)
		vector = vec3_new(1.0, 0.0, 0.0);
	else if (key == KEY_A)
		vector = vec3_new(0.0, -1.0, 0.0);
	else if (key == KEY_S)
		vector = vec3_new(-1.0, 0.0, 0.0);
	else if (key == KEY_D)
		vector = vec3_new(0.0, 1.0, 0.0);
	else if (key == KEY_SPASE)
		vector = vec3_new(0.0, 0.0, -1.0);
	else if (key == KEY_Z)
		vector = vec3_new(0.0, 0.0, 1.0);
	else
		return (FALSE);
	vector = vec3_mulmat_xy(vector, scene->matrix);
	vector = vec3_add(scene->camera.location, vec3_mulv(vector, 50.0));
	scene->camera.location = vector;
	return (TRUE);
}

int	key_pressed(int key, t_scene *scene)
{
	if (ismovement(key, scene) == TRUE)
	{
		draw(*scene);
		return (0);
	}
	else if (key == KEY_ESC)
	{
		terminate(scene);
	}
	else
	{
		printf("key: %d\n", key);
		return (0);
	}
	draw(*scene);
	return (0);
}

void	event(t_scene *scene)
{
	t_mlx	mlx;

	mlx = scene->mlx;
	mlx_hook(mlx.win, 2, 0, key_pressed, scene);
	mlx_hook(mlx.win, 4, 0, mouse_pressed, scene);
	mlx_hook(mlx.win, 5, 0, mouse_released, scene);
	mlx_hook(mlx.win, 17, 0, terminate, scene);
	mlx_loop(mlx.mlx);
}