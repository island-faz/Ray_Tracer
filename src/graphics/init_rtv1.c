/*
** initi_rtv1.c for rtv1 in /home/bourhi_a/tmp/RTV1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Jan 23 21:57:14 2014 
** Last update Sun Mar 16 21:09:27 2014 
*/

#include <rtv1.h>

int	init_rtv1(t_rtv1 *rtv1)
{
  if (!(rtv1->gr.mlx_ptr = mlx_init()))
    return (0);
  if (!(rtv1->gr.img_ptr = mlx_new_image(rtv1->gr.mlx_ptr,
					 WIN_X, WIN_Y)))
    return (0);
  if (!(rtv1->gr.win_ptr = mlx_new_window(rtv1->gr.mlx_ptr,
					  WIN_X, WIN_Y, "RTV1")))
    return (0);
  rtv1->img.data = (int *)mlx_get_data_addr(rtv1->gr.img_ptr,
					   &rtv1->img.bpp,
					   &rtv1->img.sizeline,
					   &rtv1->img.endian);
  rtv1->img.end = (rtv1->img.sizeline * WIN_Y / 4) - 1;
  return (1);
}
