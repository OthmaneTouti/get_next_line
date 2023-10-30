/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:22:03 by ottouti           #+#    #+#             */
/*   Updated: 2023/10/30 19:16:21 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_list	*create_node(char *buffer, t_list *list)
{
	t_list	*new_node;
	t_list	*last_node;
	
	new_node = (t_list *) malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	copy_string(buffer, new_node);
	if (!new_node -> str_buffer)
		return (NULL);
	new_node -> next = NULL;
	if (!list)
		return (new_node);
	last_node = find_last_node(list);
	if (!last_node)
	{
		free(new_node -> str_buffer);
		free(new_node);
		return (NULL);
	}
	last_node -> next = new_node;
	return (new_node);
}

char	*get_line(t_list list, char *buffer)


char *get_next_line(int fd)
{
	static t_list	*list;
	int				bytes_read;
	char			*buffer;
	char			*line;
	
	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		return (NULL);
	}
	while(!found_newline(list))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(list);
			free(buffer);
			return (NULL);
		}
		buffer[BUFFER_SIZE] = '\0';
		list = create_node(buffer, list);
		printf("%s\n", list -> str_buffer);
	}
	return (0);
}