/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 05:05:49 by anain             #+#    #+#             */
/*   Updated: 2019/11/14 16:14:23 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void							reset_bfs(t_graph *graph)
{
	t_room							*cur;

	cur = graph->rooms_list;
	while (cur)
	{
		cur->discovered = 0;
		if (cur->parent)
			free_parent(cur);
		cur->parent = NULL;
		cur = cur->next;
	}
	free_paths(graph->paths);
	graph->paths = NULL;
}

static void							ft_fill_the_cup(t_graph *graph)
{
	t_room_path_list				*cur_path;
	int								ants;
	int								flag;

	flag = 0;
	ants = graph->ants_nb;
	cur_path = graph->paths;
	while (ants && cur_path)
	{
		if (cur_path->lants <= graph->line_max)
		{
			ants--;
			cur_path->lants++;
			flag = 1;
		}
		if (cur_path->next)
			cur_path = cur_path->next;
		else
		{
			if (!flag && ants)
				graph->line_max++;
			flag = 0;
			cur_path = graph->paths;
		}
	}
}

static int							line_max(t_graph *graph)
{
	t_room_path_list				*cur_path;

	cur_path = graph->paths;
	graph->line_max = 1;
	while (cur_path)
	{
		cur_path->lants = cur_path->length;
		if (cur_path->length > graph->line_max)
			graph->line_max = cur_path->length;
		cur_path = cur_path->next;
	}
	ft_fill_the_cup(graph);
	cur_path = graph->paths;
	return (graph->line_max < graph->saved_line_max);
}

static void							save_last_path(t_graph *graph)
{
	if (graph->saved_paths)
	{
		free_paths(graph->saved_paths);
		graph->saved_paths = NULL;
	}
	else
		graph->paths->lants = graph->paths->length + graph->ants_nb;
	graph->saved_paths = graph->paths;
	graph->saved_line_max = graph->line_max;
	graph->paths = NULL;
}

void								edmonds_karp(t_graph *graph)
{
	t_room_treatment_list			*path;
	int								i;
	t_room_treatment_list			*cur;

	i = 0;
	cur = NULL;
	graph->start->discovered = 1;
	while ((path = bfs(graph, cur)))
	{
		get_final_paths(graph);
		graph->line_max = graph->paths->length + graph->ants_nb - 1;
		if ((!graph->saved_paths || (line_max(graph))) && graph->paths)
			save_last_path(graph);
		free_bfs(path);
		i++;
		reset_bfs(graph);
	}
}
