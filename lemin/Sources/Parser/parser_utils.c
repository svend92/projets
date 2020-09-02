/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:12:33 by anain             #+#    #+#             */
/*   Updated: 2019/11/25 12:08:25 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "parser.h"

int		get_links_error(char **linked_rooms)
{
	free_lines(linked_rooms);
	return (-1);
}

int		get_ants_nb(t_graph *graph, char *line)
{
	if (!ft_strisdigit(line) || ((graph->ants_nb = ft_atod(line)) < 0))
	{
		ft_strdel(&line);
		ft_error_free_graph(graph);
	}
	graph->ants_nb = (int)graph->ants_nb;
	return (graph->ants_nb > 0);
}

int		ft_space_count(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count == 2);
}

void	free_lines(char **lines)
{
	int i;

	i = -1;
	while (lines[++i])
	{
		ft_strdel(&lines[i]);
	}
	free(lines);
}
