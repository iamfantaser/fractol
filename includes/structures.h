#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_complex
{
	double		real;
	double		imagin;
}				t_complex;

typedef struct	s_transform
{
	double		zoom;
	int			key_hold;
	float		**c_arr;
}				t_transform;

typedef struct	s_vars
{
	void	*ptr;
	void	*win;
}				t_vars;

typedef struct	s_color
{
	int			t;
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_fractol
{
	char				keys[512];
	char				menu;
	char				is_changed;
	int 				w;
	int					h;
	int					max_iter;
	int					current_range;
	void				(*func)(struct s_fractol  *fractol, int x, int y);
	t_complex			ranges[12];
	t_complex			min;
	t_complex			max;
	t_complex			c;
	t_complex			radius;
	t_vars				mlx;
	t_transform			transformation;
	t_data				img;
	t_data				tmp;
	t_color				color;
}						t_fractol;

#endif
