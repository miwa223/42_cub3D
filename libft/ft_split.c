/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasubuc <mmasubuc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:03:46 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/12 21:02:13 by mmasubuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

static size_t	get_size_of_array(char const *s, char c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (s[i] != c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			size++;
		i++;
	}
	return (size);
}

static bool	malloc_error(char **ary, size_t ary_nb)
{
	size_t	i;

	i = 0;
	if (ary[ary_nb])
		return (false);
	while (i < ary_nb)
	{
		free(ary[i]);
		i++;
	}
	free(ary);
	return (true);
}

bool	split_lines(char **array, char const *line, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = 0;
	while (line[i] != '\0')
	{
		if (line[i] == c)
		{
			array[j] = ft_substr(line, start, i - start);
			if (malloc_error(array, j))
				return (false);
			j++;
			start = i + 1;
		}
		i++;
	}
	array[j] = ft_substr(line, start, i - start);
	if (malloc_error(array, j))
		return (false);
	array[++j] = NULL;
	return (true);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**array;

	if (s == NULL)
		return (NULL);
	size = get_size_of_array(s, c);
	array = malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (NULL);
	if (!split_lines(array, s, c))
		return (NULL);
	return (array);
}
