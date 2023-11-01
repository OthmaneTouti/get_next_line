/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:41:14 by ottouti           #+#    #+#             */
/*   Updated: 2023/10/31 21:57:40 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	found_newline(t_list *list)
{
	int	i;
	t_list	*last_node;
	
	if (!list)
		return (0);
	last_node = find_last_node(list);
	i = 0;
	while(last_node -> str_buffer[i])
	{
		if (last_node -> str_buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*find_last_node(t_list *list)
{
	t_list	*current;

	if (!list)
		return (NULL);
	current = list;
	while (current -> next != NULL)
		current = current -> next;
	return (current);
}

void	buffer_to_node(char *buffer, t_list *node, int str_len)
{
	int	i;

	i = 0;
	node -> str_buffer = (char *) malloc(str_len + 1);
	if (!node || !node -> str_buffer)
		return ;
	while (buffer[i])
	{
		node -> str_buffer[i] = buffer[i];
		i++;
	}
	node -> str_buffer[i] = '\0';
}

int	bytes_to_newline(t_list *list)
{
	int len;
	int	i;

	len = 0;
	if (!list)
		return (len);
	while (list)
	{
		i = 0;
		while (list -> str_buffer[i] != '\n'
			&& list -> str_buffer[i] != '\0')
		{
			i++;
			len++;
		}
		list = list -> next;
	}
	return (len);
}

void	copy_leftover(t_list *list, char *node_str)
{
	int		i;
	int		j;
	t_list	*last_node;

	last_node = find_last_node(list);
	if (!last_node || !last_node->str_buffer)
		return ;
	j = 0;
	while (last_node->str_buffer[j] && last_node->str_buffer[j] != '\n')
		j++;
	if (last_node->str_buffer[j] == '\n')
	{
		j++;
		i = 0;
		while (last_node->str_buffer[j])
			node_str[i++] = last_node->str_buffer[j++];
		node_str[i] = '\0';
	}
	else
		node_str[0] = '\0';
}
