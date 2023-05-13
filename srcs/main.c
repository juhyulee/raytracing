/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:44:16 by juhyulee          #+#    #+#             */
/*   Updated: 2023/05/13 20:13:23 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	image;
}t_vars;

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int	key_hook(int keycode, t_vars *vars)
// {
// 	if(keycode == 53)
// 	{
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		exit(0);
// 	}
// 	return (0);
// }

//scene_init에서 temp_init으로 바꿈
//해당 함수 역할은 ft_parse로 이동
// t_scene *scene_init(void)
// {//화면쳐다보는기준으로 위쪽이y, 오른쪽이 x, 뒤쪽 방향으로 z
// 	t_scene	*scene;
// 	t_object	*world;
// 	t_object	*lights;
// 	double		ka;

// 	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
// 		return (NULL);
// 	scene->canvas = canvas(500, 800);
// 	scene->camera = camera(&scene->canvas, vec(0, 0, 6));
// 	world = object(SP, sphere(vec(0, 0, -5), 2), vec(0.5, 0, 0));
// 	oadd(&world, object(SP, sphere(vec(0, -1000, 0), 995), vec(1, 1, 1)));
// 	oadd(&world, object(SP, sphere(vec(4, 0, -5), 2), vec(0, 0.5, 0)));
// 	oadd(&world, object(SP, sphere(vec(0, 1, -5), 3), vec(1, 1, 1)));
// 	//oadd(&world, object(PL, plane(vec(2, 0, -100), vec(0.5, 0, 0.5)), vec(0.2, 0.2, 0.2)));
// 	oadd(&world, object(CY, cylinder(vec(0, 2, -5), vec(0, 0.5, 0.2), 2, 6), vec(0, 0, 0.5)));
// 	scene->world = world;
// 	lights = object(LIGHT_POINT, light_point(vec(0, 0, 5), vec(1, 1, 1), 0.5), vec(0, 0, 0));
// 	scene->light = lights;
// 	ka = 0.1;
// 	scene->ambient = vmuln(vec(1, 1, 1), ka);
// 	return (scene);
// }

//원본 함수에서 바뀐 점 :
//	동적할당 없앰 ->scene은 메인 함수에서 선언
t_scene temp_init(void)
{//화면쳐다보는기준으로 위쪽이y, 오른쪽이 x, 뒤쪽 방향으로 z
	t_scene		scene;
	t_object	*world;
	t_object	*lights;
	double		ka;

	scene.canvas = canvas(500, 800);
	scene.camera = camera(&scene.canvas, vec(0, 0, 6));
	world = object(SP, sphere(vec(-2, 0, -5), 2), vec(0.5, 0, 0));
	oadd(&world, object(SP, sphere(vec(0, -1000, 0), 995), vec(1, 1, 1)));
	oadd(&world, object(SP, sphere(vec(2, 0, -5), 2), vec(0, 0.5, 0)));
	oadd(&world, object(SP, sphere(vec(0, 7, -5), 3), vec(1, 1, 1)));
	//oadd(&world, object(PL, plane(vec(2, 0, -100), vec(0.5, 0, 0.5)), vec(0.2, 0.2, 0.2)));
	oadd(&world, object(CY, cylinder(vec(0, 2, -5), vec(0, 0.5, 0.2), 2, 6), vec(0, 0, 0.5)));
	scene.world = world;
	lights = object(LIGHT_POINT, light_point(vec(0, 0, 5), vec(1, 1, 1), 0.5), vec(0, 0, 0));
	scene.light = lights;
	ka = 0.1;
	scene.ambient = vmuln(vec(1, 1, 1), ka);
	return (scene);
}

// int	main(void)
// {
//     int     i;
//     int     j;
//     double  u;
//     double  v;

// 	t_vars	vars;
// 	t_data	image;

// 	t_color	pixel_color;
// 	t_scene		*scene;

// 	scene = scene_init();

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, scene->canvas.width, scene->canvas.height, "Hello miniRT!");
// 	image.img = mlx_new_image(vars.mlx, scene->canvas.width, scene->canvas.height); // 이미지 객체 생성
// 	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,\
// 	 &image.line_length, &image.endian);

//  j = scene->canvas.height - 1;
//     while (j >= 0)
//     {
//         i = 0;
//         while (i < scene->canvas.width)
//         {
//             u = (double)i / (scene->canvas.width - 1);
//             v = (double)j / (scene->canvas.height - 1);
// 			scene->ray = ray_primary(&scene->camera, u, v);
// 			pixel_color = ray_color(scene);
//             my_mlx_pixel_put(&image, i, scene->canvas.height - 1 - j, \
// 			create_trgb(0, pixel_color.x * 255.999, pixel_color.y * 255.999, pixel_color.z * 255.999));
//         ++i;
//         }
//     --j;
//     }
// 	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
//     return (0);
// }

// 랜더링
// P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
void	draw(t_scene *scene, t_mlx *mlx)
{
	int i;
	int j;
	double u;
	double v;
	t_color pixel_color;

	j = scene->canvas.height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < scene->canvas.width)
        {
            u = (double)i / (scene->canvas.width - 1);
            v = (double)j / (scene->canvas.height - 1);
			scene->ray = ray_primary(&scene->camera, u, v);
			pixel_color = ray_color(scene);
            my_mlx_pixel_put(&mlx->img, i, scene->canvas.height - 1 - j, \
			create_trgb(0, pixel_color.x * 255.999, pixel_color.y * 255.999, pixel_color.z * 255.999));
        ++i;
        }
    --j;
    }
}


// void	ft_init_mlx(t_mlx *mlx, t_scene *scene, t_data *image)
// {
// 	mlx->mlx = mlx_init();
// 	mlx->win = mlx_new_window(mlx->mlx, scene->canvas_width, scene->canvas_height, "raytracer");
// 	image->img = mlx_new_image(mlx->mlx, scene->canvas_width, scene->canvas_height); //이미지 객체 생성
// 	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,\
// 	 &image->line_length, &image->endian);
// }

void	exit_error(int code)
{
	if (code == 1)
	{
		printf("no file input\n");
	}
	else if (code == 2)
		printf("too many arguments\n");
	else if (code == 3)
		printf("cannot open file\n");

	exit(1);
}

int file_check(int ac, char **av)
{
	// int 	fd;
	// if (ac != 2)
	// {
	// 	exit_error(1);
	// }
	// fd = open(av[1], O_RDONLY);
	// if (fd == -1)
	// {
	// 	exit_error(2);
	// }
	// return (fd);
	
	av[ac - 1] = 0;
	printf("not doing input file right now\n");
	return (1);
}

//controling key in keyboard
int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
		printf("W\n");
	else if (keycode == 1)
		printf("S\n");
	else if (keycode == 0)
		printf("A\n");
	else if (keycode == 2)
		printf("D\n");
	else if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}



// //norminated version
int	main(int ac, char **av)
{
	int		fd;
	t_scene	scene;
	t_mlx	mlx;
	t_data	image;
	
	fd = file_check(ac, av);
	// scene = ft_parse(fd);
	scene = temp_init();
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, scene.canvas_width, scene.canvas_height, "Hello miniRT!");
	image.img = mlx_new_image(mlx.mlx, scene.canvas_width, scene.canvas_height); // 이미지 객체 생성
	mlx.addr = mlx_get_data_addr(mlx.img, &image.bpp,\
	 &mlx.line_length, &mlx.endian);
	// ft_init_mlx(&vars.mlx, &scene, &image);
	draw(&scene);
	mlx_key_hook(&mlx.win, &key_press, &mlx.mlx);
	mlx_loop(&mlx.mlx);
	return (0);
}