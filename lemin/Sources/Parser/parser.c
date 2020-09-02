/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:55:05 by anain             #+#    #+#             */
/*   Updated: 2019/11/24 14:37:21 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "algo.h"

static void		get_links_next(t_graph *graph, char **linked_rooms, int *done)
{
	t_room		*begin;

	begin = graph->rooms_list;
	while (begin)
	{
		if (!ft_strcmp(begin->name, linked_rooms[0]))
			*done += find_n_add_adjacent_room(begin, linked_rooms[1], graph);
		else if ((!ft_strcmp(begin->name, linked_rooms[1])))
			*done += find_n_add_adjacent_room(begin, linked_rooms[0], graph);
		begin = begin->next;
	}
}

static int		get_links(t_graph *graph, char *line, int done)
{
	char		**linked_rooms;

	linked_rooms = NULL;
	if (!graph->start || !graph->end)
		ft_error_free_graph(graph);
	if (!(linked_rooms = ft_strsplit(line, '-')))
		return (0);
	if (!(linked_rooms[0] && linked_rooms[1] && !linked_rooms[2]))
		return (get_links_error(linked_rooms));
	if ((!ft_strcmp(graph->start->name, linked_rooms[0]) &&
	!ft_strcmp(graph->end->name, linked_rooms[1])) ||
	(!ft_strcmp(graph->start->name, linked_rooms[1]) &&
	!ft_strcmp(graph->end->name, linked_rooms[0])))
	{
		free_lines(linked_rooms);
		start_to_end(graph);
		return (0);
	}
	if (islinkdup(graph, linked_rooms))
		return (0);
	get_links_next(graph, linked_rooms, &done);
	if (done < 2)
		return (get_links_error(linked_rooms));
	free_lines(linked_rooms);
	return (0);
}

static int		parse_line(t_graph *graph, char *line, int start_or_end)
{
	int ret;

	ret = 0;
	if ((line[0] == '#' && line[1] != '#') || (!graph->ants_nb &&
	get_ants_nb(graph, line)))
		ret = 0;
	else if (!ft_strcmp("##start", line))
		ret = 1;
	else if (!ft_strcmp("##end", line))
		ret = 2;
	else if (line[0] != '#' && line[0] != 'L' && ft_space_count(line))
		graph->rooms_treatment = get_room(graph, line, start_or_end);
	else if (start_or_end)
		ft_error_free_graph(graph);
	else if (line[0] != '#' && line[0] != 'L' && ft_strchr(line, '-') &&
	ft_strchr(line, '-') == ft_strrchr(line, '-'))
		ret = get_links(graph, line, 0);
	else if (!(line[0] == '#' && line[1] == '#'))
		ret = -1;
	return (ret);
}

int				do_line(t_graph *graph,
char *line, int start_or_end, t_statement *final_statement)
{
	int			check;

	check = 0;
	check = parse_line(graph, line, start_or_end);
	if (check >= 0)
		add_statement(final_statement, line, graph);
	ft_strdel(&line);
	return (check);
}

void			parse(t_graph *graph)
{
	char		*line;
	int			ret;
	t_statement	*final_statement;
	int			start_or_end;

	start_or_end = 0;
	if (!(final_statement = (t_statement *)malloc(sizeof(t_statement))))
		ft_error_free_graph(graph);
	parser_init(final_statement);
	while (start_or_end >= 0 && (ret = get_next_line(0, &line)) > 0 \
	&& ft_strlen(line))
		start_or_end = do_line(graph, line, start_or_end, final_statement);
	if (ret == 1 && !ft_strlen(line))
		ft_strdel(&line);
	if (!graph->ants_nb || !graph->start || !graph->end || !graph->linklist)
		ft_error_free_graph(graph);
	if (isdup(graph))
		ft_error_free_graph(graph);
	if (!graph->saved_paths)
		flow_tab(graph);
	print_and_free_statement(final_statement);
}
