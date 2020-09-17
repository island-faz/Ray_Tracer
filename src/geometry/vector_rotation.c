/*
** vector_rotation.c for rtv1 in /home/bourhi_a/tmp/RTV1/src/forms
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Wed Jan 22 18:52:07 2014 
** Last update Fri Jan 24 02:07:41 2014 
*/

#include <rtv1.h>

void		rotate_vector_x(t_dpoint *vector, double rad_angle)
{
  double	tmp;

  tmp = vector->y * cos(rad_angle) - vector->z * sin(rad_angle);
  vector->z = vector->y * sin(rad_angle) + vector->z * cos(rad_angle);
  vector->y = tmp;
}

void		rotate_vector_y(t_dpoint *vector, double rad_angle)
{
  double	tmp;

  tmp = vector->x * cos(rad_angle) + vector->z * sin(rad_angle);
  vector->z = -vector->x * sin(rad_angle) + vector->z * cos(rad_angle);
  vector->x = tmp;
}

void		rotate_vector_z(t_dpoint *vector, double rad_angle)
{
  double	tmp;

  tmp = vector->x * cos(rad_angle) - vector->y * sin(rad_angle);
  vector->y = vector->x * sin(rad_angle) + vector->y * cos(rad_angle);
  vector->x = tmp;
}
