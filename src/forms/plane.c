/*
** plane.c for rtv1 in /home/bourhi_a/tmp/RTV1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Jan 26 05:53:01 2014 
** Last update Mon Jan 27 03:47:05 2014 
*/

#include <rtv1.h>

t_dpoint	*plane_intersection(t_plane *plane, t_ray *ray)
{
  double	a;
  double	b;
  double	x;
  t_dpoint	*intersec;

  a = plane->normal.x * ray->vector.x;
  a += plane->normal.y * ray->vector.y;
  a += plane->normal.z * ray->vector.z;
  b = plane->normal.x * (ray->coor.x - plane->coor.x);
  b += plane->normal.y * (ray->coor.y - plane->coor.y);
  b += plane->normal.z * (ray->coor.z - plane->coor.z);
  if (a == 0)
    return (0);
  x = -b / a;
  intersec = xmalloc(sizeof(t_dpoint));
  intersec->x = ray->vector.x * x + ray->coor.x;
  intersec->y = ray->vector.y * x + ray->coor.y;
  intersec->z = ray->vector.z * x + ray->coor.z;
  normalise(&ray->vector);
  if ((intersec->x - ray->coor.x) / ray->vector.x > 0 &&
      (intersec->y - ray->coor.y) / ray->vector.y > 0 &&
      (intersec->z - ray->coor.z) / ray->vector.z > 0)
    return (intersec);
  return (0);
}
