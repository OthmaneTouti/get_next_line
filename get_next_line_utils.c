/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:41:14 by ottouti           #+#    #+#             */
/*   Updated: 2023/10/30 20:39:58 by ottouti          ###   ########.fr       */
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

char	*append(t_list *list)
{
	int 	i;
	int		j;
	int 	len;
	char	*line;
	
	if (!list)
		return (NULL);
	len = bytes_to_newline(list);
	printf("len = %d\n", len);
	line = (char *) malloc(len + 1 * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (list)
	{
		j = 0;
		while (list -> str_buffer[j] && i != len)
			line[i++] = list -> str_buffer[j++];
		list = list -> next;
	}
	line[i] = '\0';
	return (line);
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