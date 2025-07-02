/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 22:38:16 by jgueon            #+#    #+#             */
/*   Updated: 2025/06/03 18:03:06 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Calculates the length of a string.
 *
 * Returns the number of characters in the string 's', excluding the null
 * terminator.
 *
 * @param s The input string.
 * @return The length of the string.
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s && s[len])
		len++;
	return (len);
}

/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * Returns a pointer to the first occurrence of character 'c' in the string 's',
 * or NULL if the character is not found.
 *
 * @param s The input string.
 * @param c The character to search for.
 * @return A pointer to the first occurrence, or NULL.
 */
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

/**
 * @brief Concatenates two strings into a new string.
 *
 * Allocates and returns a new string, which is the result of the concatenation
 * of 's1' and 's2'. Does not free the input strings.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return The new concatenated string, or NULL on allocation failure.
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}

/**
 * @brief Extracts a substring from a string.
 *
 * Allocates and returns a substring from string 's', starting at index 'start'
 * and of maximum length 'len'. Returns NULL if allocation fails.
 *
 * @param s The input string.
 * @param start The starting index.
 * @param len The maximum length of the substring.
 * @return The substring, or NULL.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (NULL);
	if (len > str_len - start)
		len = str_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/**
 * @brief Duplicates a string.
 *
 * Allocates and returns a new string which is a duplicate of the input
 * string 's'.
 *
 * @param s The string to duplicate.
 * @return The duplicated string, or NULL on allocation failure.
 */
char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
