/*
** rot_arr_axis.c for rtv1 in /home/bourhi_a/tmp/RTV1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sat Jan 25 23:25:28 2014 
** Last update Sun Jan 26 00:23:22 2014 
*/

#include <rtv1.h>

void		rot_arround_axis(t_dpoint *p, t_dpoint *r, double theta)
{
  t_dpoint	tmp;
  double	costheta;
  double	sintheta;

  normalise(r);
  costheta = cos(theta);
  sintheta = sin(theta);
  tmp.x = (costheta + (1 - costheta) * r->x * r->x) * p->x;
  tmp.x += ((1 - costheta) * r->x * r->y - r->z * sintheta) * p->y;
  tmp.x += ((1 - costheta) * r->x * r->z + r->y * sintheta) * p->z;
  tmp.y = ((1 - costheta) * r->x * r->y + r->z * sintheta) * p->x;
  tmp.y += (costheta + (1 - costheta) * r->y * r->y) * p->y;
  tmp.y += ((1 - costheta) * r->y * r->z - r->x * sintheta) * p->z;
  tmp.z = ((1 - costheta) * r->x * r->z - r->y * sintheta) * p->x;
  tmp.z += ((1 - costheta) * r->y * r->z + r->x * sintheta) * p->y;
  tmp.z += (costheta + (1 - costheta) * r->z * r->z) * p->z;
  p->x = tmp.x;
  p->y = tmp.y;
  p->z = tmp.z;
}
