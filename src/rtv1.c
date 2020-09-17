/*
** rtv1.c for rtv1 in /home/bourhi_a/tmp/RTV1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Jan 23 22:12:13 2014 
** Last update Sun Mar 16 23:23:23 2014 
*/

#include <rtv1.h>

void		run_rtv1(t_rtv1 *rtv1)
{
  t_ray		ray;
  int		x;
  int		y;
  t_ray		axis;
  double	distance;
  int		color;

  init_this_rapidly(&ray, rtv1, &axis, &y);
  while (++y < WIN_Y && (x = -1))
    {
      while (++x < WIN_X)
  	{
	  draw_planes(rtv1, ray, &distance, &color);
	  draw_objs(rtv1, ray, &distance, &color);
	  put_pixel_in_image(x, y, &rtv1->img, color);
	  color = BLACK_COLOR;
	  rotate_vector_z(&ray.vector, (M_PI / 6) / WIN_X);
	  distance = 1000000;
  	}
      rotate_vector_z(&ray.vector, -(M_PI / 6));
      rot_arround_axis(&ray.vector, &axis.vector, (M_PI / 6) / WIN_X);
    }
  img_to_win(rtv1);
}
