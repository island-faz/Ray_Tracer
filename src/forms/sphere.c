/*
** sphere.c for rtv1 in /home/bourhi_a/tmp/RTV1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Wed Jan 22 03:57:36 2014 
** Last update Sun Mar 16 21:12:43 2014 
*/

#include <rtv1.h>

t_dpoint	*sphere_inter(t_sphere *sphere, t_ray *ray)
{
  double	a;
  double	b;
  double	c;
  t_dpoint	*intersec;

  a = pow(ray->vector.x, 2);
  a += pow(ray->vector.y, 2);
  a += pow(ray->vector.z, 2);
  b = 2 * ray->vector.x * (ray->coor.x - sphere->coor.x);
  b += 2 * ray->vector.y * (ray->coor.y - sphere->coor.y);
  b += 2 * ray->vector.z * (ray->coor.z - sphere->coor.z);
  c = pow(ray->coor.x - sphere->coor.x, 2);
  c += pow(ray->coor.y - sphere->coor.y, 2);
  c += pow(ray->coor.z - sphere->coor.z, 2);
  c -= pow(sphere->rayon, 2);
  intersec = equ_to_inter(a, b, c, ray);
  if (intersec &&
      (intersec->x - ray->coor.x) / ray->vector.x > 0 &&
      (intersec->y - ray->coor.y) / ray->vector.y > 0 &&
      (intersec->z - ray->coor.z) / ray->vector.z > 0)
    return (intersec);
  return (0);
}
