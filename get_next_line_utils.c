/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:41:14 by ottouti           #+#    #+#             */
/*   Updated: 2023/10/30 19:12:41 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(t_list *list)
{
	int	i;
	
	if (!list)
		return (0);
	while(list)
	{
		i = 0;
		while(list -> str_buffer[i])
		{
			if (list -> str_buffer[i] == '\n')
				return (1);
			i++;
		}
		list = list -> next;
	}
	return (0);
}

t_list	*find_last_node(t_list *list)
{
	t_list	*current;

	if (!list)
		return (NULL);
	current = list;
	while (list -> next != NULL)
		current = list -> next;
	return (current);
}

void	copy_string(char *buffer, t_list *node)
{
	int	i;

	i = 0;
	if (!node)
		return ;
	node -> str_buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!node -> str_buffer)
	{
		free(node);
		return ;
	}
	while (buffer[i])
	{
		node -> str_buffer[i] = buffer[i];
		i++;
	}
	node -> str_buffer[i] = '\0';
}