/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frontend.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:39:27 by smaccary          #+#    #+#             */
/*   Updated: 2020/06/25 17:35:21 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRONTEND_H
# define FRONTEND_H
# include "structs/structs.h"
# include "settings.h"
# define TRANS_COLOR		0x00000001

# define WALL_COLOR			0x00AAAAAA
# define WALL_SIDE_COLOR	0x00888888

# define ROOF_COLOR			0x00000000
# define FLOOR_COLOR		0x009C9C9C

void	draw_text(t_texture *text, t_data *img, int x0, int y0);
int		create_rgb(unsigned char r, unsigned char g, unsigned char b) \
 __attribute__((pure));
void	my_mlx_pixel_put(t_data *img, int x, int y, int color) \
 __attribute__((hot));
void	my_line_put(t_data *img, int x0, int y0, int x1, int y1, int color);
void	draw_rectangle(t_data *img, int top_left[2], int bot_right[2]);
void	drawcircle(t_data *img, int x0, int y0, int radius, int color);
void	drawhalfcircle(t_data *img, int x0, int y0, int radius, int color);
void	draw_gradient(t_data *img);
void	draw_rainbow(t_data *img);
void	draw_scene(t_vars *vars);
int		add_shade(double dist, int color) __attribute__((pure));

#endif