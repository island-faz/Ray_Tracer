/*
** manage_key.c for fdf in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Dec  8 01:45:10 2013 bourhime amine
** Last update Sun Mar 16 21:14:03 2014 
*/

#include <rtv1.h>

void		rotation(int key, t_rtv1 *rtv1)
{
  int		flag;

  flag = 0;
  if (key == RIGHT_KEY && (flag = 1))
    rotate_vector_z(&rtv1->cam.vector, 0.05);
  else if (key == LEFT_KEY && (flag = 1))
    rotate_vector_z(&rtv1->cam.vector, -0.05);
  else if (key == UP_KEY && (flag = 1))
    rtv1->cam.vector.z += 0.02;
  else if (key == DOWN_KEY && (flag = 1))
    rtv1->cam.vector.z -= 0.02;
  if (flag)
    run_rtv1(rtv1);
}

void		movement(int key, t_rtv1 *rtv1)
{
  int		flag;

  flag = 0;
  if (key == Q_KEY && (flag = 1))
    {
      rtv1->cam.coor.x += rtv1->cam.vector.x;
      rtv1->cam.coor.y += rtv1->cam.vector.y;
    }
  else if (key == S_KEY && (flag = 1))
    {
      rtv1->cam.coor.x -= rtv1->cam.vector.x;
      rtv1->cam.coor.y -= rtv1->cam.vector.y;
    }
  if (flag)
    run_rtv1(rtv1);
}

int		manage_key(int key, void *p)
{
  t_rtv1	*rtv1;

  if (key == EXIT_KEY)
    exit(0);
  rtv1 = (t_rtv1*)p;
  rotation(key, rtv1);
  movement(key, rtv1);
  return (0);
}
