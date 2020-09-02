/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:51:32 by anain             #+#    #+#             */
/*   Updated: 2019/11/22 12:10:52 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	free_listoflinks(t_listoflinks *listoflinks)
{
	t_listoflinks		*cur_listoflinks;

	cur_listoflinks = listoflinks;
	while (listoflinks)
	{
		cur_listoflinks = listoflinks;
		listoflinks = listoflinks->next;
		free(cur_listoflinks->s1);
		free(cur_listoflinks->s2);
		free(cur_listoflinks);
	}
}
