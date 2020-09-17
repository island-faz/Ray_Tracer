/*
** normaliser_vec.c for rtv1 in /home/bourhi_a/tmp/RTV1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sat Jan 25 23:20:46 2014 
** Last update Sun Mar 16 23:24:35 2014 
*/

#include <rtv1.h>

void		normalise(t_dpoint *vector)
{
  double	norme;

  norme = sqrt(pow(vector->x, 2) +
	       pow(vector->y, 2) +
	       pow(vector->z, 2));
  if (norme != 0)
    {
      vector->x /= norme;
      vector->y /= norme;
      vector->z /= norme;
    }
}
