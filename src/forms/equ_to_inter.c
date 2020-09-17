/*
** eq_solver.c for rtv1 in /home/bourhi_a/tmp/RTV1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Wed Jan 22 06:09:22 2014 
** Last update Sun Mar 16 21:12:08 2014 
*/

#include <rtv1.h>

t_dpoint	*equ_to_inter(double a, double b, double c, t_ray *ray)
{
  t_dpoint	*intersec;
  t_dpoint	*tmp_intr;
  double	delta;
  double	x1;
  double	x2;

  delta = (b * b) - (4 * a * c);
  if (delta < 0 || a == 0)
    return (0);
  intersec = xmalloc(sizeof(t_dpoint));
  tmp_intr = xmalloc(sizeof(t_dpoint));
  x1 = (-b - sqrt(delta)) / (2 * a);
  x2 = (-b + sqrt(delta)) / (2 * a);
  intersec->x = ray->vector.x * x1 + ray->coor.x;
  intersec->y = ray->vector.y * x1 + ray->coor.y;
  intersec->z = ray->vector.z * x1 + ray->coor.z;
  tmp_intr->x = ray->vector.x * x2 + ray->coor.x;
  tmp_intr->y = ray->vector.y * x2 + ray->coor.y;
  tmp_intr->z = ray->vector.z * x2 + ray->coor.z;
  if ((ab_distance(&ray->coor, intersec) <
	ab_distance(&ray->coor, tmp_intr)))
    return (intersec);
  return (tmp_intr);
}
