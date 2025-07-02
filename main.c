/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:27:28 by jgueon            #+#    #+#             */
/*   Updated: 2025/06/11 23:02:12 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>		// For open
#include <stdio.h>		// For printf(), perror()
#include <stdlib.h>		// For free(), exit()
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int	fd;
	char *line;

	// Check if the filename is provided as an argument
	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	// Open the file for reading
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}

	// Read and print each line until get_next_line returns NULL
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);		// get_next_line includes the newline
		free(line);				// Always free the returned line
	}

	// Close the file
	close(fd);
	return (0);
}