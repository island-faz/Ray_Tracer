/*
** rtv1.h for rtv1 in /home/bourhi_a/tmp/RTV1
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Wed Jan 22 05:14:10 2014 
** Last update Fri Jun  6 17:22:41 2014 
*/

#ifndef		        RTV1_H_
# define		RTV1_H_

#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "../minilibx/mlx.h"

# define ABS(x)			((((x)) < 0) ? (-(x)) : ((x)))
# define M_PI			3.14159265359
# define WIN_X			1000
# define WIN_Y			1000
# define KeyPressMask		(1L<<0)
# define KeyPress		2

# define UP_KEY			65362
# define RIGHT_KEY		65363
# define DOWN_KEY		65364
# define LEFT_KEY		65361
# define EXIT_KEY		65307
# define Q_KEY			113
# define S_KEY			115

# define RED_COLOR		0xff0000
# define GREEN_COLOR		0x33FF00
# define ORANGE_COLOR		0xFF2400
# define WHITE_COLOR		0xffffff
# define BLACK_COLOR		0x000000
# define GRAY_COLOR		0x888888
# define BLUE_COLOR		0x0000ff
# define PURPLE_COLOR		0x302b54
# define YELLOW_COLOR		0xffff00
# define PINK_COLOR		0xCC0066

typedef struct	s_dpoint
{
  double	x;
  double	y;
  double	z;
}		t_dpoint;

typedef struct  s_my_mlx
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
}		t_graphics;

typedef struct s_ray
{
  t_dpoint	coor;
  t_dpoint	vector;
}		t_ray;

typedef struct s_plane
{
  t_dpoint	coor;
  t_dpoint	normal;
}		t_plane;

typedef struct s_cylindre
{
  t_dpoint	coor;
  double	rayon;
}		t_cylindre;

typedef struct s_cone
{
  t_dpoint	coor;
  double	angle;
}		t_cone;

typedef struct s_sphere
{
  t_dpoint	coor;
  double	rayon;
}		t_sphere;

typedef struct	s_image
{
  int		bpp;
  int		sizeline;
  int		*data;
  int		endian;
  int		end;
}		t_image;

typedef struct	s_rtv1
{
  t_graphics	gr;
  t_image	img;
  t_ray		cam;
  t_cone	cone;
  t_cylindre	cyl;
  t_sphere	sph;
  t_sphere	sph2;
  t_plane	plane;
  t_plane	top_plane;
  t_plane	front_plane;
  t_plane	left_plane;
  t_plane	right_plane;
  t_plane	back_plane;
}		t_rtv1;

typedef struct	s_list
{
  void		*obj;
  struct s_list	*next;
}		t_list;

int		clrs_1[2];
int		clrs_2[2];
int		clrs_3[2];
int		clrs_4[2];
int		clrs_5[2];

int		init_rtv1(t_rtv1 *rtv1);
void		run_rtv1(t_rtv1 *rtv1);
void		rtv1_loop(t_rtv1 *rtv1);
void		normalise(t_dpoint *vector);
void		img_to_win(t_rtv1 *rtv1);
int		manage_key(int key, void *p);
int		gere_expose(void *p);
void		clear_image(int	*img, int end);
void            *xmalloc(size_t size);
t_dpoint	*equ_to_inter(double a, double b, double c, t_ray *ray);
t_dpoint	*sphere_inter(t_sphere *sphere, t_ray *ray);
t_dpoint	*cylindre_inter(t_cylindre *cyl, t_ray *ray);
t_dpoint	*cone_inter(t_cone *cone, t_ray *ray);
t_dpoint	*plane_intersection(t_plane *plane, t_ray *ray);
void		rotate_vector_x(t_dpoint *vector, double rad_angle);
void		rotate_vector_y(t_dpoint *vector, double rad_angle);
void		rotate_vector_z(t_dpoint *vector, double rad_angle);
void		put_pixel_in_image(int x, int y, t_image *img, int color);
void		rot_arround_axis(t_dpoint *p, t_dpoint *r, double theta);
double		ab_distance(t_dpoint *a, t_dpoint *b);
void		file_to_list(const char *path);
void		draw_objs(t_rtv1 *rtv1, t_ray ray, double *dist, int *clr);
void		draw_planes(t_rtv1 *rtv1, t_ray ray, double *dist, int *clr);
void		init_this_rapidly(t_ray *ray, t_rtv1 *rt, t_ray *axis, int *y);
int		get_tiles(t_dpoint *inter, t_rtv1 *rt, double *dst, int cl[2]);
int		get_pix_clr(t_dpoint *inter, t_rtv1 *rt, double *ds, int cl[2]);
void		copy_ray(t_ray *dest, t_ray *source);

#endif		/* RTV1_H_ */
