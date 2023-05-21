/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:08:11 by juhyulee          #+#    #+#             */
/*   Updated: 2023/05/19 18:17:24 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	ray(t_point orig, t_vec dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

t_point	ray_at(t_ray *ray, double t)
{
	t_point	at;

	at = vadd(ray->orig, vmuln(ray->dir, t));
	return (at);
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.orig = cam->orig;
	ray.dir = vunit(vsub(vadd(vadd(cam->left_bottom,\
	 vmuln(cam->horizontal, u)), vmuln(cam->vertical, v)), cam->orig));
	return (ray);
}

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

t_color	ray_color(t_scene *scene)
{
	// t_hit_record	rec;
	double			t;

	scene->rec = record_init();
	if (hit(scene->world, &scene->ray, &scene->rec) == TRUE)
		return (phong_lighting(scene));
	t = 0.5 * (scene->ray.dir.y + 1.0);
	return (vadd(vmuln(vec(1, 1, 1), 1.0 - t), vmuln(vec(0.5, 0.7, 1.0), t)));
}

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	if (vdot(r->dir, rec->normal) < 0)
	{
		rec->front_face = TRUE;
		rec->normal = rec->normal;
	}
	else
	{
		rec->front_face = FALSE;
		rec->normal = vmuln(rec->normal, -1);
	}
}
