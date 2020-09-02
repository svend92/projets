/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 10:06:33 by anain             #+#    #+#             */
/*   Updated: 2019/11/13 18:47:31 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

int					create_adjacent_room(t_room *room, \
		t_room *adjacent, t_graph *graph)
{
	if (!(room->adjacent = (t_adjacent_room *)malloc(sizeof(t_adjacent_room))))
		ft_error_free_graph(graph);
	room->adjacent->room = adjacent;
	room->adjacent->parent = 0;
	room->adjacent->next = NULL;
	return (1);
}

int					add_adjacent_room(t_room *room, \
		t_room *adjacent, t_graph *graph)
{
	t_adjacent_room	*cur;

	cur = room->adjacent;
	while (cur->next)
		cur = cur->next;
	if (!(cur->next = (t_adjacent_room *)malloc(sizeof(t_adjacent_room))))
		ft_error_free_graph(graph);
	cur->next->room = adjacent;
	cur->next->next = NULL;
	return (1);
}
