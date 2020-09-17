/*
** img_to_win.c for rtv1 in /home/bourhi_a/tmp/RTV1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Jan 23 22:37:49 2014 
** Last update Mon Jan 27 04:13:44 2014 
*/

#include <rtv1.h>

void		img_to_win(t_rtv1 *rtv1)
{
  mlx_put_image_to_window(rtv1->gr.mlx_ptr,
			  rtv1->gr.win_ptr,
			  rtv1->gr.img_ptr,
			  0, 0);
}
