/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcielesz <jcielesz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:18:07 by jcielesz          #+#    #+#             */
/*   Updated: 2024/02/03 21:01:44 by jcielesz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_sep(char c, char *charset)
{
	int	i;

	if (c == '\0')
		return (1);
	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
        i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (check_sep(str[i + 1], charset) && !check_sep(str[i], charset))
			words++;
		i++;
	}
	return (words);
}

void	copy_word(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (!check_sep(src[i], charset))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

#include <stdio.h>

int	main(void)
{
	printf("%i", count_words(",;,a, a", ";,"));
}

// char	**ft_split(char *str, char *charset)
// {
// }
