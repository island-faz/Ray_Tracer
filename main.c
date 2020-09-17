/*
** main.c for rtv1 in /home/bourhi_a/tmp/RTV1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Jan 23 22:11:01 2014 
** Last update Tue Mar 18 15:14:27 2014 
*/

#include <rtv1.h>

void	continue_init_man(t_rtv1 *rtv1)
{
  rtv1->sph.coor.x = 10;
  rtv1->sph.coor.y = 0;
  rtv1->sph.coor.z = 5;
  rtv1->sph.rayon = 1.0;
  rtv1->cone.coor.x = 20;
  rtv1->cone.coor.y = -5;
  rtv1->cone.coor.z = 4;
  rtv1->cone.angle = M_PI / 12;
  rtv1->sph2.coor.x = 10;
  rtv1->sph2.coor.y = -2;
  rtv1->sph2.coor.z = 2;
  rtv1->sph2.rayon = 0.4;
  clrs_1[0] = WHITE_COLOR;
  clrs_1[1] = ORANGE_COLOR;
  clrs_2[0] = WHITE_COLOR;
  clrs_2[1] = BLUE_COLOR;
  clrs_3[0] = GREEN_COLOR;
  clrs_3[1] = WHITE_COLOR;
  clrs_4[0] = WHITE_COLOR;
  clrs_4[1] = PINK_COLOR;
  clrs_5[0] = BLACK_COLOR;
  clrs_5[1] = WHITE_COLOR;
}

void	continue_init(t_rtv1 *rtv1)
{
  rtv1->back_plane.coor.x = -100;
  rtv1->back_plane.coor.y = 0;
  rtv1->back_plane.coor.z = 0;
  rtv1->back_plane.normal.x = 1;
  rtv1->back_plane.normal.y = 0;
  rtv1->back_plane.normal.z = 0;
  rtv1->left_plane.coor.x = 0;
  rtv1->left_plane.coor.y = 20;
  rtv1->left_plane.coor.z = 0;
  rtv1->left_plane.normal.x = 0;
  rtv1->left_plane.normal.y = 1;
  rtv1->left_plane.normal.z = 0;
  rtv1->right_plane.coor.x = 0;
  rtv1->right_plane.coor.y = -20;
  rtv1->right_plane.coor.z = 0;
  rtv1->right_plane.normal.x = 0;
  rtv1->right_plane.normal.y = 1;
  rtv1->right_plane.normal.z = 0;
  rtv1->cyl.coor.x = 50;
  rtv1->cyl.coor.y = 0;
  rtv1->cyl.coor.z = 0;
  rtv1->cyl.rayon = 0.5;
  continue_init_man(rtv1);
}

void	init_scene(t_rtv1 *rtv1)
{
  rtv1->cam.coor.x = -14.530386;
  rtv1->cam.coor.y = -7.308754;
  rtv1->cam.coor.z = 2.000000;
  rtv1->cam.vector.x = 1.922387;
  rtv1->cam.vector.y = 0.360547;
  rtv1->cam.vector.z = 0.020000;
  rtv1->plane.coor.x = 0;
  rtv1->plane.coor.y = 0;
  rtv1->plane.coor.z = 0;
  rtv1->plane.normal.x = 0;
  rtv1->plane.normal.y = 0;
  rtv1->plane.normal.z = 1;
  rtv1->top_plane.coor.x = 0;
  rtv1->top_plane.coor.y = 0;
  rtv1->top_plane.coor.z = 15;
  rtv1->top_plane.normal.x = 0;
  rtv1->top_plane.normal.y = 0;
  rtv1->top_plane.normal.z = 1;
  rtv1->front_plane.coor.x = 180;
  rtv1->front_plane.coor.y = 0;
  rtv1->front_plane.coor.z = 0;
  rtv1->front_plane.normal.x = 1;
  rtv1->front_plane.normal.y = 0;
  rtv1->front_plane.normal.z = 0;
  continue_init(rtv1);
}

int		main()
{
  t_rtv1	rtv1;

  if (!(init_rtv1(&rtv1)))
    {
      write(1, "Error: Connot lunch RTV1.\n", 27);
      return (1);
    }
  init_scene(&rtv1);
  run_rtv1(&rtv1);
  rtv1_loop(&rtv1);
  return (0);
}
