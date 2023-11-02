/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:22:03 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/02 13:00:46 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void clean_list(t_list **list)
{
    t_list  *clean_node;

    if (!list || !(*list))
        return ;
    clean_node = (t_list *) malloc(sizeof(t_list));
    if (!clean_node)
        return ;
    clean_node->str_buffer = (char *) malloc(BUFFER_SIZE + 1);
    if (!clean_node->str_buffer)
    {
        free(clean_node);
		clean_node = NULL;
        delete_list(list);
        return;
    }
    clean_node->next = NULL;
    copy_leftover(*list, clean_node->str_buffer);
    delete_list(list);
    *list = clean_node;
}


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

char *find_line(t_list *list)
{
	char	*line;
	int		len;
	int		i;
	int		j;

	len = bytes_to_newline(list);
	line = (char *) malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (list)
	{
		j = 0;
		while (list -> str_buffer[j] && i < len)
			line[i++] = list -> str_buffer[j++];
		list = list -> next;
	}
	line[i] = '\0';
	return (line);
}

void create_list(t_list **list, int fd, char *buffer)
{
    int     bytes_read;
    t_list  *new_node;
    t_list  *last_node;

    while (!found_newline(*list))
    {
        new_node = (t_list *)malloc(sizeof(t_list));
        if (!new_node)
        {
            delete_list(list);
            return;
        }
        new_node->str_buffer = NULL;
        new_node->next = NULL;
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free(new_node);
			new_node = NULL;
            delete_list(list);
            return;
        }
        else if (bytes_read == 0)
        {
			if (*list && !(*list) -> str_buffer[0])
				delete_list(list);
            free(new_node);
			new_node = NULL;
            return ;
        }
        buffer[bytes_read] = '\0';
        last_node = find_last_node(*list);
        if (!last_node)
            *list = new_node;
        else
            last_node->next = new_node;
        buffer_to_node(buffer, new_node, bytes_read);
        new_node -> next = NULL;
    }
}

char *get_next_line(int fd)
{
    static t_list   *list;
    char            *buffer;
    char            *line;

    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    create_list(&list, fd, buffer);
    if (!list)
    {
        free(buffer);
        return (NULL);
    }
    line = find_line(list);
    free(buffer);
    clean_list(&list);
    return (line);
}
