/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:26:39 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/08 14:44:30 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*str_read;
	struct s_list	*next;
}			t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		find_new_line(t_list *list);
char	*get_next_line(int fd);
void	create_node(t_list **list, char *buff);
void	copy_line(t_list **list, char *line, size_t len);
void	clean_node(t_list **list);

#endif
