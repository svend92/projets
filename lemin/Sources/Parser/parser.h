/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:13:56 by anain             #+#    #+#             */
/*   Updated: 2019/11/22 12:32:27 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "utilities.h"

int				islinkdup(t_graph *graph, char **linked_rooms);
void			parser_init(t_statement *final_statement);
void			parse(t_graph *graph);
int				room_valid(t_graph *graph, char *room);
int				ft_space_count(char *str);
int				get_links_error(char **linked_rooms);
int				get_ants_nb(t_graph *graph, char *line);
int				get_room(t_graph *graph, char *line, int start_or_end);
int				find_n_add_adjacent_room(t_room *room, char *name,
					t_graph *graph);
int				isdup(t_graph *graph);
void			free_lines(char **lines);
void			add_statement(t_statement *final_statement,
					char *line, t_graph *graph);
void			print_and_free_statement(t_statement *final_statement);
void			flow_tab(t_graph *graph);
#endif
