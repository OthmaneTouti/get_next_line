/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 07:57:36 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/04 10:16:19 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*Mother function
Initiates a static list and a string*/
char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
	{
		delete_list(&list);
		return (NULL);
	}
	line = NULL;
	create_list(fd, &list);
	if (list == NULL)
		return (NULL);
	extract_line(list, &line);
	clean_list(&list);
	if (line[0] == '\0')
	{
		delete_list(&list);
		list = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

/*Reads from file*/
void	create_list(int fd, t_list **list)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	while (!found_newline(*list) && bytes_read != 0)
	{
		buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		bytes_read = (int)read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			delete_list(list);
			free(buffer);
			return ;
		}
		if ((*list == NULL && bytes_read == 0))
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		create_node(list, buffer, bytes_read);
		free(buffer);
	}
}

/*Adds node to end of list*/
void	create_node(t_list **list, char *buffer, int bytes_read)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->str_buffer = (char *) malloc(sizeof(char) * (bytes_read + 1));
	if (new_node->str_buffer == NULL)
		return ;
	i = 0;
	while (buffer[i] && i < bytes_read)
	{
		new_node->str_buffer[i] = buffer[i];
		i++;
	}
	new_node->str_buffer[i] = '\0';
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	last = get_last_node(*list);
	last->next = new_node;
}

/*Gets the line from the list, until newline or end of file*/
void	extract_line(t_list *list, char **line)
{
	int	i;
	int	j;

	if (list == NULL)
		return ;
	create_line(line, list);
	if (*line == NULL)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->str_buffer[i])
		{
			if (list->str_buffer[i] == '\n')
			{
				(*line)[j++] = list->str_buffer[i];
				break ;
			}
			(*line)[j++] = list->str_buffer[i++];
		}
		list = list->next;
	}
	(*line)[j] = '\0';
}

/*Cleans list before newline for next call of gnl*/
void	clean_list(t_list **list)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = (t_list *) malloc(sizeof(t_list));
	if (list == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = get_last_node(*list);
	i = 0;
	while (last->str_buffer[i] && last->str_buffer[i] != '\n')
		i++;
	if (last->str_buffer && last->str_buffer[i] == '\n')
		i++;
	clean_node->str_buffer = (char *) malloc(sizeof(char)
			* ((ft_strlen(last->str_buffer) - i) + 1));
	if (clean_node->str_buffer == NULL)
		return ;
	j = 0;
	while (last->str_buffer[i])
		clean_node->str_buffer[j++] = last->str_buffer[i++];
	clean_node->str_buffer[j] = '\0';
	delete_list(list);
	*list = clean_node;
}
