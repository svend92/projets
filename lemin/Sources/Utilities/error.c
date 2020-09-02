/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:55:56 by anain             #+#    #+#             */
/*   Updated: 2019/11/24 14:55:35 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void		ft_error_free_graph(t_graph *graph)
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
	graph->linklist = NULL;
	if (graph->flows)
		free_tab(graph);
	write(2, "ERROR\n", 6);
	exit(1);
}
