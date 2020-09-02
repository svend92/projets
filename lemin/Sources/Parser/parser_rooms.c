/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:11:08 by anain             #+#    #+#             */
/*   Updated: 2019/11/15 14:11:34 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utilities.h"

int			room_valid(t_graph *graph, char *room)
{
	t_room	*cur_room;

	cur_room = graph->rooms_list;
	if (!room)
		return (0);
	while (cur_room)
	{
		if (!ft_strcmp(cur_room->name, room))
			return (0);
		cur_room = cur_room->next;
	}
	return (1);
}

int			get_room(t_graph *graph, char *line, int start_or_end)
{
	char	**line_components;
	t_room	*new;

	new = NULL;
	line_components = ft_strsplit(line, ' ');
	if (!(room_valid(graph, line_components[0]) && line_components[1] &&
	line_components[2] && !line_components[3]) ||
	!ft_strisdigit(line_components[1]) || !ft_strisdigit(line_components[2]))
	{
		free_lines(line_components);
		ft_error_free_graph(graph);
	}
	new = create_room_ptr(line_components[0],
			line_components[1], line_components[2], graph);
	if (graph->rooms_list)
		add_room_last(graph->rooms_list, new, NULL);
	else
		graph->rooms_list = new;
	if (start_or_end == 1)
		graph->start = new;
	else if (start_or_end == 2)
		graph->end = new;
	graph->room_nb += 1;
	free_lines(line_components);
	return (0);
}

int			find_n_add_adjacent_room(t_room *room, char *name, t_graph *graph)
{
	t_room	*cur;
	int		flag;

	flag = 0;
	cur = graph->rooms_list;
	while (cur && !flag)
	{
		if (!ft_strcmp(cur->name, name))
		{
			if (!room->adjacent)
				flag = create_adjacent_room(room, cur, graph);
			else
				flag = add_adjacent_room(room, cur, graph);
		}
		cur = cur->next;
	}
	return (1);
}
