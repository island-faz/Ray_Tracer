/*
** xmalloc.c<2> for rtv1 in /home/bourhi_a/tmp/RTV1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Wed Jan 22 05:43:58 2014 
** Last update Mon Jan 27 05:45:39 2014 
*/

#include <rtv1.h>

void            *xmalloc(size_t size)
{
  void          *res;

  if ((res = malloc(size)) == 0)
    {
      write(1, "Error: Cannot malloc !\n", 24);
      exit(0);
    }
  return (res);
}
