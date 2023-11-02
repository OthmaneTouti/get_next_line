/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:22:04 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/01 14:57:55 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_list
{
	char			*str_buffer;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
char	*find_line(t_list *list);
void	create_list(t_list **list, int fd, char *buffer);
t_list	*find_last_node(t_list *list);
int		found_newline(t_list *list);
int		bytes_to_newline(t_list *list);
void	buffer_to_node(char *buffer, t_list *node, int str_len);
void	delete_list(t_list **list);
void	copy_leftover(t_list *list, char *node_str);
void	clean_list(t_list **list);

#endif