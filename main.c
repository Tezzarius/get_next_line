/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwarz <bschwarz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:54:22 by bschwarz          #+#    #+#             */
/*   Updated: 2025/05/28 14:42:28 by bschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#define RED		"\x1b[31m"
#define BLUE	"\x1b[36m"
#define RESET	"\x1b[0m"

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	
	if (argc != 2)
	{
		printf(RED "Error: no file name\n" RESET);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf(RED "Can't open this document\n" RESET);
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf(BLUE "%s" RESET, line);
		free(line);
	}
	close(fd);
	return (0);
}
