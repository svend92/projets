/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:30:52 by anain             #+#    #+#             */
/*   Updated: 2019/11/13 18:43:35 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static t_room_treatment_list		*get_shortest_path(t_graph *graph, \
		t_room_treatment_list *queue)
{
	t_room_treatment_list		*cur;
	t_room_treatment_list		*new;
	t_parent					*cur_parent;

	free_bfs(queue);
	cur = create_room_treatment_list(graph->end, graph);
	while (!((cur->room == graph->start)))
	{
		if (!cur->room->parent)
		{
			free_bfs(cur);
			return (NULL);
		}
		new = create_room_treatment_list(cur->room->parent->room, graph);
		if (!graph->flows[cur->room->parent->room->num][cur->room->num])
			graph->flows[cur->room->parent->room->num][cur->room->num] = 1;
		cur_parent = cur->room->parent;
		cur->room->parent = cur->room->parent->next;
		if (cur_parent)
			free(cur_parent);
		new->next = cur;
		cur = new;
	}
	return (cur);
}

static void							add_room(t_room_treatment_list *queue, \
		t_room *new, t_graph *graph, int reverse)
{
	t_room_treatment_list		*cur;

	cur = queue;
	while (cur->next && new)
		cur = cur->next;
	if (!(cur->next =  \
				(t_room_treatment_list *)malloc(sizeof(t_room_treatment_list))))
	{
		free_bfs(queue);
		ft_error_free_graph(graph);
	}
	new->discovered += 1;
	add_parent(new, queue->room, graph);
	cur->next->room = new;
	cur->next->reverse = reverse;
	cur->next->next = NULL;
}

static int							line_valid(t_graph *graph, int from,
		int to, t_room_treatment_list *cur)
{
	int	i;
	int	positive_flow;
	int discovered;

	discovered = cur->room->discovered;
	positive_flow = 0;
	i = -1;
	if (graph->flows[from][to])
		return (0);
	while (++i < graph->room_nb && !positive_flow)
		if (graph->flows[from][i] == 1 && !graph->flows[i][from])
			positive_flow = i;
	if (!positive_flow)
		return (cur->reverse + 1);
	if (graph->flows[to][from] == 1)
	{
		graph->flows[to][from] = 1;
		return (2);
	}
	if (cur->reverse && positive_flow == cur->room->parent->room->num)
		return (1);
	if (graph->flows[to][from] && discovered == 1)
		return (1);
	return (0);
}

static void							add_to_queue(t_room_treatment_list *queue,
		t_adjacent_room *adjacent,
		t_room_treatment_list *cur,
		t_graph *graph)
{
	int							flag;

	flag = 1;
	if (!adjacent->room->discovered && \
			!graph->flows[cur->room->num][adjacent->room->num])
	{
		if (cur->room != graph->start && !(flag = line_valid(
			graph, cur->room->num, adjacent->room->num, cur)))
			return ;
		add_room(queue, adjacent->room, graph, flag - 1);
		return ;
	}
	if (graph->flows[adjacent->room->num][cur->room->num] &&
			!graph->flows[cur->room->num][adjacent->room->num]
			&& adjacent->room->discovered == 1)
		add_room(queue, adjacent->room, graph, 1);
}

t_room_treatment_list				*bfs(
	t_graph *graph, t_room_treatment_list *cur)
{
	t_room_treatment_list		*queue;
	t_adjacent_room				*adjacent;

	adjacent = NULL;
	queue = create_room_treatment_list(graph->start, graph);
	while (queue)
	{
		cur = queue;
		if (cur->room == graph->end)
			return (get_shortest_path(graph, queue));
		adjacent = cur->room->adjacent;
		while (adjacent)
		{
			if (adjacent->room != graph->start)
				add_to_queue(queue, adjacent, cur, graph);
			adjacent = adjacent->next;
		}
		cur = queue;
		queue = queue->next;
		if (cur)
			free(cur);
	}
	free_bfs(queue);
	return (NULL);
}
