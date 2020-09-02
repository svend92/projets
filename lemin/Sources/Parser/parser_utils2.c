/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:12:33 by anain             #+#    #+#             */
/*   Updated: 2019/11/24 14:53:58 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "parser.h"

static int		checkdup(t_room *list, int x, int y)
{
	while (list)
	{
		if (list->co_x == x && list->co_y == y)
			return (1);
		list = list->next;
	}
	return (0);
}

int				isdup(t_graph *graph)
{
	t_room *list;

	list = graph->rooms_list;
	while (list)
	{
		if (checkdup(list->next, list->co_x, list->co_y))
			return (1);
		list = list->next;
	}
	return (0);
}

void			flow_tab(t_graph *graph)
{
	int			i;
	int			j;

	j = -1;
	if (!(graph->flows = (int **)malloc(sizeof(int *) * graph->room_nb)))
		ft_error_free_graph(graph);
	while (++j < graph->room_nb)
	{
		i = -1;
		graph->flows[j] = NULL;
		if (!(graph->flows[j] = (int *)malloc(sizeof(int) * graph->room_nb)))
			ft_error_free_graph(graph);
		while (++i < graph->room_nb)
			graph->flows[j][i] = 0;
	}
}
