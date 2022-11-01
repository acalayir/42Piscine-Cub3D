/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalayir <acalayir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:21:33 by acalayir          #+#    #+#             */
/*   Updated: 2022/10/08 13:51:41 by acalayir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3  vec3_new(float x, float y, float z)
{
    t_vec3   new;
    new.x = x;
    new.y = y;
    new.z = z;
    return(new);
}

t_mlx   set_mlx(void)
{
    t_mlx   mlx;

    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "CALO ILE HUZURA DOGRU");
    mlx.canvas = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
    return(mlx);
}

t_view set_view(void *canvas)
{
    t_view  view;
    int     pixel;
    int     line;
    int     endian;

    view.buffer = mlx_get_data_addr(canvas, &pixel, &line, &endian);
    view.pixel = pixel;
    view.line = line;
    view.endian = endian;
    return (view);    
}

t_scene parser(char *path)
{
    t_scene scene;

    (void) path;
    scene.mlx = set_mlx();
    scene.view = set_view(scene.mlx.canvas);
    scene.camera.location = vec3_new(-500.0, 0.0, 0.0);
    scene.camera.rotation = vec3_new(0.0, 0.0, 0.0);
    scene.fov = 60.0;
    scene.focus = WIDTH / 2 / tanf(scene.fov / 2 * M_PI / 180);
    matrix_new(scene.matrix);
    matrix_rotate(scene.matrix, scene.camera.rotation);
    return (scene);
}

void    init_map(char *path)
{
    t_scene scene;
    scene = parser(path);
    draw(scene);
    event(&scene);

}

int main(int argc, char **argv)
{
    if (argc == 2)
   {
        init_map(argv[1]);
        return (0);
   }
    else
   return (1);
}