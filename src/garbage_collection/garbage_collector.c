/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 22:08:40 by smaccary          #+#    #+#             */
/*   Updated: 2020/07/02 15:35:05 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collection.h"

void	free_str(char **str)
{
	if (!*str)
		return ;
	free(*str);
	*str = NULL;
}

void	free_split(char ***split)
{
	char **array;

	if (!*split)
		return ;
	array = *split - 1;
	while (*(++array))
	{
		free(*array);
		*array = NULL;
	}
	free(*split);
	*split = NULL;
}

void	free_textures(t_texture **t)
{
	t_texture	*text;
	int			i;

	if (!(text = *t))
		return ;
	i = -1;
	while (text[++i].array)
	{
		free(text[i].array);
		text[i].array = NULL;
	}
	free(text);
}

void	free_vars(t_vars *vars)
{
	if (vars->mlx && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx && vars->img2[0].img)
		mlx_destroy_image(vars->mlx, vars->img2[0].img);
	if (vars->mlx && vars->img2[1].img)
		mlx_destroy_image(vars->mlx, vars->img2[1].img);
	free_split(&(vars->map.array));
	free_textures(&(vars->text));
	free(vars->sprites);
	free(vars->z_buffer);
}
