/*
** clear_image.c for fdf in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Dec  8 15:53:58 2013 bourhime amine
** Last update Wed Jan 22 02:50:14 2014 
*/

#include <rtv1.h>

void	clear_image(int	*img, int end)
{
  int	i;

  i = 0;
  while (i < end)
    img[i++] = 0;
}
