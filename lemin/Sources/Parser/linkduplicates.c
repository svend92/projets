/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkduplicates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:51:43 by stherkil          #+#    #+#             */
/*   Updated: 2019/11/24 13:48:03 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utilities.h"

static int		ft_exitfreeline(char **linked_rooms)
{
	free_lines(linked_rooms);
	return (1);
}

static void		ft_exitmalloc(t_graph *graph, char **linked_rooms,
t_listoflinks *new, int flag)
{
	free_lines(linked_rooms);
	if (flag > 1)
		free(new->s1);
	if (flag > 0)
		free(new);
	ft_error_free_graph(graph);
}

int				islinkdup(t_graph *graph, char **linked_rooms)
{
	t_listoflinks	*new;
	t_listoflinks	*links;

	links = graph->linklist;
	new = NULL;
	while (links)
	{
		if (!ft_strcmp(linked_rooms[0],
		links->s1) && !ft_strcmp(linked_rooms[1], links->s2))
			return (ft_exitfreeline(linked_rooms));
		if (!ft_strcmp(linked_rooms[0],
		links->s2) && !ft_strcmp(linked_rooms[1], links->s1))
			return (ft_exitfreeline(linked_rooms));
		links = links->next;
	}
	if (!(new = malloc(sizeof(t_listoflinks))))
		ft_exitmalloc(graph, linked_rooms, new, 0);
	if (!(new->s1 = ft_strdup(linked_rooms[0])))
		ft_exitmalloc(graph, linked_rooms, new, 1);
	if (!(new->s2 = ft_strdup(linked_rooms[1])))
		ft_exitmalloc(graph, linked_rooms, new, 2);
	new->next = graph->linklist;
	graph->linklist = new;
	return (0);
}
