/*
** rtv1_loop.c for rtv1 in /home/bourhi_a/tmp/RTV1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Jan 23 22:18:33 2014 
** Last update Mon Jan 27 04:25:43 2014 
*/

#include <rtv1.h>

void	rtv1_loop(t_rtv1 *rtv1)
{
  mlx_expose_hook(rtv1->gr.win_ptr, gere_expose, &rtv1->gr);
  mlx_hook(rtv1->gr.win_ptr, KeyPress, KeyPressMask, &manage_key, rtv1);
  mlx_do_key_autorepeaton(rtv1->gr.mlx_ptr);
  mlx_loop(rtv1->gr.mlx_ptr);
}
