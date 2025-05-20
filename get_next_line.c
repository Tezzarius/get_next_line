/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwarz <bschwarz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 09:27:27 by bschwarz          #+#    #+#             */
/*   Updated: 2025/05/20 11:12:39 by bschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			file_size;

	line = malloc(BUFFER_SIZE + 1);
	if (fd == - 1 || !line)
		return (NULL);
	file_size = read(fd, buff, BUFFER_SIZE);
	if (file_size < 0)
		return (free(line), NULL);
	buff[file_size] = '\0';
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	buff[i++] = '\n';
	buff[i] = '\0';
	return (line);
}
