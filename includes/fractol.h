#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>

# define WIDTH				800
# define HEIGHT				600

# define ECHAP				53
# define T					17
# define H					4
# define SPACE				49
# define KEY_UP				126
# define KEY_RIGHT			124
# define KEY_DOWN			125
# define KEY_LEFT			123
# define MOUSE_CLIC_L		1
# define MOUSE_CLIC_R		2
# define MOUSE_WHEEL_UP		5
# define MOUSE_WHEEL_DOWN	4
# define KEY_T 				17
# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define KEYRELEASE 	3
# define KEYRELEASE_MASK	(1L<<1)
# define KEYPRESS 		2
# define KEYPRESS_MASK	(1L<<0)
# define BUTTONPRESS 4
# define BUTTONPRESS_MASK	(1L<<10)
# define EXPOSE				12
# define EXPOSE_MASK	(1L<<15)
# define MOTION_NOTIFY		6
# define PTR_MOTION_MASK	(1L<<6)

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;


typedef union		u_color
{
	int				whole;
	struct
	{
		unsigned char	r;
		unsigned int	g;
		unsigned int	b;
	} 			le;
}					t_color;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sline;
	int				endian;
}					t_img;

typedef	struct		s_fractal
{
	int				i;
	double			zr;
	double			zi;
	double			cr;
	double			ci;
	double			tmp;
}					t_fractal;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				fractal_type;
	int				i;
	int 			theme;
	int 			help;
	double			zoom_x;
	double			zoom_y;
	double			mouse_x;
	double			mouse_y;
	t_point			cam;
	t_img			img;
	t_color			color_rgba;
	t_fractal		f;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	int 			i_max;
}					t_env;

void				ft_usage_error();
void				ft_msg_error(char *msg);
void				initialize_env(t_env *e, char **av);

void				init_fractal_area(t_env *e);
void				init_fractal(t_env *e, t_fractal *f);
void				display_menu(t_env *e);
void				select_fractal(t_env *e, t_fractal *f);
int					key_hook(int keycode, t_env *e);
int					mouse_motion(int x, int y, t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					expose_hook(t_env *e);

void 				move(t_env *e, int keycode);
void				move_pixel_to_left(t_env *e);
void				move_pixel_to_bottom(t_env *e);
void				move_pixel_to_right(t_env *e);
void				move_pixel_to_top(t_env *e);

double				scale_x(t_env *e, double x);
double				scale_y(t_env *e, double y);
void				set_color(t_env *e, int color);
int 				get_color(int i);
void				pixel_put_to_image(t_env *e, double x, double y);

void				burnship(t_env *e, t_fractal *f);
void				mandelbrot(t_env *e, t_fractal *f);
void				julia(t_env *e, t_fractal *f);

#endif
