/*
** gere_expose.c for fdf in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Dec  8 15:52:17 2013 bourhime amine
** Last update Wed Jan 22 02:50:00 2014 
*/

#include <rtv1.h>

int		gere_expose(void *p)
{
  t_graphics	*fdf;

  fdf = (t_graphics*)p;
  mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
  return (0);
}
