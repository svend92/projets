/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:55:44 by anain             #+#    #+#             */
/*   Updated: 2019/11/13 18:39:10 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void						add_room_to_path(t_room_path_list *lst, \
		t_room_treatment_list *cur, \
		t_adjacent_room *cur_adjacent)
{
	cur->antnb = 0;
	cur->room = cur_adjacent->room;
	cur->next = NULL;
	lst->length += 1;
}

static void						find_next(t_room_path_list *lst,
									t_graph *graph, int found)
{
	t_room_treatment_list		*cur;
	t_adjacent_room				*cur_adjacent;

	cur = lst->path->next;
	while (cur->room != graph->end)
	{
		found = 0;
		cur_adjacent = cur->room->adjacent;
		while (cur_adjacent && !found)
		{
			if (graph->flows[cur->room->num][cur_adjacent->room->num] &&
					!graph->flows[cur_adjacent->room->num][cur->room->num])
			{
				if (!(cur->next = \
							(t_room_treatment_list *)
							malloc(sizeof(t_room_treatment_list))))
					ft_error_free_graph(graph);
				cur = cur->next;
				add_room_to_path(lst, cur, cur_adjacent);
				found = 1;
			}
			cur_adjacent = cur_adjacent->next;
		}
	}
}

t_room_path_list				*create_path(t_graph *graph, t_room *room)
{
	t_room_path_list			*cur;

	cur = NULL;
	if (!graph->paths)
	{
		if (!(graph->paths = \
		(t_room_path_list *)malloc(sizeof(t_room_path_list))))
			ft_error_free_graph(graph);
		cur = graph->paths;
	}
	else
	{
		cur = graph->paths;
		while (cur->next)
			cur = cur->next;
		if (!(cur->next = (t_room_path_list *)malloc(sizeof(t_room_path_list))))
			ft_error_free_graph(graph);
		cur = cur->next;
	}
	init_path(graph, room, cur);
	find_next(cur, graph, 0);
	return (cur);
}

int								check_path(t_graph *graph, \
								t_room_path_list *checked_path)
{
	t_room_path_list			*cur_path;
	t_room_treatment_list		*cur_room;
	t_room_treatment_list		*cur_checked_room;

	cur_path = graph->paths;
	cur_checked_room = checked_path->path->next;
	while (cur_checked_room->room != graph->end)
	{
		cur_path = graph->paths;
		while (cur_path->next && cur_path != checked_path)
		{
			cur_room = cur_path->path;
			while (cur_room)
			{
				if (cur_checked_room->room == cur_room->room)
					return (0);
				cur_room = cur_room->next;
			}
			cur_path = cur_path->next;
		}
		cur_checked_room = cur_checked_room->next;
	}
	return (1);
}

void							get_final_paths(t_graph *graph)
{
	t_adjacent_room				*cur_adjacent;
	t_room_path_list			*cur_path;

	cur_adjacent = graph->start->adjacent;
	while (cur_adjacent)
	{
		if (graph->flows[graph->start->num][cur_adjacent->room->num] &&
			!graph->flows[cur_adjacent->room->num][graph->start->num])
			cur_path = create_path(graph, cur_adjacent->room);
		cur_adjacent = cur_adjacent->next;
	}
}
