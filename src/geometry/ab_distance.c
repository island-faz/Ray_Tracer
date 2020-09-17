/*
** ab_distance.c for rtv1 in /home/bourhi_a/tmp/RTV1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Jan 27 06:05:01 2014 
** Last update Mon Jan 27 06:05:32 2014 
*/

#include <rtv1.h>

double		ab_distance(t_dpoint *a, t_dpoint *b)
{
  double	distance;

  distance = sqrt(pow(a->x - b->x, 2) +
		  pow(a->y - b->y, 2) +
		  pow(a->z - b->z, 2));
  return (distance);
}
