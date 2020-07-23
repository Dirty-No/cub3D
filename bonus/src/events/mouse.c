/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:57:06 by user42            #+#    #+#             */
/*   Updated: 2020/07/23 21:24:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int		mouse_press_handler(int keycode, int x, int y, t_vars *vars)
{
	(void)(x && y);
	if (keycode == 1)
		return (key_handler(LEFT_CLICK, vars));
	return (key_handler(-1, vars));
}

int		mouse_release_handler(int keycode, int x, int y, t_vars *vars)
{
	(void)(x && y);
	if (keycode == 1)
		return (release_handler(LEFT_CLICK, vars));
	return (release_handler(-1, vars));
}

int		click_handler(t_vars *vars)
{
	static clock_t	last_shot = 0;
	double			elapsed;
	static int		released = 1;

	elapsed = (double)(clock() - last_shot) / (double)CLOCKS_PER_SEC;
	if (!released && !key_chr(vars->keys, LEFT_CLICK, K_BUFF_SIZE))
		released = 1;
	if (key_chr(vars->keys, LEFT_CLICK, K_BUFF_SIZE)
		&& elapsed > (double)SHOT_DURATION && released)
	{
		released = 0;
		if (elapsed > (double)SHOT_DURATION + (double)SHOT_COOLDOWN)
		{
			last_shot = clock();
			vars->draw_shot = 1;
			system("(" PLAYER " " GUNSHOT_PATH BACKGROUND ") " OPTIONS);
			shoot_sprites(&(vars->sprites), &(vars->num_sprites));
			return (1);
		}
	}
	if (elapsed > (double)SHOT_DURATION && vars->draw_shot)
		vars->draw_shot = 0;
	return (0);
}

#include <limits.h>

int		mouse_move_handler(t_vars *vars)
{
	int				win_x;
	int				win_y;
	double			i;
	static int		centerx = INT_MIN;
	static int		centery = INT_MIN;
	int				foo;

	foo = 0;
	if (centerx == INT_MIN)
	{
		centerx = vars->game_screen.width / 2;
		centery = vars->game_screen.height / 2;
		if (OSX)
		{
			my_mouse_move(vars->mlx, vars->win, vars->game_screen.width / 2, vars->game_screen.height / 2);
			my_mouse_get_pos(vars->mlx, vars->win, &centerx, &centery);
		}
	}
	if (!vars->win_focus)
		return (0);
	my_mouse_get_pos(vars->mlx, vars->win, &win_x, &win_y);
	if (((i = (double)win_y - (double)vars->game_screen.height / 2.0))
		!= ((double)vars->game_screen.height / 2.0))
	{
		vars->pitch -= i * 2;
		check_pitch(&(vars->pitch));
		foo = 1;
	}
	if (((i = (double)win_x - (double)vars->game_screen.width / 2.0))
		!= (double)vars->game_screen.width / 2.0)
	{
		turn_right(vars, i / MOUSE_DPI);
		foo = 1;
	}
	if (foo)
		my_mouse_move(vars->mlx, vars->win, centerx, centery);
	return (1);
}
