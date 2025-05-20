/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwarz <bschwarz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:54:22 by bschwarz          #+#    #+#             */
/*   Updated: 2025/05/20 11:12:41 by bschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int		fd;
	char	*line;

	fd = open("a_fallen_leaf.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	close(fd);
	return (0);
}