/*
** misc.c for rtv1 in /home/bourhi_a/tmp/BCP2_RTV1/src
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Mar 16 23:21:30 2014 
** Last update Wed Jun  4 06:14:58 2014 
*/

#include <rtv1.h>

void		copy_ray(t_ray *dest, t_ray *source)
{
  dest->coor.x = source->coor.x;
  dest->coor.y = source->coor.y;
  dest->coor.z = source->coor.z;
  dest->vector.x = source->vector.x;
  dest->vector.y = source->vector.y;
  dest->vector.z = source->vector.z;
}

int		get_pix_clr(t_dpoint *inter, t_rtv1 *rt, double *dst, int cl[2])
{
  double	tmp_distance;

  if (inter)
    {
      tmp_distance = ab_distance(&rt->cam.coor, inter);
      if (tmp_distance < *dst)
  	{
  	  *dst = tmp_distance;
  	  if ((int)(inter->z * 5) % 2)
  	    return (cl[0]);
	  else
	    return (cl[1]);
  	}
    }
  return (0);
}

int		get_tiles(t_dpoint *inter, t_rtv1 *rt, double *dst, int cl[2])
{
  double	tmp_distance;

  if (inter != 0)
    {
      tmp_distance = ab_distance(&rt->cam.coor, inter);
      if (tmp_distance < *dst)
	{
	  *dst = tmp_distance;
	  if ((int)(inter->y * 0.5) % 2)
	    {
	      if ((int)(inter->x * 0.5) % 2)
		return (cl[0]);
	      else
		return (cl[1]);
	    }
	  else
	    {
	      if ((int)(inter->x * 0.5) % 2)
		return (cl[1]);
	      else
		return (cl[0]);
	    }
	}
    }
  return (-1);
}

void	init_this_rapidly(t_ray *ray, t_rtv1 *rtv1, t_ray *axis, int *y)
{
  *y = -1;
  copy_ray(ray, &rtv1->cam);
  copy_ray(axis, &rtv1->cam);
  rotate_vector_z(&axis->vector, (M_PI / 2));
  rot_arround_axis(&ray->vector, &axis->vector, -(M_PI / 12));
  rotate_vector_z(&ray->vector, -(M_PI / 12));  
}

void		draw_objs(t_rtv1 *rtv1, t_ray ray, double *dist, int *clr)
{
  int		tmp_clr;
  t_dpoint	*intersection;

  intersection = cone_inter(&rtv1->cone, &ray);
  tmp_clr = get_pix_clr(intersection, rtv1, dist, clrs_1);
  *clr = (tmp_clr ? tmp_clr : *clr);
  intersection = cylindre_inter(&rtv1->cyl, &ray);
  tmp_clr = get_pix_clr(intersection, rtv1, dist, clrs_2);
  *clr = (tmp_clr ? tmp_clr : *clr);
  intersection = sphere_inter(&rtv1->sph2, &ray);
  tmp_clr = get_pix_clr(intersection, rtv1, dist, clrs_3);
  *clr = (tmp_clr ? tmp_clr : *clr);
  intersection = sphere_inter(&rtv1->sph, &ray);
  tmp_clr = get_pix_clr(intersection, rtv1, dist, clrs_4);
  *clr = (tmp_clr ? tmp_clr : *clr);
}
