/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:28:32 by smackere          #+#    #+#             */
/*   Updated: 2022/01/26 18:05:44 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"solong.h"

size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	w_c;

	i = 0;
	w_c = 0;
	if (s && c)
	{
		while (s[i])
		{
			while (s[i] == c)
				i++;
			if (s[i])
				w_c++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (w_c);
}

char	*ft_stridup(const char *s, size_t n)

{
	char			*dup;
	unsigned int	i;

	dup = malloc(sizeof(char) * n + 1);
	if (!dup)
		return (dup);
	i = 0;
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_map_split(char const *s, char c)
{
	char			**arr;
	unsigned int	end_index;
	unsigned int	start_index;
	unsigned int	k;

	arr = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!arr)
		return (arr);
	end_index = 0;
	k = 0;
	if (s)
	{
		while (s[end_index])
		{
			while (s[end_index] == c)
				end_index++;
			start_index = end_index;
			while (s[end_index] != c && s[end_index])
				end_index++;
			if (end_index > start_index)
				arr[k++] = ft_stridup(s + start_index, end_index - start_index);
		}
	}
	arr[k] = NULL;
	return (arr);
}
