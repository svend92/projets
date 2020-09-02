/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_list_manip.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 01:20:37 by anain             #+#    #+#             */
/*   Updated: 2019/11/13 18:37:05 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

t_room_treatment_list			*create_room_treatment_list(t_room *first, \
		t_graph *graph)
{
	t_room_treatment_list		*new_list;

	if (!(new_list = \
				(t_room_treatment_list *)malloc(sizeof(t_room_treatment_list))))
		ft_error_free_graph(graph);
	new_list->room = first;
	new_list->antnb = 0;
	new_list->tmp = 0;
	new_list->next = NULL;
	new_list->reverse = 0;
	return (new_list);
}

void							del_last_path(t_graph *graph, \
		t_room_path_list *path)
{
	t_room_path_list			*cur_path;

	cur_path = graph->paths;
	while (cur_path->next && cur_path->next != path)
		cur_path = cur_path->next;
	cur_path->next = NULL;
	free_paths(path);
}

void							init_path(t_graph *graph, t_room *room, \
		t_room_path_list *cur)
{
	cur->path = create_room_treatment_list(graph->start, graph);
	if (!(cur->path->next = \
				(t_room_treatment_list *)malloc(sizeof(t_room_treatment_list))))
		ft_error_free_graph(graph);
	cur->path->next->room = room;
	cur->length = 1;
	cur->path->next->antnb = 0;
	cur->path->next->next = NULL;
	cur->next = NULL;
}
