/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 10:06:43 by anain             #+#    #+#             */
/*   Updated: 2019/11/25 12:10:43 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H
# include "libft.h"

typedef struct						s_statement
{
	char							*str;
	struct s_statement				*next;
	struct s_statement				*last;
}									t_statement;

typedef struct						s_room
{
	int								num;
	char							*name;
	int								discovered;
	struct s_adjacent_room			*adjacent;
	struct s_parent					*parent;
	struct s_room					*next;
	int								co_x;
	int								co_y;
}									t_room;

typedef struct						s_adjacent_room
{
	t_room							*room;
	int								parent;
	struct s_adjacent_room			*next;
}									t_adjacent_room;

typedef struct						s_parent
{
	t_room							*room;
	struct s_parent					*next;
	int								used;
}									t_parent;

typedef struct						s_room_treatment_list
{
	t_room							*room;
	int								antnb;
	int								tmp;
	int								reverse;
	struct s_room_treatment_list	*next;
}									t_room_treatment_list;

typedef struct						s_room_path_list
{
	t_room_treatment_list			*path;
	long long						length;
	long long						lants;
	struct s_room_path_list			*next;
}									t_room_path_list;

typedef struct						s_listoflinks
{
	char							*s1;
	char							*s2;
	struct s_listoflinks			*next;
}									t_listoflinks;

typedef struct						s_graph
{
	int								ants_nb;
	int								room_nb;
	t_room							*start;
	t_room							*end;
	t_room							*rooms_list;
	int								**flows;
	int								rooms_treatment;
	long long						line_max;
	t_room_path_list				*paths;
	long long						saved_line_max;
	t_room_path_list				*saved_paths;
	t_listoflinks					*linklist;
}									t_graph;

void								add_room_last(t_room *list,
										t_room *new_room, t_parent *parent);
t_room								*create_room_ptr(char *name,
										char *x, char *y, t_graph *graph);
int									create_adjacent_room(t_room *room,
										t_room *adjacent, t_graph *graph);
int									add_adjacent_room(t_room *room,
										t_room *adjacent, t_graph *graph);
void								add_parent(t_room *room,
										t_room *parent_room, t_graph *graph);
int									is_parent(t_room *cur_room, t_room *adj);
int									ft_strisdigit(char *str);
void								free_bfs(t_room_treatment_list *queue);
void								free_paths(t_room_path_list *paths);
void								free_adjacent(t_adjacent_room *adjacent);
void								free_rooms(t_room *room);
void								free_parent(t_room *room);
void								ft_error_free_graph(t_graph *graph);
void								free_tab(t_graph *graph);
void								free_listoflinks(t_listoflinks
										*listoflinks);

#endif
