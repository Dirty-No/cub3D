/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:34:07 by user42            #+#    #+#             */
/*   Updated: 2020/06/27 17:31:40 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	format_map_line(char *line)
{
	int error;
	int i;

	i = -1;
	error = SUCCESS_CODE;
	if (!line || !*line)
		return ((line) ? 0 : 1);
	while (line[++i])
	{
		if (ft_isspace(line[i]))
			line[i] = '0';
		if (!ft_strchr(VALID_MAP_CHARS, line[i]))
			return (MAP_ERROR);
	}
	return (error);
}

char		**parse_array(t_list *lst, int len)
{
	char	**array;
	int		error;

	error = 0;
	if (lst && (array = malloc(sizeof(char *) * (len + 1))))
	{
		len = 1;
		while (lst->next && !ft_isdigit(*(char *)lst->content)
						&& !ft_isspace(*(char *)lst->content))
			lst = lst->next;
		array[0] = lst->content;
		error |= format_map_line(array[0]);
		while ((lst = lst->next) && !(error |= format_map_line(lst->content)))
			array[len++] = lst->content;
		array[len] = NULL;
	}
	else
		array = NULL;
	ft_lstclear(&lst, NULL);
	if (error)
	{
		free(array);
		return (NULL);
	}
	return (array);
}

int			find_spawn(char **map, t_spawn *spawn)
{
	char	*spawn_ptr;
	char	*last_ptr;
	int		x;
	int		y;

	y = -1;
	x = -1;
	*spawn = (t_spawn){-1, -1, 0};
	while (map[++x])
	{
		if ((spawn_ptr = ft_setchr(map[x], SPAWN_CHARS))
						!= (last_ptr = ft_setrchr(map[x], SPAWN_CHARS)))
			return (MAP_ERROR);
		else if (spawn_ptr)
		{
			if (spawn->x != -1 && spawn->y != -1)
				return (MAP_ERROR);
			*spawn = (t_spawn){x + 0.5, spawn_ptr - map[x] + 0.5,
								map[x][spawn_ptr - map[x]]};
			map[(int)(spawn->x - 0.5)][(int)(spawn->y - 0.5)] = '0';
		}
	}
	if (spawn->x <= 0 || spawn->y <= 0 || !ft_strchr(SPAWN_CHARS, spawn->dir))
		return (MAP_ERROR);
	return (SUCCESS_CODE);
}