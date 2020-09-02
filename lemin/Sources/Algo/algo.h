/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:13:56 by anain             #+#    #+#             */
/*   Updated: 2019/11/13 18:37:13 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "utilities.h"

t_room_treatment_list	*create_room_treatment_list \
						(t_room *first, t_graph *graph);
t_room_treatment_list	*bfs(t_graph *graph, t_room_treatment_list *cur);
void					edmonds_karp(t_graph *graph);
void					free_bfs(t_room_treatment_list *queue);
void					start_to_end(t_graph *graph);
void					del_last_path(t_graph *graph, t_room_path_list *path);
void					init_path(t_graph *graph, t_room *room, \
						t_room_path_list *cur);
void					get_final_paths(t_graph *graph);

#endif
