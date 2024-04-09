/* ************************************************************************** */
/*                                                                            */
/*                                                       :::       ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:58:48 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/09 22:43:42 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/* create a node on list to add content read */
//test
void	create_node(t_list **list, char *buff)
{
	t_list	*new_node;

	new_node = NULL;
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->str_read = buff;
	new_node->next = NULL;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	while ((*list)->next)
		*list = (*list)->next;
	(*list)->next = new_node;
}

/* search New Line in all STORAGE and save it to return it */
static void	new_line(t_list **list, char **line)
{
	t_list	*temp;
	size_t	i;
	size_t	len;

	temp = *list;
	len = 0;
	while (temp)
	{
		i = 0;
		while (temp->str_read[i])
		{
			len++;
			if (temp->str_read[i++] == '\n')
				break ;
		}
		temp = temp->next;
	}
	*line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return ;
	copy_line(list, *line, len);
	(*line)[len] = '\0';
}

/* read and save the string read in a new node in the list */
static void	save_str(int fd, t_list	**list, char **buff)
{
	ssize_t		bytes_read;
	char		*temp;

	temp = NULL;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return ;
	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(temp);
		while (*list)
			clean_node(list);
		return ;
	}
	if (bytes_read <= 0)
	{
		free (temp);
		*buff = NULL;
		return ;
	}
	temp[bytes_read] = '\0';
	*buff = temp;
	create_node(list, temp);
}

/* return a new line from file descriptor given */
char	*get_next_line(int fd)
{
	static t_list	*str_storage;
	t_list			*head;
	char			*buff;
	char			*line;

	if (fd < 0 || fd > 2048 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	head = NULL;
	while (find_new_line(str_storage) < 1)
	{
		if (str_storage && !str_storage->next)
			head = str_storage;
		save_str(fd, &str_storage, &buff);
		if (!str_storage)
			return (NULL);
		if (!buff)
			break ;
	}
	if (head)
		str_storage = head;
	new_line(&str_storage, &line);
	if (!line)
		return (NULL);
	return (line);
}
