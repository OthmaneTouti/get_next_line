/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:22:04 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/04 10:18:57 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str_buffer;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void	create_list(int fd, t_list **list);
void	create_node(t_list **list, char *buffer, int bytes_read);
void	extract_line(t_list *list, char **line);
void	clean_list(t_list **list);
void	create_line(char **line, t_list *list);
void	delete_list(t_list **list);
t_list	*get_last_node(t_list *list);
int		ft_strlen(const char *str);
int		found_newline(t_list *list);
#endif