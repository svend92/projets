/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 10:06:33 by anain             #+#    #+#             */
/*   Updated: 2019/11/24 14:23:11 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

t_room				*create_room_ptr(char *name,
		char *x, char *y, t_graph *graph)
{
	t_room			*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		ft_error_free_graph(graph);
	room->num = graph->room_nb;
	if (!(room->name = ft_strdup(name)))
		ft_error_free_graph(graph);
	room->co_x = ft_atoi(x);
	room->co_y = ft_atoi(y);
	room->adjacent = NULL;
	room->parent = NULL;
	room->next = NULL;
	room->discovered = 0;
	return (room);
}

void				add_room_last(t_room *list, \
		t_room *new_room, t_parent *parent)
{
	t_room			*begin;

	begin = list;
	while (list->next)
		list = list->next;
	list->next = new_room;
	list->next->next = NULL;
	list->parent = parent;
	list = begin;
}

void				add_parent(t_room *room, \
		t_room *parent_room, t_graph *graph)
{
	t_parent		*new;

	if (!(new = \
				(t_parent *)malloc(sizeof(t_parent))))
		ft_error_free_graph(graph);
	new->room = parent_room;
	new->used = 0;
	if (room->parent)
		new->next = room->parent;
	else
		new->next = NULL;
	room->parent = new;
}

void				free_parent(t_room *room)
{
	t_parent	*cur;
	int			i;

	cur = room->parent;
	i = 0;
	while (room->parent)
	{
		i++;
		cur = room->parent;
		room->parent = room->parent->next;
		free(cur);
	}
	room->parent = NULL;
}

int					is_parent(t_room *cur_room, t_room *adj)
{
	t_parent		*cur_parent;

	cur_parent = adj->parent;
	while (cur_parent)
	{
		if (cur_parent->room == cur_room)
		{
			return (1);
		}
		cur_parent = cur_parent->next;
	}
	cur_parent = cur_room->parent;
	while (cur_parent)
	{
		if (cur_parent->room == adj)
		{
			return (1);
		}
		cur_parent = cur_parent->next;
	}
	return (0);
}
