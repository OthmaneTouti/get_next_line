/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:22:03 by ottouti           #+#    #+#             */
/*   Updated: 2023/10/30 20:23:19 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	delete_list(t_list **list)
{
	t_list	*temp;
	
	if (!list || !*list)
		return ;
	temp = *list;
	while (temp)
	{
		temp = (*list) -> next;
		free((*list) -> str_buffer);
		free(*list);
		*list = temp;
	}
	*list = NULL;
}

t_list	*create_node(char *buffer, t_list **list)
{
	t_list	*new_node;
	t_list	*last_node;
	
	new_node = (t_list *) malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	copy_string(buffer, new_node);
	if (!new_node -> str_buffer)
	{
		free(new_node);
		return (NULL);
	}
	new_node -> next = NULL;
	if (!*list)
	{
		*list = new_node;
		return (*list);
	}
	last_node = find_last_node(*list);
	if (!last_node)
	{
		free(new_node -> str_buffer);
		free(new_node);
		return (NULL);
	}
	last_node -> next = new_node;
	return (*list);
}

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
		if (bytes_read < 0)
		{
			free(list);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		list = create_node(buffer, &list);
	}
	line = append(list);
	delete_list(&list);
	printf("%s\n", line);
	return (0);
}