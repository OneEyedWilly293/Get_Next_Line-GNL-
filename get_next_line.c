/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 22:29:39 by jgueon            #+#    #+#             */
/*   Updated: 2025/06/10 19:37:02 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Reads the next line from a file descriptor.
 *
 *	This function returns a line read from the file descriptor 'fd'.
 * 	The line includes the newline character if one was found,
 * 	or the end of file.
 * 	Returns NULL if there is nothing left to read or an error occurs.
 *
 * @param fd The file descriptor to read from.
 * @return A pointer to the line read (heap-allocated, must be freed), or NULL.
 */
char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	storage[fd] = read_buffer(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = extract_line(&storage[fd]);
	if (!line)
	{
		free (storage[fd]);
		storage[fd] = NULL;
	}
	return (line);
}

/**
 * @brief Reads data from the file descriptor into a buffer until a newline
 * 			or EOF.
 *
 * This function appends data read from 'fd' to 'storage' until a newline is
 * found or end of file is reached. It returns the updated storage string.
 *
 * @param fd The file descriptor to read from.
 * @param storage The current buffer containing leftover data.
 * @return The updated storage string with new data appended, or NULL on error.
 */
char	*read_buffer(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && (!ft_strchr(storage, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			break ;
		buffer[bytes_read] = '\0';
		temp = storage;
		storage = ft_strjoin(storage, buffer);
		free(temp);
		if (!storage)
			break ;
	}
	free(buffer);
	return (storage);
}

/**
 * @brief Extracts a single line from the storage buffer.
 *
 * This function finds the next line (up to and including the newline character)
 * in the storage buffer, allocates a new string for it, and updates the storage
 * pointer to point to the remainder.
 *
 * @param storage A pointer to the storage buffer pointer.
 * @return The extracted line (heap-allocated, must be freed), or NULL.
 */
char	*extract_line(char **storage)
{
	char	*line;
	char	*newline;
	size_t	line_len;
	char	*remainder;

	if (!*storage || !**storage)
		return (NULL);
	newline = ft_strchr(*storage, '\n');
	if (newline)
	{
		line_len = newline - *storage + 1;
		line = ft_substr(*storage, 0, line_len);
		remainder = ft_strdup(*storage + line_len);
		free(*storage);
		*storage = remainder;
	}
	else
	{
		line = ft_substr(*storage, 0, ft_strlen(*storage));
		free(*storage);
		*storage = NULL;
	}
	return (line);
}
