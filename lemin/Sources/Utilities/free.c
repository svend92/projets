/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:51:32 by anain             #+#    #+#             */
/*   Updated: 2019/11/24 15:01:39 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void								free_bfs(t_room_treatment_list *queue)
{
	t_room_treatment_list			*cur;

	cur = NULL;
	while (queue)
	{
		cur = queue->next;
		free(queue);
		queue = cur;
	}
}

void								free_paths(t_room_path_list *paths)
{
	t_room_path_list				*cur_path;

	cur_path = paths;
	while (paths)
	{
		cur_path = paths;
		paths = paths->next;
		free_bfs(cur_path->path);
		free(cur_path);
	}
}

void								free_adjacent(t_adjacent_room *adjacent)
{
	t_adjacent_room					*cur_adjacent;

	cur_adjacent = adjacent;
	while (adjacent)
	{
		cur_adjacent = adjacent;
		adjacent = adjacent->next;
		free(cur_adjacent);
	}
}

void								free_rooms(t_room *room)
{
	t_room							*cur_room;

	cur_room = room;
	while (room)
	{
		cur_room = room;
		room = room->next;
		free_adjacent(cur_room->adjacent);
		free_parent(cur_room);
		free(cur_room->name);
		free(cur_room);
	}
}

void								free_tab(t_graph *graph)
{
	int								j;

	j = 0;
	while (graph->flows[j] && j < graph->room_nb)
	{
		free(graph->flows[j]);
		++j;
	}
	free(graph->flows);
	graph->flows = NULL;
}
