/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:26:54 by mohifdi           #+#    #+#             */
/*   Updated: 2025/11/14 21:57:20 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	is_separator(char c, char sep)
{
	return (c == sep);
}

int	count_words(const char *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!is_separator(str[i], sep))
		{
			words++;
			while (str[i] && !is_separator(str[i], sep))
				i++;
		}
		else
			i++;
	}
	return (words);
}

char	*word_splitter(char *str, char sep)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !is_separator(str[i], sep))
		i++;
	word = (char *) malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && !is_separator(str[i], sep))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**words;

	i = 0;
	j = 0;
	words = (char **) malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!words)
		return (NULL);
	while (s[i])
	{
		if (!is_separator(s[i], c))
		{
			words[j++] = word_splitter((char *)&s[i], c);
			while (s[i] && !is_separator(s[i], c))
				i++;
		}
		else
			i++;
	}
	words[j] = 0;
	return (words);
}
