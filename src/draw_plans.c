/*
** draw_plans.c for rtv1 in /home/bourhi_a/tmp/BCP2_RTV1/src
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Mar 16 23:25:32 2014 
** Last update Wed Jun  4 06:15:24 2014 
*/

#include <rtv1.h>

void		draw_planes(t_rtv1 *rtv1, t_ray ray, double *dist, int *clr)
{
  int		tmp_clr;
  t_dpoint	*intersection;

  intersection = plane_intersection(&rtv1->top_plane, &ray);
  tmp_clr = get_tiles(intersection, rtv1, dist, clrs_1);
  *clr = (tmp_clr != -1 ? tmp_clr : *clr);
  intersection = plane_intersection(&rtv1->front_plane, &ray);
  tmp_clr = get_tiles(intersection, rtv1, dist, clrs_4);
  *clr = (tmp_clr != -1 ? tmp_clr : *clr);
  intersection = plane_intersection(&rtv1->back_plane, &ray);
  tmp_clr = get_pix_clr(intersection, rtv1, dist, clrs_1);
  *clr = (tmp_clr ? tmp_clr : *clr);
  intersection = plane_intersection(&rtv1->left_plane, &ray);
  tmp_clr = get_tiles(intersection, rtv1, dist, clrs_1);
  *clr = (tmp_clr != -1 ? tmp_clr : *clr);
  intersection = plane_intersection(&rtv1->right_plane, &ray);
  tmp_clr = get_tiles(intersection, rtv1, dist, clrs_1);
  *clr = (tmp_clr != -1 ? tmp_clr : *clr);
  intersection = plane_intersection(&rtv1->plane, &ray);
  tmp_clr = get_tiles(intersection, rtv1, dist, clrs_5);
  *clr = (tmp_clr != -1 ? tmp_clr : *clr);
}
