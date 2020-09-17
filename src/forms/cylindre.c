/*
** cylindre.c for rtv1 in /home/bourhi_a/tmp/RTV1/src/forms
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Wed Jan 29 04:07:26 2014 
** Last update Wed Jan 29 04:18:28 2014 
*/

#include <rtv1.h>

t_dpoint	*cylindre_inter(t_cylindre *cyl, t_ray *ray)
{
  double	a;
  double	b;
  double	c;
  t_dpoint	*intersec;

  a = pow(ray->vector.x, 2);
  a += pow(ray->vector.y, 2);
  b = 2 * ray->vector.x * (ray->coor.x - cyl->coor.x);
  b += 2 * ray->vector.y * (ray->coor.y - cyl->coor.y);
  c = pow(ray->coor.x - cyl->coor.x, 2);
  c += pow(ray->coor.y - cyl->coor.y, 2);
  c -= pow(cyl->rayon, 2);
  intersec = equ_to_inter(a, b, c, ray);
  if (intersec &&
      (intersec->x - ray->coor.x) / ray->vector.x > 0 &&
      (intersec->y - ray->coor.y) / ray->vector.y > 0 &&
      (intersec->z - ray->coor.z) / ray->vector.z > 0)
    return (intersec);
  return (0);
}
