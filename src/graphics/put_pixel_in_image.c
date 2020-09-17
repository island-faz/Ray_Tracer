/*
** put_pixel_in_image.c for FDF in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Wed Dec  4 16:08:36 2013 bourhime amine
** Last update Mon Jan 27 05:44:33 2014 
*/

#include <rtv1.h>

void	put_pixel_in_image(int x, int y, t_image *img, int clr)
{
  int	tmp;

  if (img->bpp != 0)
    {
      tmp = x + ((img->sizeline / (img->bpp / 8)) * y);
      if (tmp <= img->end && tmp > 0)
	img->data[tmp] = clr;
    }
}
