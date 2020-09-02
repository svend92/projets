/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:48:10 by anain             #+#    #+#             */
/*   Updated: 2019/11/14 15:45:31 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void		start_to_end(t_graph *graph)
{
	if (!(graph->saved_paths = (t_room_path_list *)malloc(sizeof(\
		t_room_path_list))))
		ft_error_free_graph(graph);
	if (!(graph->saved_paths->path = (t_room_treatment_list *)malloc(sizeof(\
		t_room_treatment_list))))
		ft_error_free_graph(graph);
	graph->saved_paths->path->room = graph->start;
	if (!(graph->saved_paths->path->next = \
		(t_room_treatment_list *)malloc(sizeof(t_room_treatment_list))))
		ft_error_free_graph(graph);
	graph->saved_paths->path->next->room = graph->end;
	graph->saved_paths->path->next->next = NULL;
	graph->saved_paths->length = 1;
	graph->saved_paths->lants = 1 + graph->ants_nb;
	graph->saved_line_max = 1;
	graph->saved_paths->next = NULL;
}
