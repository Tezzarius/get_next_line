/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwarz <bschwarz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:54:22 by bschwarz          #+#    #+#             */
/*   Updated: 2025/05/27 17:48:09 by bschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i = 1;
	
	if (argc == 2)
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
				return -1;
			while ((line = get_next_line(fd)))
			{
				printf("%s", line);
				free(line);
			}
			close(fd);
			line = get_next_line(fd);
			free(line);
			i++;
		}
	else
	{
		fd = 0;
		while ((line = get_next_line(fd)))
		{
			printf("%s", line);
			free(line);
		}
		close(fd);
		line = get_next_line(fd);
		free(line);
	}
	return (0);
}
