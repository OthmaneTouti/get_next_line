/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:22:04 by ottouti           #+#    #+#             */
/*   Updated: 2023/10/30 19:04:56 by ottouti          ###   ########.fr       */
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
t_list	*create_node(char *buffer, t_list *list);
t_list	*find_last_node(t_list *list);
int		found_newline(t_list *list);
void	copy_string(char *buffer, t_list *node);

#endif