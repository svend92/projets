/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:41:38 by anain             #+#    #+#             */
/*   Updated: 2019/11/24 15:01:44 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "parser.h"
#include "algo.h"
#include "display.h"

static void		free_all(t_graph *graph)
{
	free_paths(graph->paths);
	free_paths(graph->saved_paths);
	free_rooms(graph->rooms_list);
	free_listoflinks(graph->linklist);
	graph->start = NULL;
	graph->end = NULL;
	graph->rooms_list = NULL;
	graph->paths = NULL;
	graph->saved_paths = NULL;
	if (graph->flows)
		free_tab(graph);
}

int				main(int argc, char **argv)
{
	t_graph					graph;
	t_room_path_list		*cur_path;
	t_room_treatment_list	*cur_room;

	graph.ants_nb = 0;
	graph.room_nb = 0;
	graph.start = NULL;
	graph.end = NULL;
	graph.rooms_list = NULL;
	graph.rooms_treatment = 0;
	graph.flows = NULL;
	graph.paths = NULL;
	graph.saved_paths = NULL;
	graph.linklist = NULL;
	parse(&graph);
	if (!graph.saved_paths)
		edmonds_karp(&graph);
	if (!graph.saved_paths)
		ft_error_free_graph(&graph);
	display(&graph);
	free_all(&graph);
}
