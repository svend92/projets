/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_statement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:36:57 by anain             #+#    #+#             */
/*   Updated: 2019/11/24 15:03:12 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "parser.h"

void		parser_init(t_statement *final_statement)
{
	final_statement->str = NULL;
	final_statement->last = NULL;
	final_statement->next = NULL;
}

void		add_statement(t_statement *final_statement, \
		char *line, t_graph *graph)
{
	t_statement	*current_statement;

	current_statement = NULL;
	if ((line[0] == '#' && line[1] == '#') &&
	(!(ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)))
		return ;
	if (!final_statement->str)
	{
		final_statement->str = ft_strdup(line);
		final_statement->last = final_statement;
		final_statement->next = NULL;
		return ;
	}
	if (!(current_statement = (t_statement *)malloc(sizeof(t_statement))))
		ft_error_free_graph(graph);
	current_statement->str = ft_strdup(line);
	final_statement->last->next = current_statement;
	final_statement->last = current_statement;
	current_statement->next = NULL;
}

void		print_and_free_statement(t_statement *final_statement)
{
	t_statement *to_free;

	while (final_statement)
	{
		to_free = final_statement;
		ft_putendl(final_statement->str);
		final_statement = final_statement->next;
		ft_strdel(&to_free->str);
		free(to_free);
	}
}
