#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "includes.h"
# include "structures.h"

void		ft_write_hint(void);
void		ft_error(const char *message);
int			ft_valid(char *str, char *needle);
double		ft_atod(const char *arg);
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);
int			ft_calculation(t_fractol *fractol, char *argv);
int			ft_get_color(int t, int r, int g, int b);
void		ft_put_pixel(t_fractol *fractol, int x, int y, t_color color);
int			ft_handle_key(int keycode, t_fractol *fractol);
int			ft_zoom(int keycode, int x, int y, t_fractol *fractol);
void		ft_tunnel(t_fractol *fractol, int x, int y);
t_complex	ft_get_complex(t_fractol *fractol, int x, int y);
double		ft_abs_double(double num);
int			ft_exit(int key);
void		ft_load_range_set(t_fractol *fractol);
void		ft_bubble(t_fractol *fractol, int x, int y);
int			ft_new_range(t_fractol *fractol);
t_fractol	*ft_new_color(int iteration, t_fractol *fractol);
int			ft_new_pallete(t_fractol *fractol);
int			ft_change_colorset(t_fractol *fractol, int set_i, int i_i, char op);
void		ft_burning_ship(t_fractol *fractol, int x, int y);
int			ft_shift_color(int keycode, t_fractol *fractol);
int			ft_remove_key(int keycode, t_fractol *fractol);
void		ft_default(t_fractol *fractol);
void		ft_pixel(t_fractol *fractol, int x, int y);
int			ft_move(int keycode, t_fractol *fractol);
int			ft_switch_set(t_fractol *fractol);
int			ft_change_max_iteration(int keycode, t_fractol *fractol);
void		ft_draw(t_fractol *fractol);
int			ft_display_menu(t_fractol *fractol);

#endif
