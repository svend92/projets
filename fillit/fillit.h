/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:17:15 by stherkil          #+#    #+#             */
/*   Updated: 2019/05/27 14:09:45 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

int		main(int argc, char **argv);
int		ft_sqrt(int n);
int		parser(char buf[544], int buflen);
int		backtrack(char ttr[28][4][4], char **s, int *list, int max);
int		*newlist(int len);
char	**newtab(int size);
char	**cpytab(char **s);
int		*cpylist(int *list);
void	freetab(char **s);
char	**addtab(char **s, char in[4][4], int n, int m);
int		*getedges(char s[4][4]);
int		solver(char tetris[28][4][4], int len, char **s);
int		to_corner(char s[4][4]);
int		righter(char s[4][4]);
int		lower(char s[4][4]);
char	getletter(char s[4][4]);
#endif
