/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 21:02:02 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/01/10 01:28:02 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_word(char const *s, char c)
{
	int			cnt;

	cnt = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s != c && *s != 0)
				s++;
			cnt += 1;
		}
		while (*s == c && *s != '\0')
			s++;
	}
	return (cnt);
}

void	ft_tocpy(char *dest, char *start, char *end)
{
	while (start < end)
	{
		*dest = *start;
		dest++;
		start++;
	}
	*dest = 0;
}

char	**ft_freearray(char **array)
{
	unsigned int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	char		**array;
	char		*start;
	int			word_count;

	word_count = count_word(s, c);
	if (!(array = (char **)malloc((word_count + 1) * sizeof(char *))))
		return (0);
	i = 0;
	while (*s && word_count != 0)
	{
		while (*s == c && *s != '\0')
			s++;
		start = (char *)s;
		while (*s != c && *s != '\0')
			s++;
		if (!(array[i] = (char *)malloc(s - start + 1)))
			return (ft_freearray(array));
		ft_tocpy(array[i++], start, (char *)s);
		while (*s == c && *s != '\0')
			s++;
	}
	array[i] = 0;
	return (array);
}
