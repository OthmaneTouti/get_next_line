/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:22:03 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/02 17:39:22 by ottouti          ###   ########.fr       */
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
    int		bytes_read;
    t_list	*new_node;

    while (!found_newline(*list))
    {
        if ((bytes_read = read(fd, buffer, BUFFER_SIZE)) <= 0)
			break;
        buffer[bytes_read] = '\0';
        new_node = (t_list *)malloc(sizeof(t_list));
        if (!new_node)
			break;
        buffer_to_node(buffer, new_node, bytes_read);
        new_node->next = NULL;
        if (!*list)
			*list = new_node;
        else
            find_last_node(*list) -> next = new_node;
    }
    if (bytes_read <= 0 && (*list == NULL || (*list)->str_buffer[0] == '\0'))
        delete_list(list);
}


char *get_next_line(int fd)
{
    static t_list   *list;
    char            *buffer;
    char            *line;

    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, buffer, 0) < 0))
	{
		free(buffer);
		delete_list(&list);
		return (NULL);
	}
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
