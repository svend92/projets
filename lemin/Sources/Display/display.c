/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:49:27 by anain             #+#    #+#             */
/*   Updated: 2019/11/14 16:00:59 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void						ft_gogo(t_graph *graph)
{
	t_room_path_list		*cur_path;
	t_room_treatment_list	*cur_room;

	cur_path = graph->saved_paths;
	while (cur_path)
	{
		cur_room = cur_path->path;
		while (cur_room)
		{
			if (cur_room->next)
				(cur_room->next)->tmp = cur_room->antnb;
			cur_room->antnb = cur_room->tmp;
			cur_room = cur_room->next;
		}
		cur_path = cur_path->next;
	}
}

void						ft_print_move(t_room_treatment_list *cur_room)
{
	write(1, "L", 1);
	ft_putnbr(cur_room->antnb);
	write(1, "-", 1);
	ft_putstr(cur_room->room->name);
}

void						ft_display_places(t_graph *graph, int *flag)
{
	t_room_path_list		*cur_path;
	t_room_treatment_list	*cur_room;

	cur_path = graph->saved_paths;
	while (cur_path)
	{
		cur_room = cur_path->path;
		while (cur_room)
		{
			if (cur_room->antnb)
			{
				if (*flag || (graph->saved_line_max == 1 \
				&& cur_room->antnb != 1))
					write(1, " ", 1);
				*flag = 1;
				ft_print_move(cur_room);
			}
			cur_room = cur_room->next;
		}
		cur_path = cur_path->next;
	}
	if (*flag && graph->saved_line_max > 1)
		write(1, "\n", 1);
}

void						display(t_graph *graph)
{
	t_room_path_list		*cur_path;
	int						ant;
	int						flag;

	ant = 1;
	flag = 1;
	write(1, "\n", 1);
	while (flag)
	{
		flag = 0;
		cur_path = graph->saved_paths;
		while (cur_path)
		{
			if (ant <= graph->ants_nb && !cur_path->path->antnb &&
			cur_path->lants > cur_path->length && cur_path->lants--)
			{
				cur_path->path->antnb = ant;
				cur_path->path->tmp = 0;
				ant++;
			}
			cur_path = cur_path->next;
		}
		ft_gogo(graph);
		ft_display_places(graph, &flag);
	}
}
